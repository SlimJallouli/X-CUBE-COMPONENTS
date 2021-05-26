/**
  ******************************************************************************
  * File Name          : STMicroelectronics.X-CUBE-COMPONENTS_conf.h
  * Description        : This file provides code for the configuration
  *                      of the STMicroelectronics.X-CUBE-COMPONENTS_conf.h instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STMICROELECTRONICS__X_CUBE_COMPONENTS_CONF__H__
#define __STMICROELECTRONICS__X_CUBE_COMPONENTS_CONF__H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/**
	MiddleWare name : STMicroelectronics.X-CUBE-COMPONENTS.1.3.4
	MiddleWare fileName : STMicroelectronics.X-CUBE-COMPONENTS_conf.h
	MiddleWare version :
*/
/*---------- LED_TIM_HANDLER  -----------*/
#define LED_TIM_HANDLER      htim1

/*---------- LED_TIM_CHANNEL  -----------*/
#define LED_TIM_CHANNEL      TIM_CHANNEL_1

/*---------- HTS221_I2C_HANDLER  -----------*/
#define HTS221_I2C_HANDLER      hi2c2

/*---------- HTS221_I2C_ADDRESS  -----------*/
#define HTS221_I2C_ADDRESS      0xBF

/*---------- ISM43362_SPI_HANDLER  -----------*/
#define ISM43362_SPI_HANDLER      hspi3

/*---------- ISM43362_UART_HANDLER  -----------*/
#define ISM43362_UART_HANDLER      husart1

/*---------- ESP8266_USART_HANDLER  -----------*/
#define ESP8266_USART_HANDLER      husart1

/*---------- EAZY_LCD_I2C_HANDLER  -----------*/
#define EAZY_LCD_I2C_HANDLER      hi2c1

/*---------- EAZY_LCD_I2C_LCD_ADDR  -----------*/
#define EAZY_LCD_I2C_LCD_ADDR      0x7C

/*---------- EAZY_LCD_I2C_RGB_ADDR  -----------*/
#define EAZY_LCD_I2C_RGB_ADDR      0xC4

/*---------- SSD1306_I2C_HANDLER  -----------*/
#define SSD1306_I2C_HANDLER      hi2c1

/*---------- SSD1306_I2C_ADDR  -----------*/
#define SSD1306_I2C_ADDR      0x78

#ifdef __cplusplus
}
#endif
#endif /*__ STMICROELECTRONICS__X_CUBE_COMPONENTS_CONF__H_H */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
