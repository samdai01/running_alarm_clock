/**
 * @file main.ino
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Main Arduino file responsible for managing navigation and alarm clock
 * @version 0.1
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Define constants */

#define DEBUG 1

/* Include files */
#include <avr/wdt.h>
#include <ultrasonic.h>
#include <motor.h>
#include <MPU6050.h>
#include <compass.h>
#include <direction.h>

/* Onboard Module Objects */
UltrasonicSensor ultrasonic;
Motor alarm_clock_motor;
MPU6050 gyroscope;
Compass OnboardGyro;

void setup() {
    Serial.begin(9600);
    ultrasonic.ultrasonicSensorInit();
    alarm_clock_motor.motorInit();      // initializing motor pins
    OnboardGyro.CompassInit(&gyroscope);
    OnboardGyro.CompassCalibrate(&gyroscope);
}

void loop() {
    uint16_t distance;
    static float yaw;
    float turn_around_yaw;
    ultrasonic.ultrasonicGetDistance(&distance);

    if (distance < 30) {
      alarm_clock_motor.stop();
      OnboardGyro.CompassGetAngle(&yaw, &gyroscope);

      Serial.print("Current Yaw: ");
      Serial.println(yaw);

      turn_around_yaw = getTurnAroundAngle(yaw);

      Serial.print("Turn around Yaw is: ");
      Serial.println(turn_around_yaw);

    }
}
