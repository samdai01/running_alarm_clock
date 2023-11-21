/**
 * @file compass.ino
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Test of the MPU6050 module to interact with the z axis of the car
 * @version 0.1
 * @date 2023-11-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Include Files */
#include <avr/wdt.h>
#include <MPU6050.h>
#include <compass.h>

/* Static Objects */
MPU6050 gyroscope;
Compass OnboardGyro;

/* Functions */

// Arduino setup function
void setup() {
  Serial.begin(9600);
  OnboardGyro.CompassInit(&gyroscope);
  delay(2000);
  OnboardGyro.CompassCalibrate(&gyroscope);
}

// Arduino Loop function
// DOES NOT END
void loop() {
    static float Yaw;
    OnboardGyro.CompassGetAngle(&Yaw, &gyroscope);
    Serial.print("Yaw:");
    Serial.println(Yaw);
}
