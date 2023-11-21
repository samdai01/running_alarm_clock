/**
 * @file compass.h
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Header file for defining the compass used by the navigation algorithm to determine
 *        the current direction of travel compared to initialization
 * @version 0.1
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef COMPASS_H_
#define COMPASS_H_

/* Include Statements */
#include <Arduino.h>

/* Object Templates */

/**
 * @brief Abstraction of the onboard MPU6050 gyroscope module 
 */
class Compass {
    public:
        int CompassInit(MPU6050* gyroscope);
        int CompassCalibrate(MPU6050 *gyroscope);
        int CompassGetAngle(float *angle, MPU6050 *gyroscope);
    
    // Members
    private:
        int16_t angular_velocity;
        unsigned long current, past;
        float change_in_time;
        float angle_from_center = 0;
        long sensor_drift = 0;
};

#endif
