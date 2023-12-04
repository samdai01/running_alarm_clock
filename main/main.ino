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
#define DEBUG 0

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
    ultrasonic.ultrasonicSensorInit();          // Initializing ultrasonic
    alarm_clock_motor.motorInit();              // initializing motor pins
    OnboardGyro.CompassInit(&gyroscope);        // Initialize compass
    OnboardGyro.CompassCalibrate(&gyroscope);   // Calibrating Compass
}

// DOES NOT END
void loop() {
    uint16_t distance;
    static float yaw;
    float turn_around_yaw;
    bool clockwise;

    // Move forward and get distance to object in front
    ultrasonic.ultrasonicGetDistance(&distance);
    alarm_clock_motor.forward();

    if (distance < 30) {
      // stop and obtain yaw
      alarm_clock_motor.stop();
      OnboardGyro.CompassGetAngle(&yaw, &gyroscope);

#if DEBUG
      Serial.print("Current Yaw: ");
      Serial.println(yaw);
#endif
      // obtain desired yaw
      turn_around_yaw = getTurnAroundAngle(yaw);

#if DEBUG
      Serial.print("Turn around Yaw is: ");
      Serial.println(turn_around_yaw);
#endif
      // determine direction to rotate
      clockwise = turnClockwise(yaw, turn_around_yaw);

      if (clockwise) {
        while (fabs(yaw - turn_around_yaw) >= 5) {
          alarm_clock_motor.right();
          OnboardGyro.CompassGetAngle(&yaw, &gyroscope);
          delay(5);
        }
      } else {
        while (fabs(yaw - turn_around_yaw) >= 5) {
          alarm_clock_motor.left();
          OnboardGyro.CompassGetAngle(&yaw, &gyroscope);
          delay(5);
        }
      }

      alarm_clock_motor.stop();
      delay(1000);
    }
}
