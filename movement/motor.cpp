/**
 * @file motor.cpp
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Functions to control buggy motors
 * @date 2023-10-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Include Statements */
#include "motor.h"

void Motor::motorInit(void) {
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(A_IN, OUTPUT);
    pinMode(B_IN, OUTPUT);
    pinMode(STBY, OUTPUT);
}

void Motor::forward(void) {
    digitalWrite(STBY, HIGH);

    digitalWrite(A_IN, HIGH);
    analogWrite(PWMA, SPEED);
    
    digitalWrite(B_IN, HIGH);
    analogWrite(PWMB, SPEED);
}

void Motor::backward(void) {
    digitalWrite(STBY, HIGH);

    digitalWrite(A_IN, LOW);
    analogWrite(PWMA, SPEED);

    digitalWrite(B_IN, LOW);
    analogWrite(PWMB, SPEED);
}

void Motor::left(void) {
    digitalWrite(STBY, HIGH);

    digitalWrite(A_IN, HIGH);
    analogWrite(PWMA, SPEED);

    digitalWrite(B_IN, LOW);
    analogWrite(PWMB, SPEED);
}

void Motor::right(void) {
    digitalWrite(STBY, HIGH);

    digitalWrite(A_IN, LOW);
    analogWrite(PWMA, SPEED);

    digitalWrite(B_IN, HIGH);
    analogWrite(PWMB, SPEED);
}

void Motor::stop(void) {
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);

    digitalWrite(STBY, LOW);
}
