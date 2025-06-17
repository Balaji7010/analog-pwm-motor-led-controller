#ifndef __LCD_DRIVER_H
#define __LCD_DRIVER_H

void lcd_init();
void lcd_command(unsigned char);
void send_data_to_lcd(unsigned char);
void lcd_convert(unsigned int);

#endif

