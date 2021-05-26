/**
 ******************************************************************************
 * @file    hts221.h
 * @author  MEMS Software Solutions Team
 * @brief   HTS221 header driver file
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HTS221_H
#define HTS221_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "hts221_reg.h"
#include <string.h>

/** @addtogroup BSP BSP
 * @{
 */

/** @addtogroup Component Component
 * @{
 */

/** @addtogroup HTS221 HTS221
 * @{
 */

/** @defgroup HTS221_Exported_Types HTS221 Exported Types
 * @{
 */

typedef struct
{
  float x0;
  float y0;
  float x1;
  float y1;
} lin_t;

typedef struct
{
  uint8_t Temperature;
  uint8_t Pressure;
  uint8_t Humidity;
  uint8_t LowPower;
  float   HumMaxOdr;
  float   TempMaxOdr;
  float   PressMaxOdr;
} HTS221_Capabilities_t;

typedef union{
  int16_t i16bit[3];
  uint8_t u8bit[6];
} hts221_axis3bit16_t;

typedef union{
  int16_t i16bit;
  uint8_t u8bit[2];
} hts221_axis1bit16_t;

typedef union{
  int32_t i32bit[3];
  uint8_t u8bit[12];
} hts221_axis3bit32_t;

typedef union{
  int32_t i32bit;
  uint8_t u8bit[4];
} hts221_axis1bit32_t;

/**
 * @}
 */

/** @defgroup HTS221_Exported_Constants HTS221 Exported Constants
 * @{
 */


/** HTS221 error codes  **/
#define HTS221_OK                 0
#define HTS221_ERROR             -1

/**
 * @}
 */

/** @addtogroup HTS221_Exported_Functions HTS221 Exported Functions
 * @{
 */

int32_t HTS221_Init(HTS221_Object_t *pObj);
int32_t HTS221_DeInit(HTS221_Object_t *pObj);
int32_t HTS221_ReadID(HTS221_Object_t *pObj, uint8_t *Id);
int32_t HTS221_GetCapabilities(HTS221_Object_t *pObj, HTS221_Capabilities_t *Capabilities);
int32_t HTS221_Get_Init_Status(HTS221_Object_t *pObj, uint8_t *Status);

int32_t HTS221_HUM_Enable(HTS221_Object_t *pObj);
int32_t HTS221_HUM_Disable(HTS221_Object_t *pObj);
int32_t HTS221_HUM_GetOutputDataRate(HTS221_Object_t *pObj, float *Odr);
int32_t HTS221_HUM_SetOutputDataRate(HTS221_Object_t *pObj, float Odr);
int32_t HTS221_HUM_GetHumidity(HTS221_Object_t *pObj, float *Value);
int32_t HTS221_HUM_Get_DRDY_Status(HTS221_Object_t *pObj, uint8_t *Status);

int32_t HTS221_TEMP_Enable(HTS221_Object_t *pObj);
int32_t HTS221_TEMP_Disable(HTS221_Object_t *pObj);
int32_t HTS221_TEMP_GetOutputDataRate(HTS221_Object_t *pObj, float *Odr);
int32_t HTS221_TEMP_SetOutputDataRate(HTS221_Object_t *pObj, float Odr);
int32_t HTS221_TEMP_GetTemperature(HTS221_Object_t *pObj, float *Value);
int32_t HTS221_TEMP_Get_DRDY_Status(HTS221_Object_t *pObj, uint8_t *Status);

int32_t HTS221_Read_Reg(HTS221_Object_t *pObj, uint8_t Reg, uint8_t *Data);
int32_t HTS221_Write_Reg(HTS221_Object_t *pObj, uint8_t Reg, uint8_t Data);

int32_t HTS221_Set_One_Shot(HTS221_Object_t *pObj);
int32_t HTS221_Get_One_Shot_Status(HTS221_Object_t *pObj, uint8_t *Status);

int32_t HTS221_Enable_DRDY_Interrupt(HTS221_Object_t *pObj);

/**
 * @}
 */

/** @addtogroup HTS221_Exported_Variables HTS221 Exported Variables
 * @{
 */

//extern HTS221_CommonDrv_t HTS221_COMMON_Driver;// @SJ
//extern HTS221_HUM_Drv_t HTS221_HUM_Driver;
//extern HTS221_TEMP_Drv_t HTS221_TEMP_Driver;

extern I2C_HandleTypeDef                HTS221_I2C_HANDLER;

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
