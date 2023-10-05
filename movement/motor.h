#ifndef MOTOR_H_
#define MOTOR_H_

#include <arduino.h>

class motor {
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
