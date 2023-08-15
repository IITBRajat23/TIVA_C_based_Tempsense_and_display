/*
 * lcd.h
 *
 *  Created on: 09-Feb-2023
 *      Author: Rajat Sankhla
 */

#ifndef LCD_H_
#define LCD_H_

#define lcd_delay SysCtlDelay(67000 *2) // changed
#define lcd_put_data(x)  GPIOPinWrite(GPIO_PORTB_BASE,(0xFF), x)
#define lcd_set_RS() (GPIOPinWrite(GPIO_PORTC_BASE,(GPIO_PIN_4),0x01<<4))
#define lcd_set_RW() (GPIOPinWrite(GPIO_PORTC_BASE,(GPIO_PIN_5),0x01<<5))
#define lcd_set_EN() (GPIOPinWrite(GPIO_PORTC_BASE,(GPIO_PIN_6),0x01<<6))
#define lcd_reset_RS() (GPIOPinWrite(GPIO_PORTC_BASE,(GPIO_PIN_4),~(0x01<<4)))
#define lcd_reset_RW() (GPIOPinWrite(GPIO_PORTC_BASE,(GPIO_PIN_5),~(0x01<<5)))
#define lcd_reset_EN() (GPIOPinWrite(GPIO_PORTC_BASE,(GPIO_PIN_6),~(0x01<<6)))

void lcd_portconfig(void);
void lcd_init(void);
void lcd_command(char cmd);
void lcd_char(char data);
void lcd_string(char *name);
void  lcd_cursor (int row,int column);
void lcd_print (char row, char column, uint32_t value);
void lcd_integer(int integer);
void ADC_config(void);

#endif /* LCD_H_ */
