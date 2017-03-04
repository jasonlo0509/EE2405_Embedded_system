#include "mbed.h"
Serial pc( USBTX, USBRX );
 PwmOut PWM1(D6);
 AnalogIn Ain(A0);
 

 int main(){
 float tmp;
 float count=0, total=0;
        PWM1.period(0.001);
        PWM1 = 0.7;
       
         while(1){
                tmp = Ain;
                total++;
                if(tmp >0.5){
                    count++;}
                //wait(1);
                //PWM1=tmp;
                 //pc.printf("%f\r\n", total);
                if(total > 1000){
                    pc.printf("%1.3f\r\n", count/total);
                    break;}
         }
         
 }