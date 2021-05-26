
#ifndef _TEMPERATURE_SENSORS_H_
#define _TEMPERATURE_SENSORS_H_

#include "hts221.h"

#define TEMPERATURE_SENSOR_Object_t              HTS221_Object_t
#define TEMPERATURE_SENSOR_Capabilities_t        HTS221_Capabilities_t

#define TEMPERATURE_SENSOR_Init                  HTS221_Init
#define TEMPERATURE_SENSOR_DeInit                HTS221_DeInit
#define TEMPERATURE_SENSOR_ReadID                HTS221_ReadID
#define TEMPERATURE_SENSOR_GetCapabilities       HTS221_GetCapabilities
#define TEMPERATURE_SENSOR_Init_Status           HTS221_Get_Init_Status

#define TEMPERATURE_SENSOR_Enable                HTS221_HUM_Enable
#define TEMPERATURE_SENSOR_Disable               HTS221_HUM_Disable
#define TEMPERATURE_SENSOR_GetOutputDataRate     HTS221_HUM_GetOutputDataRate
#define TEMPERATURE_SENSOR_SetOutputDataRate     HTS221_HUM_SetOutputDataRate
#define TEMPERATURE_SENSOR_GetTemperature        HTS221_TEMP_GetTemperature
#define TEMPERATURE_SENSOR_Get_DRDY_Statu        HTS221_HUM_Get_DRDY_Status

#define TEMPERATURE_SENSOR_Read_Reg              HTS221_Read_Reg
#define TEMPERATURE_SENSOR_Write_Reg             HTS221_Write_Reg
#define TEMPERATURE_SENSOR_Set_One_Shot          HTS221_Set_One_Shot
#define TEMPERATURE_SENSOR_Get_One_Shot_Status   HTS221_Get_One_Shot_Status
#define TEMPERATURE_SENSOR_Enable_DRDY_Interrupt HTS221_Enable_DRDY_Interrupt


#define TEMPERATURE_SENSOR_BUS          HTS221_I2C_BUS
#define TEMPERATURE_SENSOR_I2C_ADDRESS  HTS221_I2C_ADDRESS
#define TEMPERATURE_SENSOR_I2C_HANDLER  HTS221_I2C_HANDLER
  
#endif