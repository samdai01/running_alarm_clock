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

/* Include files */
#include <avr/wdt.h>
#include <simple_obstacle_avoidance.h>
#include <motor.h>

UltrasonicSensor ultrasonic;
Motor alarm_clock_motor;

void setup() {
    Serial.begin(9600);
    ultrasonic.ultrasonicSensorInit();
    alarm_clock_motor.motorInit();      // initializing motor pins
}

void loop() {
    uint16_t distance;
    ultrasonic.ultrasonicGetDistance(&distance);

    if (distance < 30) {
      alarm_clock_motor.stop();
      delay(1000);
      long second_to_rotate = random(0, 5);
      alarm_clock_motor.left();
      delay(second_to_rotate * 1000);
      alarm_clock_motor.forward();
    } else {
      alarm_clock_motor.forward();
    }
}
