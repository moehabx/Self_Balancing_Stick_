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
+------------------------------------+
   |          ESP32-C3 CORE             |
   |                                    |
   |  GPIO 8 (SDA)  <---->  SDA (MPU6050)|
   |  GPIO 9 (SCL)  <---->  SCL (MPU6050)|
   |  GPIO 4 (PWM1) ---->   IN1 (DRV8833)|
   |  GPIO 5 (PWM2) ---->   IN2 (DRV8833)|
   |  3.3V / GND    <---->  VCC / GND   |
   +------------------------------------+
                     |
  +------------------+------------------+
  |                                     |
+---------------+                     +-----------+
| MPU6050 (IMU) |                     | DRV8833   |
+---------------+                     +-----------+
|
OUT1 / OUT2
|
+-----------+
| DC Motor  |
+-----------+


---

