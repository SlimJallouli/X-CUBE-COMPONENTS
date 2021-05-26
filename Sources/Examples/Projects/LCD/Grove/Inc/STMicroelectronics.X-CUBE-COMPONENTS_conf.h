/**
  ******************************************************************************
  * File Name          : STMicroelectronics.X-CUBE-COMPONENTS_conf.h
  * Description        : This file provides code for the configuration
  *                      of the STMicroelectronics.X-CUBE-COMPONENTS_conf.h instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
	MiddleWare name : STMicroelectronics.X-CUBE-COMPONENTS.1.4.1
	MiddleWare fileName : STMicroelectronics.X-CUBE-COMPONENTS_conf.h
	MiddleWare version :
*/
/*---------- EAZY_LCD_I2C_HANDLER  -----------*/
#define EAZY_LCD_I2C_HANDLER      hi2c1

/*---------- EAZY_LCD_I2C_LCD_ADDR  -----------*/
#define EAZY_LCD_I2C_LCD_ADDR      0x7C

/*---------- EAZY_LCD_I2C_RGB_ADDR  -----------*/
#define EAZY_LCD_I2C_RGB_ADDR      0xC4

/*---------- LCD_FB_START_ADDRESS  -----------*/
#define LCD_FB_START_ADDRESS      0xC0000000

/*---------- LTDC_MAX_LAYER_NUMBER  -----------*/
#define LTDC_MAX_LAYER_NUMBER      2

/*---------- LTDC_ACTIVE_LAYER_BACKGROUND  -----------*/
#define LTDC_ACTIVE_LAYER_BACKGROUND      0

/*---------- LTDC_ACTIVE_LAYER_FOREGROUND  -----------*/
#define LTDC_ACTIVE_LAYER_FOREGROUND      1

/*---------- LTDC_NB_OF_LAYERS  -----------*/
#define LTDC_NB_OF_LAYERS      2

/*---------- LTDC_DEFAULT_ACTIVE_LAYER  -----------*/
#define LTDC_DEFAULT_ACTIVE_LAYER      LTDC_ACTIVE_LAYER_FOREGROUND

#ifdef __cplusplus
}
#endif
#endif /*__ STMICROELECTRONICS__X_CUBE_COMPONENTS_CONF__H_H */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
