/**
 * @file compass.c
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Implmementation of functions for MPU6050 gyroscope
 * @version 0.1
 * @date 2023-11-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Include Files */
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Wire.h>
#include <compass.h>
#include <stdio.h>
#include <math.h>

/* Functions */

/**
 * @brief Initialize the onboard MPU6050 gyroscope
 * @param gyroscope - a pointer to a gyroscope object 
 * @return int - status field
 */
int Compass::CompassInit(MPU6050* gyroscope) {
    Wire.begin();

    uint8_t chip_id = 0x00;
    uint8_t cout = 0;

    while (chip_id == 0x00 || chip_id == 0xFF) {
        chip_id = gyroscope->getDeviceID();
        delay(10);
        cout += 1;

        if (cout > 10) {
            return 1;
        }
    }

    gyroscope->initialize();

    return 0;
}

/**
 * @brief Calibrate the compass by using mean filtering of z axis angular velocity
 * @param gyroscope - a pointer to a gyroscope object
 * @return int - status field
 */
int Compass::CompassCalibrate(MPU6050 *gyroscope) {
    unsigned short times = 100;

    for (int i = 0; i < 100; i++) {
        angular_velocity = gyroscope->getRotationZ();
        sensor_drift += angular_velocity;
    }

    sensor_drift /= times;

    return 0;
}

/**
 * @brief Obtain the current angle from the calibrated center in CompassCalibrate
 * @param angle - float pointer representing the ongoing angle from center
 * @param gyroscope - pointer to gyroscope object
 * @return int - function status
 */
int Compass::CompassGetAngle(float *angle, MPU6050 *gyroscope) {
    unsigned long current = millis();
    change_in_time = (current - past) / 1000.0;
    past = current;

    angular_velocity = gyroscope->getRotationZ();
    float change_in_angle = (angular_velocity - sensor_drift) / 131.0 * change_in_time;

    if (fabs(change_in_angle) < 0.05) {
        change_in_angle = 0.0;
    }

    angle_from_center += change_in_angle;
    *angle = angle_from_center;
    return 0;
}
