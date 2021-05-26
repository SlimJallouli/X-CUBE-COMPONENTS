
#ifndef _HUMIDITY_SENSORS_H_
#define _HUMIDITY_SENSORS_H_

#include "hts221.h"

#define HUMIDITY_SENSOR_Object_t              HTS221_Object_t
#define HUMIDITY_SENSOR_Capabilities_t        HTS221_Capabilities_t

#define HUMIDITY_SENSOR_Init                  HTS221_Init
#define HUMIDITY_SENSOR_DeInit                HTS221_DeInit
#define HUMIDITY_SENSOR_ReadID                HTS221_ReadID
#define HUMIDITY_SENSOR_GetCapabilities       HTS221_GetCapabilities
#define HUMIDITY_SENSOR_Init_Status           HTS221_Get_Init_Status

#define HUMIDITY_SENSOR_Enable                HTS221_HUM_Enable
#define HUMIDITY_SENSOR_Disable               HTS221_HUM_Disable
#define HUMIDITY_SENSOR_GetOutputDataRate     HTS221_HUM_GetOutputDataRate
#define HUMIDITY_SENSOR_SetOutputDataRate     HTS221_HUM_SetOutputDataRate
#define HUMIDITY_SENSOR_GetHumidity           HTS221_HUM_GetHumidity
#define HUMIDITY_SENSOR_Get_DRDY_Statu        HTS221_HUM_Get_DRDY_Status

#define HUMIDITY_SENSOR_Read_Reg              HTS221_Read_Reg
#define HUMIDITY_SENSOR_Write_Reg             HTS221_Write_Reg
#define HUMIDITY_SENSOR_Set_One_Shot          HTS221_Set_One_Shot
#define HUMIDITY_SENSOR_Get_One_Shot_Status   HTS221_Get_One_Shot_Status
#define HUMIDITY_SENSOR_Enable_DRDY_Interrupt HTS221_Enable_DRDY_Interrupt

#define HUMIDITY_SENSOR_BUS          HTS221_I2C_BUS
#define HUMIDITY_SENSOR_I2C_ADDRESS  HTS221_I2C_ADDRESS
extern I2C_HandleTypeDef                HTS221_I2C_HANDLER;
#define HUMIDITY_SENSOR_I2C_HANDLER  HTS221_I2C_HANDLER

#endif /* _HUMIDITY_SENSORS_H_ */