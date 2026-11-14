# AI-Based Drone Object Detection and Embedded Sensor Monitoring

## Project Overview

This project focuses on two important areas of robotics and embedded systems: AI-based object detection using drone-view images and embedded sensor monitoring using an ESP32 and MPU6050 sensor.

The first task uses the YOLO26n object detection model trained on the VisDrone2019-DET dataset to identify objects such as pedestrians, cars, bicycles, trucks, and other vehicles in aerial images.

The second task uses an ESP32 microcontroller and an MPU6050 accelerometer and gyroscope to monitor tilt and motion. The system displays sensor readings and generates warnings when the measured tilt or motion exceeds the selected thresholds.

Both tasks demonstrate the use of artificial intelligence, computer vision, microcontrollers, and sensor integration.

## 1. Task 1 – AI-Based Drone Object Detection

### 1.1 Objective

The objective of this task is to develop an object detection system that can identify different objects in drone-view images using artificial intelligence and deep learning.

### 1.2 Dataset Used

- **Dataset:** VisDrone2019-DET
- **Source:** [VisDrone Official Dataset](https://github.com/VisDrone/VisDrone-Dataset)
- **Task Type:** Object Detection
- **Number of Classes:** 10

The dataset contains aerial images captured from drones and is used to train and evaluate the object detection model.

### 1.3 Model and Technologies

The project uses the YOLO26n object detection model, fine-tuned on the VisDrone2019-DET dataset.

**Technologies used:**
- Python
- YOLO26n
- Ultralytics
- PyTorch
- Google Colab

### 1.4 Implementation

The project was implemented using the following steps:

1. Obtained and prepared the VisDrone2019-DET dataset.
2. Set up the YOLO26n model using the Ultralytics framework.
3. Fine-tuned the model using the prepared dataset in Google Colab.
4. Evaluated the trained model using validation data.
5. Tested object detection on 10 unseen drone-view images.
6. Saved sample predictions and evaluation results.

### 1.5 Model Evaluation

The selected model was evaluated at an image size of 1536 pixels.

| Evaluation Metric | Result |
|---|---:|
| Precision | 52.89% |
| Recall | 45.76% |
| mAP50 | 45.84% |
| mAP50-95 | 27.06% |

The model produces bounding boxes, class labels, and confidence scores for detected objects.

## 2. Task 2 – Embedded Sensor Monitoring

### 2.1 Objective

The objective of this task is to monitor tilt and motion using an MPU6050 accelerometer and gyroscope connected to an ESP32 microcontroller.

### 2.2 Components Used

- ESP32 Development Board (DOIT ESP32 DEVKIT V1)
- MPU6050 Accelerometer and Gyroscope
- Breadboard
- Jumper Wires
- USB Cable

### 2.3 Hardware Connections

The MPU6050 sensor communicates with the ESP32 using the I2C communication protocol.

| MPU6050 Pin | ESP32 Pin |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### 2.4 Software and Libraries

- Arduino IDE
- ESP32 Board Support
- Adafruit MPU6050 Library
- Adafruit Unified Sensor Library
- Wire Library

### 2.5 Implementation

The system was implemented using the following steps:

1. Connected the MPU6050 sensor to the ESP32 using I2C.
2. Installed the required libraries in Arduino IDE.
3. Read accelerometer and gyroscope data from the sensor.
4. Calculated roll and pitch angles to monitor tilt.
5. Implemented threshold-based tilt and motion warnings.
6. Displayed sensor readings and warning messages in the Serial Monitor.

### 2.6 Threshold Settings

The following experimental thresholds were used:

- Tilt Limit: 30°
- Gyroscope Limit: 1.2 rad/s
- Acceleration Change Limit: 3.0 m/s²

These thresholds are used for demonstration and are not validated safety limits.

### 2.7 Testing and Results

The system was tested in different conditions.

| Test Condition | Expected Output |
|---|---|
| Sensor in normal position | STATUS: NORMAL |
| Sensor tilted beyond the limit | WARNING: EXCESSIVE TILT! |
| Sensor moved | WARNING: MOTION DETECTED! |

The system successfully displayed sensor readings and generated the expected warning messages during testing.

## 3. Results and Evidence

### 3.1 Task 1 – Object Detection Results

The trained YOLO26n model was tested on unseen drone-view images. The detection results include bounding boxes, class labels, and confidence scores.

Sample prediction images and model training graphs are available in:

`task1_ai_ml/results/`

### 3.2 Task 2 – Sensor Monitoring Evidence

The ESP32 and MPU6050 system was physically tested. The following evidence is available in the GitHub repository:

- [Wiring Diagram](task2_embedded/wiring_diagram.png.jpeg)
- [Normal Status Screenshot](task2_embedded/evidence/normal_status.png)
- [Tilt Warning Screenshot](task2_embedded/evidence/tilt_warning.png)
- [Motion Warning Screenshot](task2_embedded/evidence/motion_warning.png)

## 4. Conclusion

This project provided practical experience in artificial intelligence, computer vision, embedded systems, and sensor interfacing.

In Task 1, the YOLO26n model was fine-tuned using the VisDrone2019-DET dataset and tested on unseen drone-view images.

In Task 2, the ESP32 and MPU6050 sensor were used to monitor tilt and motion and generate warning messages based on experimental thresholds.

Both tasks helped develop practical knowledge of software tools, hardware components, model evaluation, programming, and system testing.

## 5. References

1. [VisDrone Official Dataset](https://github.com/VisDrone/VisDrone-Dataset)
2. [Ultralytics Documentation](https://docs.ultralytics.com/)
3. [Adafruit MPU6050 Library](https://github.com/adafruit/Adafruit_MPU6050)
4. [Arduino IDE](https://www.arduino.cc/en/software)
5. [ESP32 Arduino Documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)

