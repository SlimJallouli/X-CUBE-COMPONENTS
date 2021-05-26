#ifndef _ACC_GYRO_H_
#define _ACC_GYRO_H_

#include "lsm6dsl.h"

#define ACC_Object_t             LSM6DSL_Object_t
#define ACC_Capabilities_t       LSM6DSL_Capabilities_t
#define ACC_Axes_t               LSM6DSL_Axes_t
#define ACC_AxesRaw_t            LSM6DSL_AxesRaw_t

#define GYRO_Object_t            LSM6DSL_Object_t
#define GYRO_Capabilities_t      LSM6DSL_Capabilities_t

#define GYRO_Axes_t              LSM6DSL_Axes_t
#define GYRO_AxesRaw_t           LSM6DSL_AxesRaw_t

#define ACC_Init                 LSM6DSL_Init
#define ACC_DeInit               LSM6DSL_DeInit
#define ACC_ReadID               LSM6DSL_ReadID
#define ACC_GetCapabilities      LSM6DSL_GetCapabilities

#define ACC_Enable               LSM6DSL_ACC_Enable
#define ACC_Disable              LSM6DSL_ACC_Disable
#define ACC_GetSensitivity       LSM6DSL_ACC_GetSensitivity
#define ACC_GetOutputDataRate    LSM6DSL_ACC_GetOutputDataRate
#define ACC_SetOutputDataRate    LSM6DSL_ACC_SetOutputDataRate
#define ACC_GetFullScale         LSM6DSL_ACC_GetFullScale
#define ACC_SetFullScale         LSM6DSL_ACC_SetFullScale
#define ACC_GetAxesRaw           LSM6DSL_ACC_GetAxesRaw
#define ACC_GetAxes              LSM6DSL_ACC_GetAxes

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
  #define ACC_SPI_BUS
  #define ACC_BUS                LSM6DSL_SPI_3WIRES_BUS
  #define ACC_SPI_HANDLER        LSM6DSL_SPI_HANDLER
  #define ACC_NSS_GPIO_Port      LSM6DSL_NSS_GPIO_Port
  #define ACC_NSS_GPIO_Pin       LSM6DSL_NSS_Pin
#elif defined(LSM6DSL_BUS_TYPE_I2C)
  #define ACC_I2C_BUS
  #define ACC_BUS                LSM6DSL_I2C_BUS
  #define ACC_I2C_ADDRESS        LSM6DSL_I2C_ADDRESS
  #define ACC_I2C_HANDLER        LSM6DSL_I2C_HANDLER
#endif

#endif /* _ACC_GYRO_H_ */