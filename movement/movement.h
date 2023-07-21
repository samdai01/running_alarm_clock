/**
 * @file movement.h
 * @author Sam Dai
 * @brief Header file that abstracts a motor on the running alarm clock with
 *        some useful constants
 * @version 0.1
 * @date 2023-07-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef MOVEMENT
#define MOVEMENT

#include <arduino.h>

// Motor class
class motor {
    public:
    // setup function that initializes all the pins
    void setupMotor(void);
    void forward(void);
    void backward(void);
    void left(void);
    void right(void);
    void stop(void);

    private:
    #define MOTOR_PIN_STBY 3
    #define MOTOR_PIN_PWMA 5
    #define MOTOR_PIN_PWMB 6
    #define MOTOR_PIN_AIN 7
    #define MOTOR_PIN_BIN 8
};

#endif
