
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>

Adafruit_MPU6050 mpu;

const float TILT_LIMIT = 30.0;
const float GYRO_LIMIT = 1.2;
const float ACCEL_CHANGE_LIMIT = 3.0;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!mpu.begin()) {
    Serial.println("MPU6050 not detected!");
    while (1) {
      delay(10);
    }
  }

  Serial.println("Motion Monitoring Started!");
}

void loop() {
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  float x = accel.acceleration.x;
  float y = accel.acceleration.y;
  float z = accel.acceleration.z;

  // Calculate tilt angles
  float roll = atan2(y, z) * 180.0 / PI;
  float pitch = atan2(-x, sqrt(y * y + z * z)) * 180.0 / PI;

  // Calculate total acceleration and rotation
  float accelMagnitude = sqrt(x*x + y*y + z*z);
  float gyroMagnitude = sqrt(
    gyro.gyro.x * gyro.gyro.x +
    gyro.gyro.y * gyro.gyro.y +
    gyro.gyro.z * gyro.gyro.z
  );

  bool tiltWarning =
    (fabs(roll) > TILT_LIMIT || fabs(pitch) > TILT_LIMIT);

  bool motionWarning =
    (gyroMagnitude > GYRO_LIMIT ||
     fabs(accelMagnitude - 9.81) > ACCEL_CHANGE_LIMIT);

  Serial.print("Roll: ");
  Serial.print(roll);
  Serial.print(" | Pitch: ");
  Serial.println(pitch);

  Serial.print("Gyroscope magnitude: ");
  Serial.println(gyroMagnitude);

  if (tiltWarning) {
    Serial.println("WARNING: EXCESSIVE TILT!");
  }
  else if (motionWarning) {
    Serial.println("WARNING: MOTION DETECTED!");
  }
  else {
    Serial.println("STATUS: NORMAL");
  }

  Serial.println("-------------------------");

  delay(500);
}

