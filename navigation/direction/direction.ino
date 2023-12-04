/**
 * @file direction.ino
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Arduino sketch for testing the functions in new_direction.h
 * @date 2023-12-04
 */

/* Include Files */
#include <avr/wdt.h>
#include <compass.h>
#include <MPU6050.h>
#include "new_direction.h"

/* Objects */
MPU6050 Gyroscope;
Compass OnboardGyro;

/* Functions */
void setup() {
    Serial.begin(9600);
    OnboardGyro.CompassInit(&Gyroscope);
    delay(2000);
    OnboardGyro.CompassCalibrate(&Gyroscope);
}

void loop() {
    static float yaw;
    float desired_yaw;

    // Obtain current yaw
    OnboardGyro.CompassGetAngle(&Yaw, &Gyroscope);
    Serial.print("Yaw: ");
    Serial.println(Yaw);

    // Obtain turnaround angle for current yaw
    desired_yaw = getTurnAroundAngle(yaw);
    Serial.print("Desired Yaw: ");
    Serial.println(desired_yaw);

    // Obtain whether or not to turn clockwise (right)
    bool clockwise = turnClockwise(yaw, desired_yaw);

    if (clockwise) {
        Serial.println("The alarm clock will turn clockwise.");
    } else {
        Serial.println("The alarm clock will not turn clockwise.");
    }

    delay(2000);
}