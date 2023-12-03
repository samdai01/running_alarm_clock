/**
 * @file new_direction.cpp
 * @author Sam Dai (you@domain.com)
 * @brief Implementation of direction finding functions for onboard alarm clock
 * @date 2023-12-03
 */

/* Include Files */
#include "new_direction.h"

/* Functions */

/**
 * @brief Given any degree representation of an angle, return the equivalent angle
 *        within the range of [0.0, 360] degrees.  
 * @param angle
 * @return float 
 */
float naturalizeAngle(float angle) {
    int num_full_rotations;
    float naturalized_angle;

    // obtain number of 360 rotations the current angle is away from naturalized range
    num_full_rotations = angle / 360;

    // decrement since we want our naturalized angle to be within positive 0-360
    if (num_full_rotations <= 0 && angle < 0) {
        num_full_rotations--;
    }

    // obtain naturalized angle by removing all extra full rotations
    naturalized_angle = angle - (360.0 * num_full_rotations);

    if (naturalized_angle == 360.0) {
        naturalized_angle = 0.0;
    }

    return naturalized_angle;
}

/**
 * @brief Obtain a random turn around angle within a specified range (see navigation
 *        documentation)
 * @param angle 
 * @return float 
 */
float getTurnAroundAngle(float angle) {
    
}

