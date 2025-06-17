#include <xc.h>
#define _XTAL_FREQ 6000000
#include "lcd_driver.h"
unsigned char l,j,p,q;
void lcd_init(){
    
    TRISD=0x00; // 0000 0000 set PORTD as output 
    PORTD=0x00; // 0000 0000 Setting all the pins low
    TRISB=0x00; // 0000 0000 set PORTB as output
    PORTB=0x00; // 0000 0000 Setting all the pins low
    lcd_command(0x38);//0011 1000 DB4=1 i.e. Data length is 8 bit, N=1(DB3=1) 2 line display, F=0 5X7 dots
    __delay_ms(100);
    lcd_command(0x38);//0011 1000 DB4=1 i.e. Data length is 8 bit, N=1(DB3=1) 2 line display, F=0 5X7 dots
    __delay_ms(100);
    lcd_command(0x38);//0011 1000 DB4=1 i.e. Data length is 8 bit, N=1(DB3=1) 2 line display, F=0 5X7 dots
    __delay_ms(100);
    lcd_command(0x38);//0011 1000 DB4=1 i.e. Data length is 8 bit, N=1(DB3=1) 2 line display, F=0 5X7 dots
    __delay_ms(100);
    lcd_command(0x06);//0000 0110 cursor left to right move
    __delay_ms(100);
    lcd_command(0x0C); // 0000 1100 Display ON and Cursor OFF
    __delay_ms(100);
    lcd_command(0x01); //0000 0001  clear display
    __delay_ms(100);
}

void send_data_to_lcd(unsigned char i){
    PORTB|=0x08; //RS=1 (data) at RB3
    PORTD=i; // send data to PORTD
    PORTB|=0x01; //Enable = 1 at RB0
    PORTB&=~0x01; // Enable = 0 at RB0
    __delay_ms(50);
}

void lcd_command(unsigned char i){
    PORTB&=~0x08; //RS=0 (data) at RB3
    PORTD=i; // send data to PORTD
    PORTB|=0x01; //Enable = 1 at RB0
    PORTB&=~0x01; // Enable = 0 at RB0
    __delay_ms(5`0);
    
}

void lcd_convert(unsigned int i){
    if(i<10) //If the value is single digit
    {
        send_data_to_lcd(0x20); // Display Space
        send_data_to_lcd(0x20); // Display Space
        send_data_to_lcd(0x30+i); // Display digit in ones place
    }
    
    else if(i>=10 && i<100) //If the value is double digit
    {
        l=i/10; // Extract tens digit
        j=i%10; // Extract ones digit
        send_data_to_lcd(0x20); // Display Space
        send_data_to_lcd(0x30+l); // Display digit in ones place
        send_data_to_lcd(0x30+j); // Display digit in tens place

    }
       else //If the value is triple digit
    {
        l=i/100; // Extract hundreds digit
        j=(i%100)/10; // Extract tens digit
        p=(i%10); // Extract ones digit
        send_data_to_lcd(0x30+l); // Display digit in ones place
        send_data_to_lcd(0x30+j); // Display digit in tens place
        send_data_to_lcd(0x30+p); // Display digit in hundreds place
       }  
}
