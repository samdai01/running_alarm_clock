/**
 * Source file for the alarm_clock_motor_movement library
 * 
 * Implements the 6 public movement functions for the running alarm clock
 * 
 * For more information see complementary header file. 
 * 
 * Author: Sam Dai
 * 
*/

#include "motor_movement.h"
#include "Arduino.h"

/**
 * Initializes the I/O for both DC Motors through an Arduino Nano
 * 
*/
void DC_Motor::motor_init() {
    pinMode(AIN1, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(PWM_LEFT, OUTPUT);
    pinMode(PWM_RIGHT, OUTPUT);
    pinMode(STANDBY, OUTPUT);

    digitalWrite(STANDBY, HIGH);
}

/**
 * Halts the alarm clock
*/
void DC_Motor::stop() {
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, LOW);
    analogWrite(PWM_LEFT, 0);
    analogWrite(PWM_RIGHT, 0);
}

/**
 * Moves the alarm clock forward at a specific speed
 * @param speed Defined speed within 1 to 255 (inclusive) in the forward direction
*/
void DC_Motor::forward(int speed) {
    digitalWrite(AIN1, 0);
    digitalWrite(BIN1, 0);
    analogWrite(PWM_LEFT, speed);
    analogWrite(PWM_RIGHT, speed);
}

/**
 * Moves the alarm clock backward at a specified speed
 * @param speed Defined speed within 1 to 255 (inclusive) in the backward direction
*/
void DC_Motor::backward(int speed) {
    digitalWrite(AIN1, 1);
    digitalWrite(BIN1, 1);
    analogWrite(PWM_LEFT, speed);
    analogWrite(PWM_RIGHT, speed);
}

/**
 * Moves the alarm clock left by turning one single motor
 * @param speed Defined speed within 1 to 255 (inclusive) for the single motor
 * to spin
*/
void DC_Motor::turn_left(int speed) {
    digitalWrite(AIN1, 1);
    digitalWrite(BIN1, 1);
    analogWrite(PWM_LEFT, speed);
    analogWrite(PWM_RIGHT, 0);
}

/**
 * Moves the alarm clock right by turning one single motor
 * @param speed Defined speed within 1 to 255 (inclusive) for the single motor
 * to spin
*/
void DC_Motor::turn_left(int speed) {
    digitalWrite(AIN1, 1);
    digitalWrite(BIN1, 1);
    analogWrite(PWM_LEFT, 0);
    analogWrite(PWM_RIGHT, speed);
}