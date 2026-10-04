# ESP32 DIY Balance Stick (Propeller-Driven Inverted Pendulum)

An open-source, single-axis self-balancing stick controlled by an ESP32-C3 microcontroller, MPU6050 IMU, and DRV8833 motor driver. Features an onboard Wi-Fi Access Point and Web Server for real-time PID tuning via browser.

Developed as part of the HKUST(GZ) Maker World workshop series.

---

## Technical Specifications

| Parameter | Specification |
| :--- | :--- |
| **Microcontroller** | ESP32-C3 Core Board (Wi-Fi 2.4GHz) |
| **Sensor** | MPU6050 (3-axis Gyroscope + 3-axis Accelerometer) |
| **Motor Driver** | DRV8833 Dual H-Bridge |
| **Actuator** | Coreless DC Motor with Propeller |
| **Power Source** | 1S 18650 Li-ion Battery (3.7V - 4.2V) |
| **Control Method** | Closed-loop PID Loop (100Hz Refresh Rate) |
| **AP SSID** | `ESP32 AP: XXXX_Balance_Stick` |
| **Web UI Address**| `http://192.168.4.1` |

---

## Hardware Wiring Diagram
<img width="601" height="676" alt="image" src="https://github.com/user-attachments/assets/cf6a2d1e-edef-4905-bd54-106fd1c3180b" />

