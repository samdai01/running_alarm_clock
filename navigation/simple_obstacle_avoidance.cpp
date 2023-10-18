/**
 * @file simple_obstacle_avoidance.cpp
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Functions for the onboard ultrasonic sensor
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Include Statements */

#include "simple_obstacle_avoidance.h"

/* Functions */

void UltrasonicSensor::ultrasonicSensorInit( void ) {
    pinMode(ULTRASONIC_ECHO_PIN, INPUT);
    pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
}

void UltrasonicSensor::ultrasonicGetDistance(uint16_t* retval) {
    uint16_t signal_duration;
    uint16_t distance;

    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
    
    signal_duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
    distance = signal_duration * 0.034 / 2;

    *retval = distance;

    return;
}

void UltrasonicSensor::ultrasonicSensorPrintData(uint16_t* distance) {
    Serial.print("ULTRASONIC=");
    Serial.print(*distance);
    Serial.print("units\n");

    return;
}
