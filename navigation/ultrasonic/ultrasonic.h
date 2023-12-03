/**
 * @file simple_obstacle_avoidance.h
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Defines set of simple obstacle avoidance functions for the buggy which
 *        uses the onboard ultrasonic module
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _OBSTACLE_AVOIDANCE_H_
#define _OBSTACLE_AVOIDANCE_H_

/* Include Statements */
#include <arduino.h>

class UltrasonicSensor {
    public:

        void ultrasonicSensorInit(void);
        void ultrasonicSensorPrintData(uint16_t* distance);
        void ultrasonicGetDistance(uint16_t* retval);
    
    private:

        #define ULTRASONIC_TRIG_PIN 13
        #define ULTRASONIC_ECHO_PIN 12
        #define MIN_DISTANCE_CM 15
};

#endif
