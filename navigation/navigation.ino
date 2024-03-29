/**
 * @file simple_obstacle_avoidance_test.ino
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Test arduino sketch for the onboard ultrasonic sensor
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Include Statements */
#include <avr/wdt.h>
#include "simple_obstacle_avoidance.h"

/* Objects */

UltrasonicSensor ultrasonic;

void setup() {
    Serial.begin(9600);
    ultrasonic.ultrasonicSensorInit();
}

void loop() {
    uint16_t distance;
    ultrasonic.ultrasonicGetDistance(&distance);
    ultrasonic.ultrasonicSensorPrintData(&distance);
}
