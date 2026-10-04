#ifndef CONFIG_H
#define CONFIG_H

// Pin Configurations for ESP32-C3
#define SDA_PIN        8
#define SCL_PIN        9
#define MOTOR_PWM1_PIN 4
#define MOTOR_PWM2_PIN 5

// Initial PID Default Coefficients
#define DEFAULT_KP     15.0f
#define DEFAULT_KI     0.05f
#define DEFAULT_KD     15.20f
#define DEFAULT_TARGET 0.0f

// Network AP Credentials
#define AP_SSID        "ESP32_Balance_Stick"
#define AP_PASS        "12345678"

#endif