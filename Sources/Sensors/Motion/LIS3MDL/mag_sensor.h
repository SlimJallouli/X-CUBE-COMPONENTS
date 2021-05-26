#ifndef _MAG_SENSORS_H_
#define _MAG_SENSORS_H_

#include "lis3mdl.h"

#define MAG_SENSOR_Object_t               LIS3MDL_Object_t
#define MAG_SENSOR_Capabilities_t         LIS3MDL_Capabilities_t
#define MAG_SENSOR_Axes_t                 LIS3MDL_Axes_t
#define MAG_SENSOR_AxesRaw_t              LIS3MDL_AxesRaw_t

#define MAG_SENSOR_Init                   LIS3MDL_Init
#define MAG_SENSOR_DeInit                 LIS3MDL_DeInit
#define MAG_SENSOR_ReadID                 LIS3MDL_ReadID
#define MAG_SENSOR_GetCapabilities        LIS3MDL_GetCapabilities

#define MAG_SENSOR_MAG_Enable             LIS3MDL_MAG_Enable
#define MAG_SENSOR_MAG_Disable            LIS3MDL_MAG_Disable
#define MAG_SENSOR_MAG_GetSensitivity     LIS3MDL_MAG_GetSensitivity
#define MAG_SENSOR_MAG_GetOutputDataRate  LIS3MDL_MAG_GetOutputDataRate
#define MAG_SENSOR_MAG_SetOutputDataRate  LIS3MDL_MAG_SetOutputDataRate
#define MAG_SENSOR_MAG_GetFullScale       LIS3MDL_MAG_GetFullScale
#define MAG_SENSOR_MAG_SetFullScale       LIS3MDL_MAG_SetFullScale
#define MAG_SENSOR_MAG_GetAxes            LIS3MDL_MAG_GetAxes
#define MAG_SENSOR_MAG_GetAxesRaw         LIS3MDL_MAG_GetAxesRaw

#define MAG_SENSOR_Read_Reg               LIS3MDL_Read_Reg
#define MAG_SENSOR_Write_Reg              LIS3MDL_Write_Reg
#define MAG_SENSOR_MAG_Get_DRDY_Status    LIS3MDL_MAG_Get_DRDY_Status

#endif /* _MAG_SENSORS_H_ */