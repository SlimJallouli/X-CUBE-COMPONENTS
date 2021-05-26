/**
 ******************************************************************************
 * @file    lis3mdl.h
 * @author  MCD Application Team
 * @brief   LIS3MDL header driver file
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
#ifndef LIS3MDL_H
#define LIS3MDL_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "lis3mdl_reg.h"
#include <stddef.h>
#include <string.h>
/** @addtogroup BSP
  * @{
  */

/** @addtogroup Component
  * @{
  */

/** @addtogroup LIS3MDL
  * @{
  */

/** @defgroup LIS3MDL_Exported_Types LIS3MDL Exported Types
 * @{
 */

typedef struct
{
  int16_t x;
  int16_t y;
  int16_t z;
} LIS3MDL_AxesRaw_t;

typedef struct
{
  int32_t x;
  int32_t y;
  int32_t z;
} LIS3MDL_Axes_t;

typedef struct
{
  uint8_t   Acc;
  uint8_t   Gyro;
  uint8_t   Magneto;
  uint8_t   LowPower;
  uint32_t  GyroMaxFS;
  uint32_t  AccMaxFS;
  uint32_t  MagMaxFS;
  float     GyroMaxOdr;
  float     AccMaxOdr;
  float     MagMaxOdr;
} LIS3MDL_Capabilities_t;

typedef union{
  int16_t i16bit[3];
  uint8_t u8bit[6];
} lis3mdl_axis3bit16_t;

typedef union{
  int16_t i16bit;
  uint8_t u8bit[2];
} lis3mdl_axis1bit16_t;

typedef union{
  int32_t i32bit[3];
  uint8_t u8bit[12];
} lis3mdl_axis3bit32_t;

typedef union{
  int32_t i32bit;
  uint8_t u8bit[4];
} lis3mdl_axis1bit32_t;

/**
  * @}
  */

/** @defgroup LIS3MDL_Exported_Constants LIS3MDL Exported Constants
 * @{
 */
#define LIS3MDL_OK            0
#define LIS3MDL_ERROR        -1

#define LIS3MDL_MAG_SENSITIVITY_FS_4GAUSS   0.146f /**< Sensitivity value for 4 gauss full scale [mgauss/LSB] */
#define LIS3MDL_MAG_SENSITIVITY_FS_8GAUSS   0.292f /**< Sensitivity value for 8 gauss full scale [mgauss/LSB] */
#define LIS3MDL_MAG_SENSITIVITY_FS_12GAUSS  0.438f /**< Sensitivity value for 12 gauss full scale [mgauss/LSB] */
#define LIS3MDL_MAG_SENSITIVITY_FS_16GAUSS  0.584f /**< Sensitivity value for 16 gauss full scale [mgauss/LSB] */

/**
  * @}
  */

/** @addtogroup LIS3MDL_Exported_Functions
 * @{
 */
int32_t LIS3MDL_Init                 (LIS3MDL_Object_t *pObj);
int32_t LIS3MDL_DeInit               (LIS3MDL_Object_t *pObj);
int32_t LIS3MDL_ReadID               (LIS3MDL_Object_t *pObj, uint8_t *Id);
int32_t LIS3MDL_GetCapabilities      (LIS3MDL_Object_t *pObj, LIS3MDL_Capabilities_t *Capabilities);

int32_t LIS3MDL_MAG_Enable           (LIS3MDL_Object_t *pObj);
int32_t LIS3MDL_MAG_Disable          (LIS3MDL_Object_t *pObj);
int32_t LIS3MDL_MAG_GetSensitivity   (LIS3MDL_Object_t *pObj, float *Sensitivity);
int32_t LIS3MDL_MAG_GetOutputDataRate(LIS3MDL_Object_t *pObj, float  *Odr);
int32_t LIS3MDL_MAG_SetOutputDataRate(LIS3MDL_Object_t *pObj, float  Odr);
int32_t LIS3MDL_MAG_GetFullScale     (LIS3MDL_Object_t *pObj, int32_t  *FullScale);
int32_t LIS3MDL_MAG_SetFullScale     (LIS3MDL_Object_t *pObj, int32_t FullScale);
int32_t LIS3MDL_MAG_GetAxes          (LIS3MDL_Object_t *pObj, LIS3MDL_Axes_t *MagneticField);
int32_t LIS3MDL_MAG_GetAxesRaw       (LIS3MDL_Object_t *pObj, LIS3MDL_AxesRaw_t *Value);

int32_t LIS3MDL_Read_Reg             (LIS3MDL_Object_t *pObj, uint8_t Reg, uint8_t *pData);
int32_t LIS3MDL_Write_Reg            (LIS3MDL_Object_t *pObj, uint8_t Reg, uint8_t Data);
int32_t LIS3MDL_MAG_Get_DRDY_Status  (LIS3MDL_Object_t *pObj, uint8_t *Status);
/**
  * @}
  */

/** @addtogroup LIS3MDL_Exported_Variables
  * @{
  */

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
