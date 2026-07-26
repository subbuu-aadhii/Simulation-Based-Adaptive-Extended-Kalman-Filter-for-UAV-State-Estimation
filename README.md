# Adaptive Extended Kalman Filter for UAV State Estimation under Sensor Degradation
The project develops a data-driven environmental noise model using real-world weather statistics and demonstrates how adaptive covariance estimation improves state estimation accuracy compared to conventional filtering techniques.

---

# Project Overview

Modern UAVs rely heavily on onboard sensors such as IMUs and barometric pressure sensors for navigation and control. Unfortunately, these sensors are affected by

- Gaussian sensor noise
- Wind-induced oscillations
- Sudden disturbances (gusts)
- Thermal drift
- Time-varying environmental conditions

Traditional Kalman Filters assume constant measurement noise and therefore degrade in performance when operating under dynamic environments.

This project implements an **Adaptive Extended Kalman Filter (AEKF)** that continuously updates its measurement covariance matrix using innovation statistics, enabling robust estimation under non-stationary noise.

---

# Project Workflow

```text
Real Weather Dataset
          │
          ▼
 Statistical Analysis (Google Colab)
          │
          ▼
 Composite Noise Model
          │
          ▼
 Sensor Measurements
          │
          ▼
 Adaptive Extended Kalman Filter
          │
          ▼
 Estimated States
          │
          ▼
 Controller
          │
          ▼
 PWM Output
```

---

# Features

✔ Data-driven environmental noise modelling

✔ Adaptive Extended Kalman Filter implementation

✔ Innovation-based covariance adaptation

✔ MATLAB/Simulink simulation

✔ UAV-oriented state estimation framework

✔ Parameter tuning through simulation

✔ Modular architecture suitable for future embedded implementation

---

# Repository Structure

```
AEKF-UAV-State-Estimation/
│
├── Simulink_Model/
│   ├── AEKF_Model.slx
│   ├── Noise_Model.slx
│   └── Supporting_Files/
│
├── MATLAB/
│   ├── aekf.m
│   ├── adaptive_update.m
│   ├── noise_model.m
│   ├── plots.m
│   └── utilities/
│
├── Dataset/
│   ├── Weather_Data.csv
│   └── Processed_Data.csv
│
├── Google_Colab/
│   └── Noise_Modelling.ipynb
│
├── Images/
│
├── Paper/
│   └── IEEE_Paper.pdf
│
└── README.md
```

---
