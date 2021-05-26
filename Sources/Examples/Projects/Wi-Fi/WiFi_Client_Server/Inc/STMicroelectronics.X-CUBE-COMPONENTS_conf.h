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
/*---------- LED_TIM_HANDLER  -----------*/
#define LED_TIM_HANDLER      htim1

/*---------- LED_TIM_CHANNEL  -----------*/
#define LED_TIM_CHANNEL      TIM_CHANNEL_1

/*---------- ISM43362_SPI_HANDLER  -----------*/
#define ISM43362_SPI_HANDLER      hspi3

/*---------- ISM43362_UART_HANDLER  -----------*/
#define ISM43362_UART_HANDLER      husart1

/*---------- ESP8266_USART_HANDLER  -----------*/
#define ESP8266_USART_HANDLER      husart1

/*---------- ISM43362_RESET_GPIO_Port  -----------*/
#define ISM43362_RESET_GPIO_Port      ISM43362_RST_GPIO_Port

/*---------- ISM43362_RESET_Pin  -----------*/
#define ISM43362_RESET_Pin      ISM43362_RST_Pin

/*---------- ISM43362_NSS_GPIO_Port  -----------*/
#define ISM43362_NSS_GPIO_Port      ISM43362_SPI3_CSN_GPIO_Port

/*---------- ISM43362_NSS_Pin  -----------*/
#define ISM43362_NSS_Pin      ISM43362_SPI3_CSN_Pin

/*---------- ISM43362_DATA_READY_GPIO_Port  -----------*/
#define ISM43362_DATA_READY_GPIO_Port      ISM43362_DRDY_EXTI1_GPIO_Port

/*---------- ISM43362_DATA_READY_Pin  -----------*/
#define ISM43362_DATA_READY_Pin      ISM43362_DRDY_EXTI1_Pin

#ifdef __cplusplus
}
#endif
#endif /*__ STMICROELECTRONICS__X_CUBE_COMPONENTS_CONF__H_H */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
