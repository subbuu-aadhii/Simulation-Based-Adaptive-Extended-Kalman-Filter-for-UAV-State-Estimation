#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>


Adafruit_BMP280 bmp;
Adafruit_MPU6050 mpu;


int ENA = 9;
int IN1 = 8;
int IN2 = 7;


float Kp = 50;
float ref = 0;


float bias = 0;
float t = 0;


float dt = 0.05;
// State [z, v]
float x[2] = {0, 0};
// Covariance
float P[2][2] = {{1, 0}, {0, 1}};
// System matrix
float A[2][2] = {{1, dt}, {0, 1}};
// Measurement matrix
float H[2] = {1, 0};
// Process noise
float Q[2][2] = {{0.001, 0}, {0, 0.001}};
// Measurement noise (adaptive)
float R = 5;
// Adaptive factor
float alpha = 0.98;


void setup() {
  Serial.begin(9600);
  Wire.begin();


  bmp.begin(0x76);
  mpu.begin();


  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);


  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}


void loop() {


  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);


  float Az = a.acceleration.z;
  float wind_noise = 5.0 * sin(2 * t);
  float spike = random(-1000, 1000) / 100.0;
  bias += 0.01;


  float z = Az + wind_noise + spike + bias;  // measurement


  // Prediction
  float x_pred[2];
  x_pred[0] = A[0][0]*x[0] + A[0][1]*x[1];
  x_pred[1] = A[1][0]*x[0] + A[1][1]*x[1];


  // P_pred = A P A^T + Q
  float P_pred[2][2];


  P_pred[0][0] = A[0][0]*P[0][0] + A[0][1]*P[1][0];
  P_pred[0][1] = A[0][0]*P[0][1] + A[0][1]*P[1][1];
  P_pred[1][0] = A[1][0]*P[0][0] + A[1][1]*P[1][0];
  P_pred[1][1] = A[1][0]*P[0][1] + A[1][1]*P[1][1];


  // Add Q
  P_pred[0][0] += Q[0][0];
  P_pred[1][1] += Q[1][1];


  // Measurement update 
  // y = z - Hx
  float y = z - (H[0]*x_pred[0] + H[1]*x_pred[1]);
  // S = HPH' + R
  float S = P_pred[0][0] + R;
  // Kalman Gain K = P H' / S
  float K[2];
  K[0] = P_pred[0][0] / S;
  K[1] = P_pred[1][0] / S;


  // State update 
  x[0] = x_pred[0] + K[0]*y;
  x[1] = x_pred[1] + K[1]*y;


  // Covariance update
  P[0][0] = (1 - K[0]) * P_pred[0][0];
  P[0][1] = (1 - K[0]) * P_pred[0][1];
  P[1][0] = P_pred[1][0] - K[1]*P_pred[0][0];
  P[1][1] = P_pred[1][1] - K[1]*P_pred[0][1];


  // Adaptive R update 
  R = alpha * R + (1 - alpha) * (y * y);
  float Az_filtered = x[0];


  float error = ref - Az_filtered;


  int pwm = abs(Kp * error);
  pwm = pwm + 50;
  pwm = constrain(pwm, 0, 255);


  analogWrite(ENA, pwm);
  Serial.print(Az);           // raw
  Serial.print(" ");
  Serial.print(z);            // noisy
  Serial.print(" ");
  Serial.print(Az_filtered);  // AEKF output
  Serial.print(" ");
  Serial.println(pwm);
  t += 0.2;
  delay(50);
}