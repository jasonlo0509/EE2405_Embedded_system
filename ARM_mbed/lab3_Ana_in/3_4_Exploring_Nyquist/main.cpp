#include "mbed.h"
  
  AnalogOut Aout(DAC0_OUT);
  AnalogIn Ain(A0);
  DigitalOut test(LED2);
  float ADCdata;
  
  int main(){
          while(1){
             ADCdata = Ain;
             test = 1;
             test = 0;
             Aout = ADCdata;
             test = 1;
             test = 0;
             test = 1;
             test = 0;
         }
 }