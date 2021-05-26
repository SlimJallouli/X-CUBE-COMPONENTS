#include "main.h"

#include "app.h"
#include "temperature_sensor.h"
#include "humidity_sensor.h"
#include <stdio.h>


TEMPERATURE_SENSOR_Object_t TMP_Obj;
uint8_t TMP_Id;
float   TMP_Odr;
uint8_t TMP_Status;

HUMIDITY_SENSOR_Object_t   HUM_Obj;
uint8_t HUM_Id;
float   HUM_Odr;
uint8_t HUM_Status;

/**
* @brief  Send HTML page
* @param  None
* @retval None
*/
int App_Init(void)
{
uint32_t err = 0;

  TMP_Obj.is_initialized  = 0;
  TMP_Obj.hum_is_enabled  = 0;
  TMP_Obj.temp_is_enabled = 0;  

  err = TEMPERATURE_SENSOR_Init  (&TMP_Obj);
  err = TEMPERATURE_SENSOR_Enable(&TMP_Obj);
  err = TEMPERATURE_SENSOR_ReadID(&TMP_Obj, &TMP_Id);

  HUM_Obj.is_initialized  = 0;
  HUM_Obj.hum_is_enabled  = 0;
  HUM_Obj.temp_is_enabled = 0;  

  err = HUMIDITY_SENSOR_Init  (&HUM_Obj);
  err = HUMIDITY_SENSOR_Enable(&HUM_Obj);
  err = HUMIDITY_SENSOR_ReadID(&HUM_Obj, &HUM_Id);

  if(err)
  {
    LOG("Error reading from semsor\r\n");
  }
  
  return err;
}

int App_Run(void)
{
  uint32_t err = 0;
  float    fTemp;
  float    fHum;
  
  err = TEMPERATURE_SENSOR_GetTemperature(&TMP_Obj, &fTemp); 
  err = HUMIDITY_SENSOR_GetHumidity      (&HUM_Obj, &fHum);
  
  if(err)
  {
    LOG("Error reading from semsor\r\n");
  }
  else
  {
    LOG("Temperature: %f\r\n", fTemp);
    LOG("Humidity   : %f\r\n", fHum);
  }
  
  HAL_Delay(1000);
  
  return err;
}

