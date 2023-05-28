/**
 * Header file for the alarm_clock_motor_movement library
 * 
 * Contains 5 functions that are responsible for moving the alarm clock forward,
 * backward, left, and right respectively. All functions also require a specific
 * speed value from 1 to 255. A stop function is also included as the default 
 * state.
 * 
 * An initialization function is also included to set up the pins for both DC
 * motors.
 * 
 * Author: Sam Dai
 * 
*/

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>

/**
 * DC Motor class that provides an interface for the direct control of the 
 * movement of the alarm clock.
 * 
 * Control of the 2 DC Motors is NOT individualized and confined to the 
 * specified action of the entire alarm clock. 
 * 
*/
class DC_Motor {
    

    public:
        void motor_init();

        void stop();
        void forward(int speed);
        void backward(int speed);
        void turn_left(int speed);
        void turn_right(int speed);
    
    private:
        #define AIN1 7
        #define BIN1 12
        #define PWM_LEFT 5
        #define PWM_RIGHT 6
        #define STANDBY 8
}


#endif