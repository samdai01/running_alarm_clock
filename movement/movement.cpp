/**
 * @file movement.cpp
 * @author Sam Dai
 * @brief cpp file that abstracts a motor on the running alarm clock with
 *        some useful constants
 * @version 0.1
 * @date 2023-08-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "movement.h"

#define SPEED 200

/**
 * @brief Setup pins function for all four DC motors. Initializes all required
 * pins to desired mode
 * @author Sam Dai 
 */
void motor::setupMotor(void) {
    pinMode(MOTOR_PIN_AIN, OUTPUT);
    pinMode(MOTOR_PIN_BIN, OUTPUT);
    pinMode(MOTOR_PIN_PWMA, OUTPUT);
    pinMode(MOTOR_PIN_PWMB, OUTPUT);
    pinMode(MOTOR_PIN_STBY, OUTPUT);
}

/**
 * @brief Moves the alarm clock forward. Outputs forward/positive for both left
 * and right wheels
 * @author Sam Dai 
 */
void motor::forward(void) {
    // left side
    digitalWrite(MOTOR_PIN_AIN, HIGH);
    analogWrite(MOTOR_PIN_PWMA, SPEED);

    // right side
    digitalWrite(MOTOR_PIN_BIN, HIGH);
    analogWrite(MOTOR_PIN_PWMB, SPEED);
}

/**
 * @brief Move the alarm clock backwards. Outputs low for both left and right wheels
 * @author Sam Dai
 */
void motor::backward(void) {
    // left side
    digitalWrite(MOTOR_PIN_AIN, LOW);
    analogWrite(MOTOR_PIN_PWMA, SPEED);

    // right side
    digitalWrite(MOTOR_PIN_BIN, LOW);
    analogWrite(MOTOR_PIN_PWMB, SPEED);
}

