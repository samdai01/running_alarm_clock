/*
  Main control for synchronization of all resources
*/

/**
 * Importing of required libraries for alarm clock function
 * motor_movement -> abstracts the DC_motors and provides basic functions for
 *                   alarm clock movement
*/

#include <motor_movement.h>

/**
 * Defining of any abstractions needed
*/
DC_Motor dc_motor;

/**
* Initialization function which sets up an interface for our variables and pins
*/
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  dc_motor.motor_init();
}

/**
* Forever function that loops consecutively 
*/
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  dc_motor.stop();
  delay(2000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  dc_motor.forward(120);
  delay(2000);                      // wait for a second
  dc_motor.backward(120);
  delay(2000);
}
