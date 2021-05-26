#include "main.h"

#include "accelerometer.h"
#include "gyroscope.h"


ACC_Object_t        acc;
#define acc         gyro
uint8_t ACC_Id;

I2C_HandleTypeDef hi2c1;
#define ACC_I2C_HANDLER hi2c1

int main(void)
{
uint32_t err = 0;

  ACC_Obj.IO.BusType       =  ACC_I2C_BUS;
  ACC_Obj.IO.Address       =  ACC_I2C_ADDRESS;
  ACC_Obj.IO.hi2c          = &ACC_I2C_HANDLER;
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
