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

# Project Workflow - Architecture

<img width="502" height="188" alt="image" src="https://github.com/user-attachments/assets/0fec11b9-6e2a-40bd-8e4f-dd4724f7d24b" />

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
├── Dataset/
│   ├── Weather_Data.csv
│   └── Sensor_data.csv
├── Google_Colab/
│   └── Noise_Modelling.ipynb
├── Paper/
│   └── IEEE_Paper.pdf
└── README.md
```

---

# Drone Design - SolidWorks Drawing

<p align="center">

<img width="502" height="467" alt="image" src="https://github.com/user-attachments/assets/c74482aa-57a2-4100-97bf-8019a2834c52" />

</p>

# Composite Noise Model

The simulated sensor noise is composed of four different components.

- Gaussian Noise
- Oscillatory Turbulence
- Random Gust Spikes
- Thermal Drift

The overall measurement becomes

Vk = V_gauss + V_osc + V_spike + bk

where

- Gaussian component models wind uncertainty
- Oscillatory component models turbulence
- Spike component models sudden gusts
- Drift models temperature-induced sensor bias

---

## Noise Model

<p align="center">

<img width="502" height="329" alt="image" src="https://github.com/user-attachments/assets/b9412216-3404-45e4-b938-0afb3396be3b" />

</p>

---

# Adaptive Extended Kalman Filter

Unlike a conventional EKF, the proposed filter updates the measurement covariance online.

The filter performs

1. Prediction

2. Innovation

3. Kalman Gain Computation

4. State Update

5. Covariance Update

6. Adaptive Measurement Covariance Update

The adaptive covariance equation is

R_k = alpha*R_k-1 + (1-alpha)y_k^2

where

- (R_k) is the measurement covariance
- (y_k) is the innovation
- (alpha) is the forgetting factor

---

# Simulink Model

The complete system was modeled and validated in MATLAB Simulink.

The simulation contains

- Sensor model
- Noise generation
- Adaptive EKF
- Controller
- Scope blocks

---

### Simulink Block Diagram

<p align="center">

<img width="560" height="209" alt="image" src="https://github.com/user-attachments/assets/f4d8a2c7-ac18-4da1-8bf6-c6bfcd019fba" />

</p>

---

# Results

The AEKF demonstrates

- Significant reduction in sensor noise
- Better signal smoothness
- Stable state estimation
- Improved controller response
- Adaptation to varying environmental conditions

---

## Sensor Data Filtering - flowchart

<p align="center">

<img width="502" height="831" alt="image" src="https://github.com/user-attachments/assets/18f2f4b6-74cf-4c9d-b957-a8ea507ba558" />

</p>

---

## Simulink & Hardware Validation

<p align="center">
          
<img width="502" height="394" alt="image" src="https://github.com/user-attachments/assets/35f5ba84-130d-44b5-a308-a3fcf2d87dd8" />

</p>

<p align="center">

<img width="502" height="377" alt="image" src="https://github.com/user-attachments/assets/a55cd8dc-550e-4368-bf87-a553177bc703" />

</p>

<p align="center">
          
<img width="417" height="222" alt="image" src="https://github.com/user-attachments/assets/dc13cab4-cc15-45c6-9629-114155f138ad" />

<img width="426" height="214" alt="image" src="https://github.com/user-attachments/assets/48b69bb0-435c-47d1-b934-ad53c7188429" />

</p>

---

# Software Used

| Software | Purpose |
|-----------|---------|
| MATLAB | Numerical Computing |
| Simulink | System Simulation |
| Google Colab | Dataset Analysis |
| SolidWorks | UAV Design |
| Kaggle Dataset | Weather Statistics |

---

# Future Work

- Embedded implementation on STM32
- PX4 / ArduPilot integration
- Multi-sensor fusion
- GPS integration
- Magnetometer integration
- Quaternion-based EKF
- Flight controller validation
- Hardware-in-the-loop (HIL) simulation

---

# Citation

If you use this work, please cite

```bibtex
@article{AEKF_UAV,
  title={Adaptive Extended Kalman Filter for Robust UAV State Estimation under Sensor Degradation},
  author={N. Subramanian},
  year={2026}
}
```

---

# Author

**N. Subramanian**

Electrical and Electronics Engineering

VIT Chennai

---

# License

This project is released under the MIT License.
