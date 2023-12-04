/**
 * @file new_direction.cpp
 * @author Sam Dai (you@domain.com)
 * @brief Implementation of direction finding functions for onboard alarm clock
 * @date 2023-12-03
 */

/* Include Files */
#include "direction.h"

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
 * @param angle -> guaranteed to be naturalized to [0, 360)
 * @return float 
 */
float getTurnAroundAngle(float angle) {
    float turn_around_angle;
    Sector rotation_sector;

    rotation_sector = random(0, 3);

    if (angle >= 0.0 && angle < 60.0) {
        switch(rotation_sector) {
            case LEFT:
                turn_around_angle = random(120.0, 180.0);
                break;
            case CENTER:
                turn_around_angle = random(180.0, 240.0);
                break;
            case RIGHT:
                turn_around_angle = random(240.0, 300.0);
                break;
            default:
                turn_around_angle = 0.0;
        }
    } else if (angle >= 60.0 && angle < 120.0) {
        switch(rotation_sector) {
            case LEFT:
                turn_around_angle = random(180.0, 240.0);
                break;
            case CENTER:
                turn_around_angle = random(240.0, 300.0);
                break;
            case RIGHT:
                turn_around_angle = random(300.0, 360.0);
                break;
            default:
                turn_around_angle = 0.0;
        }
    } else if (angle >= 120.0 && angle < 180.0) {
        switch(rotation_sector) {
            case LEFT:
                turn_around_angle = random(240.0, 300.0);
                break;
            case CENTER:
                turn_around_angle = random(300.0, 360.0);
                break;
            case RIGHT:
                turn_around_angle = random(0.0, 60.0);
                break;
            default:
                turn_around_angle = 0.0;
        }
    } else if (angle >= 180.0 && angle < 240.0) {
        switch(rotation_sector) {
            case LEFT:
                turn_around_angle = random(300.0, 360.0);
                break;
            case CENTER:
                turn_around_angle = random(0.0, 60.0);
                break;
            case RIGHT:
                turn_around_angle = random(60.0, 120.0);
                break;
            default:
                turn_around_angle = 0.0;
        }
    } else if (angle >= 240.0 && angle < 300.0) {
        switch(rotation_sector) {
            case LEFT:
                turn_around_angle = random(0.0, 60.0);
                break;
            case CENTER:
                turn_around_angle = random(60.0, 120.0);
                break;
            case RIGHT:
                turn_around_angle = random(120.0, 180.0);
                break;
            default:
                turn_around_angle = 0.0;
        }
    } else if (angle >= 300.0 && angle < 360.0) {
        switch(rotation_sector) {
            case LEFT:
                turn_around_angle = random(60.0, 120.0);
                break;
            case CENTER:
                turn_around_angle = random(120.0, 180.0);
                break;
            case RIGHT:
                turn_around_angle = random(180.0, 240.0);
                break;
            default:
                turn_around_angle = 0.0;
        }
    }

    return turn_around_angle;
}

/**
 * @brief Takes a given angle represents the current yaw, and a desired yaw for
 *        the alarm clock and determines if turning clockwise (right) would be
 *        the closest (angular distance wise)
 * 
 * @param current_angle -> guaranteed to be naturalized to [0, 360)
 * @param desired_angle -> guaranteed to be naturalized to [0, 360)
 * @return true 
 * @return false 
 */
bool turnClockwise(float current_angle, float desired_angle) {
    int clockwise_distance;
    int cclockwise_distance;
    
    // obtain angular distances in both directions
    clockwise_distance = ((int)desired_angle - (int)current_angle + 360) % 360;
    cclockwise_distance = ((int) current_angle - (int)desired_angle + 360) % 360;

    if (clockwise_distance < cclockwise_distance) {
        return true;
    } else {
        return false;
    }
    
}
