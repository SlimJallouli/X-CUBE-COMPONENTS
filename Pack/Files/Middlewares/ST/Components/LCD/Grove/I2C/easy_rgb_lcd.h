/*
 * easy_rgb_lcd.h
 *
 *  Created on: Jul 10, 2019
 *  Author: @ArduinoEasy
 *	 Github:	https://github.com/mahmood-ul-hassan/Grove_LCD_RGB_Backlight
 *	 Source: Based on SeeedStudio Arduino Library 
 *			(https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight)
 *
 */

#ifndef SOURCE_EASY_RGB_LCD_H_
#define SOURCE_EASY_RGB_LCD_H_

#include "main.h"


/***************************************
*            I2C Constants
****************************************/
/* I2C slave address to communicate with */


/*************************************************************************/
/*
 *
 *	@-> I2C_LCD_ADDR/I2C_RGB_ADDR are 1-bit left shifted addresses of Grove 16x2 LCD
 *	->	with RGB backlight because STM32 HAL functions doesnt automatically shift 
 *	->	7-bit I2C slave address to the left by 1-bit.
 *	->	For other MCU I2C_LCD_ADDR/I2C_RGB_ADDR might require 1-bit right shift
 *	->	in 7-bit I2C slave addressing mode
 *	->	i.e:	
 *	->			#define I2C_RGB_ADDR  (0xC4 >> 1)
 *	->			#define I2C_LCD_ADDR  (0x7C >> 1)
 *	->	For any other MCU Modify these addresses as shown above (if required)
 *
*/
/*************************************************************************/
 
 #define GROVE_LCD_BUS_TYPE_I2C
 
//	1-bit left shifted 7-bit address
#define I2C_RGB_ADDR  0xC4
#define I2C_LCD_ADDR  0x7C

// color define
#define WHITE           0
#define RED             1
#define GREEN           2
#define BLUE            3

#define REG_RED         0x04        // pwm2
#define REG_GREEN       0x03        // pwm1
#define REG_BLUE        0x02        // pwm0

#define REG_MODE1       0x00
#define REG_MODE2       0x01
#define REG_OUTPUT      0x08

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

void EAZY_LCD_begin(uint8_t cols, uint8_t rows, uint8_t charsize);

void EAZY_LCD_clear(void);
void EAZY_LCD_home(void);

void EAZY_LCD_noDisplay(void);
void EAZY_LCD_display(void);
void EAZY_LCD_noBlink(void);
void EAZY_LCD_blink(void);
void EAZY_LCD_noCursor(void);
void EAZY_LCD_cursor(void);
void EAZY_LCD_scrollDisplayLeft(void);
void EAZY_LCD_scrollDisplayRight(void);
void EAZY_LCD_leftToRight(void);
void EAZY_LCD_rightToLeft(void);
void EAZY_LCD_autoscroll(void);
void EAZY_LCD_noAutoscroll(void);

void EAZY_LCD_createChar(uint8_t location, uint8_t charmap[]);
void EAZY_LCD_setCursor(uint8_t col, uint8_t row);

void EAZY_LCD_write(uint8_t value);
void EAZY_LCD_print(char* data, uint8_t size);
void EAZY_LCD_command(uint8_t value);

// color control
void EAZY_LCD_setRGB(unsigned char r, unsigned char g, unsigned char b);			// set rgb
void EAZY_LCD_setPWM(unsigned char color, unsigned char pwm);					// set pwm

void EAZY_LCD_setColor(unsigned char color);
void EAZY_LCD_setColorAll(void);
void EAZY_LCD_setColorWhite(void);


#endif /* SOURCE_EASY_RGB_LCD_H_ */
