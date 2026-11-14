
# Task 2: Embedded Sensor Monitoring

## Project Overview
This task uses an ESP32 microcontroller and an MPU6050 sensor to monitor tilt and motion.

## Components Used
- ESP32 development board
- MPU6050 accelerometer and gyroscope
- Breadboard
- Jumper wires
- USB cable

## Connections

| MPU6050 | ESP32 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## Working
The MPU6050 measures acceleration and angular velocity. The ESP32 reads these values through I2C and calculates roll and pitch angles.

The program displays sensor readings on the Serial Monitor and generates warnings when excessive tilt or motion is detected.

## Thresholds
- Tilt limit: 30 degrees
- Gyroscope limit: 1.2 rad/s
- Acceleration change limit: 3.0 m/s²

These are initial experimental thresholds for demonstration.

## Files
- `esp32_mpu6050.ino` – ESP32 firmware source code.
- `wiring_diagram.png` – Wiring diagram (to be added).
