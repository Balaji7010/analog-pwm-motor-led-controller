#include <xc.h>
#define _XTAL_FREQ 6000000
#include "adc_driver.h"
#include "lcd_driver.h"
unsigned int adc_low,adc_high,calibrated_data;
unsigned long int adc_voltage;



void adc_init(){
    //ADC Initialization
    ADCON0=0x81;  //10000001 A/D is powered up and A/D Conversion Clock select bit (FOSC/32)  and channel 0 (AN0) is selected
    ADCON1=0x8E; //10001110 Configuring analog pins AN0 1110 and Right justified ADC Result and FOSC/32 is selected
    __delay_ms(10); //Acquisition Time
}


void read_adc(){
        ADCON0|=0x04; // Start ADC conversion by setting the GO/DONE bit 
        while(ADCON0&0x04); // Wait for ADC conversion to complete (GO/DONE bit becomes 0)
        adc_low=ADRESL; // Stores lower 8 bits of 10-bit ADC result
        adc_high=ADRESH; // Stores upper 2 bits of 10-bit ADC result remaining bits read as 0 (Right Justified))
        adc_voltage=(adc_high<<8)+adc_low; //Combining adc_low and adc_high to form 10 bit ADC value
        calibrated_data=(adc_voltage*338)/1023;  //Calibrating ADC Value to 0-338 range
        CCPR1L=(calibrated_data>>2); // Load the upper 8 bits (MSBs) of the 10-bit PWM duty cycle into CCPR1L register
        CCP1CON=(CCP1CON & 0xCF) | ((calibrated_data & 0x03)<<4); // Sending lastmand remaining 2 bit to CCP1CON<5:4> 
        lcd_convert(calibrated_data);  // Convert number to characters and display on LCD
}


