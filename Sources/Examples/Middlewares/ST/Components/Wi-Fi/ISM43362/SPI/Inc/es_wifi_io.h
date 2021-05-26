/**
  ******************************************************************************
  * @file    es_wifi_io.h
  * @author  MCD Application Team
  * @brief   This file contains the functions prototypes for es_wifi IO operations.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#ifndef WIFI_IO_H
#define WIFI_IO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/


/* Exported functions ------------------------------------------------------- */ 
int8_t  ISM43362_DeInit     (ES_WIFIObject_t *Obj);
int8_t  ISM43362_Init       (ES_WIFIObject_t *Obj);
int8_t  ISM43362_ResetModule(ES_WIFIObject_t *Obj);
int16_t ISM43362_ReceiveData(ES_WIFIObject_t *Obj, uint8_t *pData, uint16_t len, uint32_t timeout);
int16_t ISM43362_SendData   (ES_WIFIObject_t *Obj, uint8_t *pData, uint16_t len, uint32_t timeout);

void    ISM43362_Delay(uint32_t Delay);
void    ISM43362_DATA_READY_ISR(void);
void    ISM43362_TxCpltCallback(void);/* @SJ */
void    ISM43362_RxCpltCallback(void);/* @SJ */
#ifdef __cplusplus
}
#endif

#endif /* WIFI_IO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
