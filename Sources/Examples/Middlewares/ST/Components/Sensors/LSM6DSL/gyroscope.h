#ifndef _GYRO_H_
#define _GYRO_H_

#include "lsm6dsl.h"

#define GYRO_Object_t            LSM6DSL_Object_t
#define GYRO_Capabilities_t      LSM6DSL_Capabilities_t

#define GYRO_Axes_t              LSM6DSL_Axes_t
#define GYRO_AxesRaw_t           LSM6DSL_AxesRaw_t

#define GYRO_Init                LSM6DSL_Init
#define GYRO_DeInit              LSM6DSL_DeInit
#define GYRO_ReadID              LSM6DSL_ReadID
#define GYRO_GetCapabilities     LSM6DSL_GetCapabilities

#define GYRO_Enable              LSM6DSL_GYRO_Enable
#define GYRO_Disable             LSM6DSL_GYRO_Disable
#define GYRO_GetSensitivity      LSM6DSL_GYRO_GetSensitivity
#define GYRO_GetOutputDataRate   LSM6DSL_GYRO_GetOutputDataRate
#define GYRO_SetOutputDataRate   LSM6DSL_GYRO_SetOutputDataRate
#define GYRO_GetFullScale        LSM6DSL_GYRO_GetFullScale
#define GYRO_SetFullScale        LSM6DSL_GYRO_SetFullScale
#define GYRO_GetAxesRaw          LSM6DSL_GYRO_GetAxesRaw
#define GYRO_GetAxes             LSM6DSL_GYRO_GetAxes

#if defined(LSM6DSL_BUS_TYPE_SPI)
  #define GYRO_SPI_BUS
  #define GYRO_BUS                LSM6DSL_SPI_3WIRES_BUS
  #define GYRO_SPI_HANDLER        LSM6DSL_SPI_HANDLER
  #define GYRO_NSS_GPIO_Port      LSM6DSL_NSS_GPIO_Port
  #define GYRO_NSS_GPIO_Pin       LSM6DSL_NSS_Pin
#elif defined(LSM6DSL_BUS_TYPE_I2C)
  #define GYRO_I2C_BUS
  #define GYRO_BUS                LSM6DSL_I2C_BUS
  #define GYRO_I2C_ADDRESS        LSM6DSL_I2C_ADDRESS
  #define GYRO_I2C_HANDLER        LSM6DSL_I2C_HANDLER
#endif

#endif /* _GYRO_H_ */