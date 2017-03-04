#include "mbed.h"
PwmOut PWM1(D6);
DigitalIn  Switch(SW2);
DigitalOut redLED(LED1);
DigitalOut greenLED(LED2);
float Aout;
float i;
int main()
{
    while (true) {
        
        if( Switch==1 ){
            greenLED = 1;
            redLED = 0;
            PWM1=0;
        }
        else if (Switch == 0)
        {
            redLED = 1;
            greenLED = 0;
            
        for( i=0; i<2; i+=0.0007 ){
                        Aout = 1.0 + 1.0*sin(i*3.14159);
                        //wait(0.001);
                        PWM1.period(0.5);
                        PWM1 = 0.5;
                        wait(0.001);
            }
            
        
        }
        else{
            
        
        }
    }
}