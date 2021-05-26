#include "main.h"
#include "STMicroelectronics.X-CUBE-COMPONENTS_conf.h"
#include "RTE_Components.h"
#include <stdio.h>
#include "app.h"

#include "temperature_sensor.h"
#include "humidity_sensor.h"
#include "barometer_sensor.h"
#include "mag_sensor.h"
#include "accel_gyro_sensor.h"

/****************************** HTS221 ****************************************/
TEMPERATURE_SENSOR_Object_t TMP_Obj;
uint8_t TMP_Id;
float   TMP_Odr;
uint8_t TMP_Status;

#if defined(HTS221_BUS_TYPE_I2C)  
extern I2C_HandleTypeDef HTS221_I2C_HANDLER;
#endif

#define HUM_Obj TMP_Obj
uint8_t HUM_Id;
float   HUM_Odr;
uint8_t HUM_Status;

/****************************** LPS22 ****************************************/
BAROMETER_Object_t  PRESS_Obj;
uint8_t PRESS_Id;
#if defined(LPS22HB_BUS_TYPE_I2C)  
extern I2C_HandleTypeDef LPS22HB_I2C_HANDLER;
#endif
#if defined(LPS22HB_BUS_TYPE_SPI)  
extern SPI_HandleTypeDef LPS22HB_SPI_HANDLER;
#endif

/****************************** LIS3MDL ****************************************/
MAG_SENSOR_Object_t MAG_Obj;
uint8_t MAG_Id;

#if defined(LPS22HB_BUS_TYPE_I2C)  
extern I2C_HandleTypeDef LIS3MDL_I2C_HANDLER;
#endif
#if defined(LPS22HB_BUS_TYPE_SPI)  
extern SPI_HandleTypeDef LIS3MDL_SPI_HANDLER;
#endif

/****************************** LSM6DSL ****************************************/
ACC_Object_t        ACC_Obj;
#define GYRO_Obj    ACC_Obj
uint8_t ACC_Id;

#if defined(LSM6DSL_BUS_TYPE_I2C)  
extern I2C_HandleTypeDef LSM6DSL_I2C_HANDLER;
#endif
#if defined(LSM6DSL_BUS_TYPE_SPI)  
extern SPI_HandleTypeDef LSM6DSL_SPI_HANDLER;
#endif

/**
* @brief  Send HTML page
* @param  None
* @retval None
*/
int App_Init(void)
{
uint32_t err = 0;

/****************************** HTS221 ****************************************/
  TMP_Obj.IO.BusType      = HTS221_I2C_BUS;
  TMP_Obj.IO.Address      = HTS221_I2C_ADDRESS;
  TMP_Obj.IO.hi2c         = &HTS221_I2C_HANDLER;
  TMP_Obj.is_initialized  = 0;
  TMP_Obj.hum_is_enabled  = 0;
  TMP_Obj.temp_is_enabled = 0;  

  err = TEMPERATURE_SENSOR_Init  (&TMP_Obj);  
  err = TEMPERATURE_SENSOR_Enable(&TMP_Obj);
  err = TEMPERATURE_SENSOR_ReadID(&TMP_Obj, &TMP_Id);
  err = HUMIDITY_SENSOR_Enable   (&HUM_Obj);
  
  if(err) { LOG("HTS221 error\r\n");}
  
/****************************** LPS22 ****************************************/
  PRESS_Obj.IO.BusType       =  LPS22HB_I2C_BUS;
  PRESS_Obj.IO.Address       =  LPS22HB_I2C_ADDRESS;
  PRESS_Obj.IO.hi2c          = &LPS22HB_I2C_HANDLER;   
  PRESS_Obj.is_initialized   = 0;
  PRESS_Obj.press_is_enabled = 0;
  PRESS_Obj.temp_is_enabled  = 0;
  
  err = BAROMETER_Init        (&PRESS_Obj);
  err = BAROMETER_ReadID      (&PRESS_Obj, &PRESS_Id);
  err = BAROMETER_PRESS_Enable(&PRESS_Obj);
  err = BAROMETER_TEMP_Enable (&PRESS_Obj);

  if(err) { LOG("LPS22 error\r\n");}
  
/****************************** LIS3MDL ****************************************/
  MAG_Obj.IO.BusType     =  LIS3MDL_I2C_BUS;
  MAG_Obj.IO.Address     =  LIS3MDL_I2C_ADDRESS;
  MAG_Obj.IO.hi2c        = &LIS3MDL_I2C_HANDLER;   
  MAG_Obj.is_initialized = 0;
  MAG_Obj.mag_is_enabled = 0;
  
  err = MAG_SENSOR_Init      (&MAG_Obj);
  err = MAG_SENSOR_ReadID    (&MAG_Obj, &MAG_Id);
  err = MAG_SENSOR_MAG_Enable(&MAG_Obj);
  
  if(err) { LOG("LIS3MDL error\r\n");}

/****************************** LSM6DSL ****************************************/
  ACC_Obj.IO.BusType       =  LSM6DSL_I2C_BUS;
  ACC_Obj.IO.Address       =  LSM6DSL_I2C_ADDRESS;
  ACC_Obj.IO.hi2c          = &LSM6DSL_I2C_HANDLER;
  ACC_Obj.is_initialized   = 0;
  ACC_Obj.acc_is_enabled   = 0;
  GYRO_Obj.gyro_is_enabled = 0;

  err = ACC_Init   (&ACC_Obj);
  err = ACC_ReadID (&ACC_Obj, &ACC_Id);
  err = ACC_Enable (&ACC_Obj);
  err = GYRO_Enable(&GYRO_Obj);
   
  if(err) { LOG("LSM6DSL error\r\n");}
  
  return err;
}

int App_Run(void)
{
  uint32_t err = 0;
  float    fTemp;
  float    fHum;
  float    fPressure;
  MAG_SENSOR_Axes_t MAG_Axes;
  ACC_Axes_t        ACC_Axes;
  GYRO_Axes_t       GYRO_Axes;
  
  err = TEMPERATURE_SENSOR_GetTemperature(&TMP_Obj   , &fTemp); 
  err = HUMIDITY_SENSOR_GetHumidity      (&HUM_Obj   , &fHum);
  err = BAROMETER_PRESS_GetPressure      (&PRESS_Obj , &fPressure);
  err = MAG_SENSOR_MAG_GetAxes           (&MAG_Obj   , &MAG_Axes);
  err = ACC_GetAxes                      (&ACC_Obj   , &ACC_Axes);
  err = GYRO_GetAxes                     (&GYRO_Obj  , &GYRO_Axes);
    
  if(err)
  {
    LOG("Error reading from sensor\r\n");
  }
  else
  {
    LOG("Temperature: %d\r\n", (int)fTemp);
    LOG("Humidity   : %d\r\n", (int)fHum);
    LOG("Pressure   : %d\r\n", (int)fPressure);
    LOG("Mag        : %d, %d, %d\r\n", MAG_Axes.x , MAG_Axes.y , MAG_Axes.z);
    LOG("ACC        : %d, %d, %d\r\n", ACC_Axes.x , ACC_Axes.y , ACC_Axes.z);
    LOG("GYRO       : %d, %d, %d\r\n", GYRO_Axes.x, GYRO_Axes.y, GYRO_Axes.z);
    LOG("-------------------------------------------------------\r\n\r\n");
  }
  
  HAL_Delay(1000);
  
  return err;
}