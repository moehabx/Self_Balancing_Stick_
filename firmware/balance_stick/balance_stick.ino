#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <WiFi.h>
#include <WebServer.h>

#include "config.h"
#include "web_server.h"

Adafruit_MPU6050 mpu;
WebServer server(80);

// PID Control Variables
float Kp = DEFAULT_KP;
float Ki = DEFAULT_KI;
float Kd = DEFAULT_KD;
float keepAngle = DEFAULT_TARGET;

float currentAngle = 0.0f;
float bias = 0.0f;
float bias_Integrate = 0.0f;
float bias_Differential = 0.0f;
float lastBias = 0.0f;

unsigned long lastTime = 0;

void setup() {
  Serial.begin(115200);

  // Motor Outputs
  pinMode(MOTOR_PWM1_PIN, OUTPUT);
  pinMode(MOTOR_PWM2_PIN, OUTPUT);

  // Initialize I2C Communication
  Wire.begin(SDA_PIN, SCL_PIN);
  if (!mpu.begin()) {
    Serial.println("Error: MPU6050 sensor not found!");
    while (1) { delay(10); }
  }

  // Sensor Ranges
  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  // Wi-Fi AP Setup
  WiFi.softAP(AP_SSID, AP_PASS);
  Serial.print("Access Point IP: ");
  Serial.println(WiFi.softAPIP());

  // Web Server Setup
  setupWebServer();

  lastTime = millis();
}

void loop() {
  server.handleClient();

  // Time Difference Calculation
  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0f;
  if (dt < 0.01f) return; // Maintain ~100Hz control loop speed
  lastTime = now;

  // IMU Data Capture
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Tilt Angle Calculation via Accelerometer
  currentAngle = atan2(a.acceleration.y, a.acceleration.z) * 180.0f / M_PI;

  // PID Computations
  bias = currentAngle - keepAngle;
  bias_Integrate += bias * dt;
  bias_Integrate = constrain(bias_Integrate, -100.0f, 100.0f); // Anti-windup
  bias_Differential = (bias - lastBias) / dt;
  lastBias = bias;

  float motor_PWM = (Kp * bias) + (Ki * bias_Integrate) + (Kd * bias_Differential);

  // Output Drive Signal to Motor
  int pwmValue = constrain((int)abs(motor_PWM), 0, 255);

  if (motor_PWM > 0) {
    analogWrite(MOTOR_PWM1_PIN, pwmValue);
    analogWrite(MOTOR_PWM2_PIN, 0);
  } else {
    analogWrite(MOTOR_PWM1_PIN, 0);
    analogWrite(MOTOR_PWM2_PIN, pwmValue);
  }
}