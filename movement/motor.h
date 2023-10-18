/**
 * @file motor.h
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Function definitions to control buggy motors
 * @date 2023-10-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <arduino.h>

class Motor {
    public:
        void motorInit(void);
        void forward(void);
        void backward(void);
        void left(void);
        void right(void);
        void stop(void);
    
    private:
        #define PWMA 5
        #define PWMB 6
        #define B_IN 8
        #define A_IN 7
        #define STBY 3
        #define SPEED 220
};

#endif
