#include "mbed.h"
 
 PwmOut PWM1(D6);
 
 int main() {
    PWM1.period(0.02);
    PWM1 = 0.3;
}