/*
  ******************************************************************************
  * @file           : app.c
  * @brief          : Main application
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
#include "main.h"

#include "app.h"
#include "hts221.h"
#include <stdio.h>

HTS221_Object_t HTS221_Obj;
uint8_t HTS221_id;

/**
* @brief  Send HTML page
* @param  None
* @retval None
*/
int App_Init(void)
{
uint32_t err = 0;

  HTS221_Obj.IO.BusType      =  HTS221_I2C_BUS;
  HTS221_Obj.IO.Address      =  HTS221_I2C_ADDRESS;
  HTS221_Obj.IO.hi2c         = &HTS221_I2C_HANDLER; 
  HTS221_Obj.is_initialized  = 0;
  HTS221_Obj.hum_is_enabled  = 0;
  HTS221_Obj.temp_is_enabled = 0;  

  err = HTS221_ReadID     (&HTS221_Obj, &HTS221_id);
  err = HTS221_Init       (&HTS221_Obj);
  err = HTS221_TEMP_Enable(&HTS221_Obj);
  err = HTS221_HUM_Enable (&HTS221_Obj);

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
  
  err = HTS221_TEMP_GetTemperature(&HTS221_Obj, &fTemp); 
  err = HTS221_HUM_GetHumidity    (&HTS221_Obj, &fHum);
  
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

