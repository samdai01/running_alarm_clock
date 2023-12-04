/**
 * @file new_direction.h
 * @author Sam Dai (daisam1215@gmail.com)
 * @brief Functions to help determine new direction of rotation to avoid obstacles
 * @date 2023-12-03
 */

#ifndef NEW_DIRECTION_H_
#define NEW_DIRECTION_H_

/* Enumerations */

/**
 * @brief Enumerations representing the subdivisions of available angles for 
 *        the alarm clock to rotate once it encounters an obstacle in front
 */
typedef enum {
   LEFT,
   CENTER,
   RIGHT
} Sector;

/* Functions */

/* Takes a given angle and naturalizes it to an equivalent on the 360 degree scale */
float naturalizeAngle(float angle);                       

/* Takes a given angle and returns an obstacle avoidance angle for the car to turn to */
float getTurnAroundAngle(float angle);

/* Takes a current angle and desired angle and returns if clockwise is the shortest 
   angular distance between them */
bool turnClockwise(float current_angle, float desired_angle);

#endif
