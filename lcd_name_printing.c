/*
 * sample.c
 *
 *  Created on: 16-Jan-2023
 *      Author: Rajat Sankhla
 */

//------------------------------------------
// TivaWare Header Files
//------------------------------------------
#include "myLib.h" // invoking user defined header files
#include "lcd.h"   // invoking user defined header files(contains prototypes of user defined functions)



//---------------------------------------
// Globals
//---------------------------------------
int i;
int a;
int b;

//---------------------------------------------------------------------------
// main()
//---------------------------------------------------------------------------
int main(void)

{
    lcd_init();
    lcd_cursor(1,1);
    lcd_string("RAJ-DRU-JAN");
    lcd_cursor(2,5);
    lcd_string("IIT BOMBAY");
    while(1);
}


//---------------------------------------------------------------------------

void lcd_portconfig(void)
{
    //Set CPU Clock to 40MHz. 400MHz PLL/2 = 200 DIV 5 = 40MHz
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

     //* * * * * * Setting Ouput for LCD * * * * * * * *
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
      GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, 0xFF);

      // * * * * * * LCD_Control Pin* * * * * * *
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
      GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, 0x70);
  }


void lcd_init()
{
    lcd_portconfig();

    lcd_reset_RW(); //writing to the lcd
    lcd_reset_EN(); // low at start of data transfer

    // transferring of data starts

    lcd_command(0x38); // function set command
    lcd_command(0x0f); // display switch command
    lcd_command(0x06); // increment cursor to the right after one character is sent
    lcd_command(0x01); // clear screen command
    lcd_command(0x80); // Set cursor to second line starting
}


void lcd_command(char cmd)
{
    lcd_put_data(cmd);
    lcd_reset_RS(); // pulled low for command transfer
    lcd_delay;
    lcd_set_EN();// setting enable high means command transfer is complete
    lcd_delay;
    lcd_reset_EN(); //setting enable to zero for future command transfer
    lcd_delay;
}

/*
 *lcd_char()
 *Description: Print single character
 *Example lcd_char('A'); prints letter A
 */

void lcd_char(char data)
{
    /* TASK 3 : Write the code here
       Hint: Somehow Similar to the function lcd_command()*/

    lcd_set_RS(); //enabling data transfer
    lcd_delay;
    lcd_reset_EN(); // pulling enable low for data transfer
    lcd_delay;
    // RW is already pulled low in lcd_init();
    lcd_put_data(data); // putting the data
    lcd_delay;
    lcd_set_EN(); // marks the completion of data transfer
    lcd_delay;


}

/*
 * lcd_string()
 * Description: Print string
 * Example: lcd_string("Hello World");
 */
void lcd_string(char *name){

        while(*name){
            // means while pointer is pointing to the string
            lcd_char(*name); // keep sending the characters of the string one by one to the lcd_char(); function.
            name++;
        }
        lcd_char(" ");
    }

/*
 * Name: lcd_cursor (row, column). For setting cursor position in 16 by 2 lcd
 * Description: Position the LCD cursor at "row", "column"
 * row: 1,2
 * column: 1 to 16
 * Example: lcd_cursor(2,14) - Places cursor at 2nd line 14th column
*/

void lcd_cursor (int row,int column)
{
    /* TASK 4 : Write the code to set the cursor position*/


       if(row==1){

           a = 0x80;
           b = 0x80 + column-1;
       }
       else if(row==2){
           a = 0xC0;
           b= 0xC0 + column-1;
       }


           //specifying the row
           lcd_reset_RS(); // pulled low for command transfer
           lcd_delay;
           lcd_reset_EN();
           lcd_put_data(a);// setting the row
           lcd_delay;
           lcd_set_EN();// setting enable high means command transfer is complete
           //lcd_delay;

           //specifying the column
           lcd_reset_RS(); // pulled low for command transfer
           lcd_delay;
           lcd_reset_EN();
           lcd_put_data(b);// setting the column
           lcd_delay;
           lcd_set_EN();// setting enable high means command transfer is complete
           //lcd_delay;


}


/*
 * Name: lcd_print (value, digit). Print value (a numeric number).
 * Description: Print number
 * value: Numeric number
 * digit: number of digits in number. Maximum allowed digit is 7
 * Example: lcd_print(456,3) - Print 456 on LCD
*/


//void lcd_print (char row, char column, uint32_t value, int digits)
//{

    /* row    : Input Cursor position for the row position
       column : Input Cursor position for the column position
       value  : Input integer value to be displayed on LCD
       digits : Input number to depict the number of decimal places u want to show*/

    // To set the LCD cursor position

    //lcd_cursor(row,column);

    /* TASK 5 : Write the code to convert the integer number into ASCII format so
       that can passed to the LCD for display */
    /* You can declare your own variables also*/

//}


