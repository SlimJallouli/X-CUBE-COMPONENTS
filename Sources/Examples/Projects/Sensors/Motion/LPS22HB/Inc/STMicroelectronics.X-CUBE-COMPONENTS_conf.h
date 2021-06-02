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
/*---------- LIS3MDL_I2C_HANDLER  -----------*/
#define LIS3MDL_I2C_HANDLER      hi2c2

/*---------- LIS3MDL_I2C_ADDRESS  -----------*/
#define LIS3MDL_I2C_ADDRESS      0x3C

/*---------- LSM6DSL_I2C_HANDLER  -----------*/
#define LSM6DSL_I2C_HANDLER      hi2c2

/*---------- LSM6DSL_I2C_ADDRESS  -----------*/
#define LSM6DSL_I2C_ADDRESS      0xD4

/*---------- LPS22HB_I2C_HANDLER  -----------*/
#define LPS22HB_I2C_HANDLER      hi2c2

/*---------- LPS22HB_I2C_ADDRESS  -----------*/
#define LPS22HB_I2C_ADDRESS      0xBA

/*---------- LSM6DSL_SPI_HANDLER  -----------*/
#define LSM6DSL_SPI_HANDLER      ARD_SPI

/*---------- LSM6DSL_NSS_GPIO_Port  -----------*/
#define LSM6DSL_NSS_GPIO_Port      ARD_D10_GPIO_Port

/*---------- LSM6DSL_NSS_Pin  -----------*/
#define LSM6DSL_NSS_Pin      ARD_D10_Pin

/*---------- LSM6DSL_NSS  -----------*/
#define LSM6DSL_NSS      ARD_D10

#ifdef __cplusplus
}
#endif
#endif /*__ STMICROELECTRONICS__X_CUBE_COMPONENTS_CONF__H_H */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
