#include<xc.h>
#include "pwm_driver.h"
void pwm_init(){
    TRISC=0xFB; //1111 1011 Setting RC2 as output (CCP1)
    CCP1CON=0x0C; //0000 1100 bit 3-0: 1100 PWM Mode
    T2CON=0x06; //0000 0110 Timer2 ON [bit 2: 1 -> Timer2 ON & bit 1-0: 10 -> PRESCALE 16]
    PR2=0x5E; //0101 1110 Setting PWM Period 94 for 90% Dutycycle
}
