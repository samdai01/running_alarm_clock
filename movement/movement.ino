#include <avr/wdt.h>
#include "motor.h"

motor alarm_clock_motor;

void setup() {
    alarm_clock_motor.motorInit();
    delay(2000);
    alarm_clock_motor.forward();
    delay(2000);
}

void loop() {
    alarm_clock_motor.stop();
    delay(2000);
    alarm_clock_motor.forward();
    delay(2000);
    alarm_clock_motor.backward();
    delay(2000);
    alarm_clock_motor.left();
    delay(2000);
    alarm_clock_motor.right();
    delay(2000);
}