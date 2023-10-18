/**
 * @file movement.ino
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Main test arduino sketck to test movement of the alarm clock buggy
 * @date 2023-10-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <avr/wdt.h>
#include "motor.h"

Motor alarm_clock_motor;

/**
 * @brief Arduino setup function.
 */
void setup() {
    alarm_clock_motor.motorInit();      // initializing motor pins
}

/**
 * @brief Arduino loop function. 
 * NOTE: This function will endlessly loop unless arduino is turned off
 */
void loop() {
    alarm_clock_motor.stop();
    delay(2000);
    alarm_clock_motor.forward();
    delay(2000);
    alarm_clock_motor.backward();
    delay(2000);
    alarm_clock_motor.left();
    delay(2000);
    alarm_clock_motor.right();
    delay(2000);
}