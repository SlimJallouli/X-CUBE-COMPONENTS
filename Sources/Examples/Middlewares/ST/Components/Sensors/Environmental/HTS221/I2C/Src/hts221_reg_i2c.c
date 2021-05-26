/*
 ******************************************************************************
 * @file    hts221_reg.c
 * @author  Sensors Software Solution Team
 * @brief   HTS221 driver file
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

#include "hts221_reg.h"

/**
  * @defgroup  HTS221
  * @brief     This file provides a set of functions needed to drive the
  *            hts221 enhanced inertial module.
  * @{
  *
  */

/**
  * @}
  *
  */

/**
  * @defgroup  HTS221_Data_Generation
  * @brief     This section group all the functions concerning data generation
  * @{
  *
  */
int32_t hts221_write_reg(HTS221_Object_t *pObj, uint8_t Reg, uint8_t *Data, uint16_t Len)
{
#if RTOS_ENABLED

#else
#if defined(HAL_I2C_MODULE_ENABLED)
  if(pObj->IO.BusType == HTS221_I2C_BUS)
  {  
     return HAL_I2C_Mem_Write(pObj->IO.hi2c, pObj->IO.Address,(Reg | 0x80U), I2C_MEMADD_SIZE_8BIT, Data, Len, HTS221_I2C1_POLL_TIMEOUT);
  }
#endif /* HAL_I2C_MODULE_ENABLED */
#endif /* RTOS_ENABLED */
  
  return -1;
}

int32_t hts221_read_reg (HTS221_Object_t *pObj, uint8_t Reg, uint8_t *Data, uint16_t Len)
{
#if RTOS_ENABLED

#else
  #if defined(HAL_I2C_MODULE_ENABLED)
  if(pObj->IO.BusType == HTS221_I2C_BUS)
  {
    return HAL_I2C_Mem_Read (pObj->IO.hi2c, pObj->IO.Address,(Reg | 0x80U), I2C_MEMADD_SIZE_8BIT, Data, Len, HTS221_I2C1_POLL_TIMEOUT);
  }
#endif /* HAL_I2C_MODULE_ENABLED */  
#endif /* RTOS_ENABLED */
  
  return -1;
}

/**
  * @brief  The numbers of averaged humidity samples.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of avgh in reg AV_CONF
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_humidity_avg_set(HTS221_Object_t *pObj, hts221_avgh_t val)
{
  hts221_av_conf_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_AV_CONF, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.avgh = (uint8_t)val;
    ret = hts221_write_reg(pObj, HTS221_AV_CONF, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  The numbers of averaged humidity samples.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     Get the values of avgh in reg AV_CONF
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_humidity_avg_get(HTS221_Object_t *pObj, hts221_avgh_t *val)
{
  hts221_av_conf_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_AV_CONF, (uint8_t*) &reg, 1);

  switch (reg.avgh) {
    case HTS221_H_AVG_4:
      *val = HTS221_H_AVG_4;
      break;
    case HTS221_H_AVG_8:
      *val = HTS221_H_AVG_8;
      break;
    case HTS221_H_AVG_16:
      *val = HTS221_H_AVG_16;
      break;
    case HTS221_H_AVG_32:
      *val = HTS221_H_AVG_32;
      break;
    case HTS221_H_AVG_64:
      *val = HTS221_H_AVG_64;
      break;
    case HTS221_H_AVG_128:
      *val = HTS221_H_AVG_128;
      break;
    case HTS221_H_AVG_256:
      *val = HTS221_H_AVG_256;
      break;
    case HTS221_H_AVG_512:
      *val = HTS221_H_AVG_512;
      break;
    default:
      *val = HTS221_H_AVG_ND;
      break;
  }

  return ret;
}

/**
  * @brief  The numbers of averaged temperature samples.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of avgt in reg AV_CONF
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_temperature_avg_set(HTS221_Object_t *pObj, hts221_avgt_t val)
{
  hts221_av_conf_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_AV_CONF, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.avgt = (uint8_t)val;
    ret = hts221_write_reg(pObj, HTS221_AV_CONF, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  The numbers of averaged temperature samples.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     Get the values of avgt in reg AV_CONF
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_temperature_avg_get(HTS221_Object_t *pObj, hts221_avgt_t *val)
{
  hts221_av_conf_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_AV_CONF, (uint8_t*) &reg, 1);

  switch (reg.avgh) {
    case HTS221_T_AVG_2:
      *val = HTS221_T_AVG_2;
      break;
    case HTS221_T_AVG_4:
      *val = HTS221_T_AVG_4;
      break;
    case HTS221_T_AVG_8:
      *val = HTS221_T_AVG_8;
      break;
    case HTS221_T_AVG_16:
      *val = HTS221_T_AVG_16;
      break;
    case HTS221_T_AVG_32:
      *val = HTS221_T_AVG_32;
      break;
    case HTS221_T_AVG_64:
      *val = HTS221_T_AVG_64;
      break;
    case HTS221_T_AVG_128:
      *val = HTS221_T_AVG_128;
      break;
    case HTS221_T_AVG_256:
      *val = HTS221_T_AVG_256;
      break;
    default:
      *val = HTS221_T_AVG_ND;
      break;
  }

  return ret;
}

/**
  * @brief  Output data rate selection.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of odr in reg CTRL_REG1
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_data_rate_set(HTS221_Object_t *pObj, hts221_odr_t val)
{
  hts221_ctrl_reg1_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG1, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.odr = (uint8_t)val;
    ret = hts221_write_reg(pObj, HTS221_CTRL_REG1, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  Output data rate selection.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     Get the values of odr in reg CTRL_REG1
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_data_rate_get(HTS221_Object_t *pObj, hts221_odr_t *val)
{
  hts221_ctrl_reg1_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG1, (uint8_t*) &reg, 1);

  switch (reg.odr) {
    case HTS221_ONE_SHOT:
      *val = HTS221_ONE_SHOT;
      break;
    case HTS221_ODR_1Hz:
      *val = HTS221_ODR_1Hz;
      break;
    case HTS221_ODR_7Hz:
      *val = HTS221_ODR_7Hz;
      break;
    case HTS221_ODR_12Hz5:
      *val = HTS221_ODR_12Hz5;
      break;
    default:
      *val = HTS221_ODR_ND;
      break;
  }

  return ret;
}

/**
  * @brief  Block data update.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of bdu in reg CTRL_REG1
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_block_data_update_set(HTS221_Object_t *pObj, uint8_t val)
{
  hts221_ctrl_reg1_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG1, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.bdu = val;
    ret = hts221_write_reg(pObj, HTS221_CTRL_REG1, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  Block data update.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of bdu in reg CTRL_REG1
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_block_data_update_get(HTS221_Object_t *pObj, uint8_t *val)
{
  hts221_ctrl_reg1_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG1, (uint8_t*) &reg, 1);
  *val = reg.bdu;

  return ret;
}

/**
  * @brief  One-shot mode. Device perform a single measure.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of one_shot in reg CTRL_REG2
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_one_shoot_trigger_set(HTS221_Object_t *pObj, uint8_t val)
{
  hts221_ctrl_reg2_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG2, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.one_shot = val;
    ret = hts221_write_reg(pObj, HTS221_CTRL_REG2, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  One-shot mode. Device perform a single measure.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of one_shot in reg CTRL_REG2
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_one_shoot_trigger_get(HTS221_Object_t *pObj, uint8_t *val)
{
  hts221_ctrl_reg2_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG2, (uint8_t*) &reg, 1);
  *val = reg.one_shot;

  return ret;
}

/**
  * @brief  Temperature data available.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of t_da in reg STATUS_REG
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_temp_data_ready_get(HTS221_Object_t *pObj, uint8_t *val)
{
  hts221_status_reg_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_STATUS_REG, (uint8_t*) &reg, 1);
  *val = reg.t_da;

  return ret;
}

/**
  * @brief  Humidity data available.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of h_da in reg STATUS_REG
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_hum_data_ready_get(HTS221_Object_t *pObj, uint8_t *val)
{
  hts221_status_reg_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_STATUS_REG, (uint8_t*) &reg, 1);
  *val = reg.h_da;

  return ret;
}

/**
  * @brief  Humidity output value[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_humidity_raw_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  int32_t ret;
  ret = hts221_read_reg(pObj, HTS221_HUMIDITY_OUT_L, buff, 2);
  return ret;
}

/**
  * @brief  Temperature output value[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_temperature_raw_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  int32_t ret;
  ret = hts221_read_reg(pObj, HTS221_TEMP_OUT_L, buff, 2);
  return ret;
}

/**
  * @}
  *
  */

/**
  * @defgroup  HTS221_common
  * @brief     This section group common usefull functions
  * @{
  *
  */

/**
  * @brief  Device Who amI.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_device_id_get(HTS221_Object_t *pObj, uint8_t *buff)
{
#if 0 
  int32_t ret;
  ret = hts221_read_reg(pObj, HTS221_WHO_AM_I, buff, 1);
  return ret;
#else
  return hts221_read_reg(pObj, HTS221_WHO_AM_I, buff, 1);
#endif
}

/**
  * @brief  Switch device on/off.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of pd in reg CTRL_REG1
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_power_on_set(HTS221_Object_t *pObj, uint8_t val)
{
  hts221_ctrl_reg1_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG1, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.pd = val;
    ret = hts221_write_reg(pObj, HTS221_CTRL_REG1, (uint8_t*) &reg, 1);
  }
  return ret;
}

/**
  * @brief  Switch device on/off.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of pd in reg CTRL_REG1
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_power_on_get(HTS221_Object_t *pObj, uint8_t *val)
{
  hts221_ctrl_reg1_t reg;
  int32_t mm_error;

  mm_error = hts221_read_reg(pObj, HTS221_CTRL_REG1, (uint8_t*) &reg, 1);
  *val = reg.pd;

  return mm_error;
}

/**
  * @brief  Heater enable / disable.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of heater in reg CTRL_REG2
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_heater_set(HTS221_Object_t *pObj, uint8_t val)
{
  hts221_ctrl_reg2_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG2, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.heater = val;
    ret = hts221_write_reg(pObj, HTS221_CTRL_REG2, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  Heater enable / disable.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of heater in reg CTRL_REG2
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_heater_get(HTS221_Object_t *pObj, uint8_t *val)
{
  hts221_ctrl_reg2_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG2, (uint8_t*) &reg, 1);
  *val = reg.heater;

  return ret;
}

/**
  * @brief  Reboot memory content. Reload the calibration parameters.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of boot in reg CTRL_REG2
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_boot_set(HTS221_Object_t *pObj, uint8_t val)
{
  hts221_ctrl_reg2_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG2, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.boot = val;
    ret = hts221_write_reg(pObj, HTS221_CTRL_REG2, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  Reboot memory content. Reload the calibration parameters.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of boot in reg CTRL_REG2
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_boot_get(HTS221_Object_t *pObj, uint8_t *val)
{
  hts221_ctrl_reg2_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG2, (uint8_t*) &reg, 1);
  *val = reg.boot;

  return ret;
}

/**
  * @brief  Info about device status.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     Registers STATUS_REG
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_status_get(HTS221_Object_t *pObj, hts221_status_reg_t *val)
{
  int32_t ret;
  ret = hts221_read_reg(pObj, HTS221_STATUS_REG, (uint8_t*) val, 1);
  return ret;
}

/**
  * @}
  *
  */

/**
  * @defgroup  HTS221_interrupts
  * @brief   This section group all the functions that manage interrupts
  * @{
  *
  */

/**
  * @brief  Data-ready signal on INT_DRDY pin.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of drdy in reg CTRL_REG3
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_drdy_on_int_set(HTS221_Object_t *pObj, uint8_t val)
{
  hts221_ctrl_reg3_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG3, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.drdy = val;
    ret = hts221_write_reg(pObj, HTS221_CTRL_REG3, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  Data-ready signal on INT_DRDY pin.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of drdy in reg CTRL_REG3
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_drdy_on_int_get(HTS221_Object_t *pObj, uint8_t *val)
{
  hts221_ctrl_reg3_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG3, (uint8_t*) &reg, 1);
  *val = reg.drdy;

  return ret;
}

/**
  * @brief  Push-pull/open drain selection on interrupt pads.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of pp_od in reg CTRL_REG3
  *
  */
int32_t hts221_pin_mode_set(HTS221_Object_t *pObj, hts221_pp_od_t val)
{
  hts221_ctrl_reg3_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG3, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.pp_od = (uint8_t)val;
    ret = hts221_write_reg(pObj, HTS221_CTRL_REG3, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  Push-pull/open drain selection on interrupt pads.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     Get the values of pp_od in reg CTRL_REG3
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_pin_mode_get(HTS221_Object_t *pObj, hts221_pp_od_t *val)
{
  hts221_ctrl_reg3_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG3, (uint8_t*) &reg, 1);

  switch (reg.pp_od) {
    case HTS221_PUSH_PULL:
      *val = HTS221_PUSH_PULL;
      break;
    case HTS221_OPEN_DRAIN:
      *val = HTS221_OPEN_DRAIN;
      break;
    default:
      *val = HTS221_PIN_MODE_ND;
      break;
  }

  return ret;
}

/**
  * @brief  Interrupt active-high/low.[set]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     change the values of drdy_h_l in reg CTRL_REG3
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_int_polarity_set(HTS221_Object_t *pObj, hts221_drdy_h_l_t val)
{
  hts221_ctrl_reg3_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG3, (uint8_t*) &reg, 1);

  if(ret == 0){
    reg.drdy_h_l = (uint8_t)val;
    ret = hts221_write_reg(pObj, HTS221_CTRL_REG3, (uint8_t*) &reg, 1);
  }

  return ret;
}

/**
  * @brief  Interrupt active-high/low.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  val     Get the values of drdy_h_l in reg CTRL_REG3
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_int_polarity_get(HTS221_Object_t *pObj, hts221_drdy_h_l_t *val)
{
  hts221_ctrl_reg3_t reg;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_CTRL_REG3, (uint8_t*) &reg, 1);

  switch (reg.drdy_h_l) {
    case HTS221_ACTIVE_HIGH:
      *val = HTS221_ACTIVE_HIGH;
      break;
    case HTS221_ACTIVE_LOW:
      *val = HTS221_ACTIVE_LOW;
      break;
    default:
      *val = HTS221_ACTIVE_ND;
      break;
  }

  return ret;
}

/**
  * @}
  *
  */

/**
  * @defgroup  HTS221_calibration
  * @brief     This section group all the calibration coefficients need
  *            for reading data
  * @{
  *
  */

/**
  * @brief  First calibration point for Rh Humidity.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_hum_rh_point_0_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_H0_RH_X2, buff, 1);
  *buff = (uint8_t)(((uint16_t)(*buff) >> 1) & 0x7FFFu);

  return ret;
}

/**
  * @brief  Second calibration point for Rh Humidity.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_hum_rh_point_1_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_H1_RH_X2, buff, 1);
  *buff = (uint8_t)(((uint16_t)(*buff) >> 1) & 0x7FFFu);

  return ret;
}

/**
  * @brief  First calibration point for degC temperature.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_temp_deg_point_0_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  hts221_t1_t0_msb_t reg;
  uint8_t coeff_h, coeff_l;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_T0_DEGC_X8, &coeff_l, 1);

  if(ret == 0){
    ret = hts221_read_reg(pObj, HTS221_T1_T0_MSB, (uint8_t*) &reg, 1);
    coeff_h = reg.t0_msb;
    *(buff) = (uint8_t)(((coeff_h << 8) + coeff_l) >> 3);
  }

  return ret;
}

/**
  * @brief  Second calibration point for degC temperature.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_temp_deg_point_1_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  hts221_t1_t0_msb_t reg;
  uint8_t coeff_h, coeff_l;
  int32_t ret;

  ret = hts221_read_reg(pObj, HTS221_T1_DEGC_X8, &coeff_l, 1);

  if(ret == 0){
    ret = hts221_read_reg(pObj, HTS221_T1_T0_MSB, (uint8_t*) &reg, 1);
    coeff_h = reg.t1_msb;
    *(buff) = (uint8_t)(((coeff_h << 8) + coeff_l) >> 3);
  }

  return ret;
}

/**
  * @brief  First calibration point for humidity in LSB.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_hum_adc_point_0_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  int32_t ret;
  ret = hts221_read_reg(pObj, HTS221_H0_T0_OUT_L, buff, 2);
  return ret;
}

/**
  * @brief  Second calibration point for humidity in LSB.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_hum_adc_point_1_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  int32_t ret;
  ret = hts221_read_reg(pObj, HTS221_H1_T0_OUT_L, buff, 2);
  return ret;
}

/**
  * @brief  First calibration point for temperature in LSB.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_temp_adc_point_0_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  int32_t ret;
  ret = hts221_read_reg(pObj, HTS221_T0_OUT_L, buff, 2);
  return ret;
}

/**
  * @brief  Second calibration point for temperature in LSB.[get]
  *
  * @param  pObj     read / write interface definitions
  * @param  buff    buffer that stores data read
  * @retval         interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t hts221_temp_adc_point_1_get(HTS221_Object_t *pObj, uint8_t *buff)
{
  int32_t ret;
  ret = hts221_read_reg(pObj, HTS221_T1_OUT_L, buff, 2);
  return ret;
}
  
#if RTOS_ENABLED
int32_t hts221_read_reg(HTS221_Object_t *pObj, uint8_t Reg, uint8_t *Data, uint16_t Len)
{
  HAL_StatusTypeDef status = HAL_TIMEOUT;
  
  if(osOK == osMutexWait(*pObj->IO.Peripheral_mutexHandle, 0xFFFFFFFF))
  {
#if defined(HTS221_BUS_TYPE_I2C)      
#if 1    
    status = HAL_I2C_Mem_Read (pObj->IO.hi2c, pObj->IO.Address, (Reg | 0x80U), I2C_MEMADD_SIZE_8BIT, Data, Len, HTS221_I2C1_POLL_TIMEOUT);
#else /* TODO: STill not working in IT mode */
    status = HAL_I2C_Mem_Read_IT (pObj->IO.hi2c, pObj->IO.Address, (Reg | 0x80U), I2C_MEMADD_SIZE_8BIT, Data, Len);
    osSemaphoreAcquire(*pObj->IO.rx_semHandle, 0xFFFFFFFF);
#endif
#endif /* HTS221_BUS_TYPE_I2C */
    osMutexRelease(*pObj->IO.Peripheral_mutexHandle);
  }
  
  return status;
}

int32_t hts221_write_reg(HTS221_Object_t *pObj, uint8_t Reg, uint8_t *Data, uint16_t Len)
{
  HAL_StatusTypeDef status = HAL_TIMEOUT;
  
  if(osOK == osMutexWait(*pObj->IO.Peripheral_mutexHandle, 0xFFFFFFFF))
  {
#if defined(HTS221_BUS_TYPE_I2C)      
#if 1        
    status = HAL_I2C_Mem_Write(pObj->IO.hi2c, pObj->IO.Address, (Reg | 0x80U), I2C_MEMADD_SIZE_8BIT, Data, Len, HTS221_I2C1_POLL_TIMEOUT);
#else  
    status = HAL_I2C_Mem_Write_IT(pObj->IO.hi2c, pObj->IO.Address, (Reg | 0x80U), I2C_MEMADD_SIZE_8BIT, Data, Len);
    osSemaphoreAcquire(*pObj->IO.tx_semHandle, 0xFFFFFFFF);
#endif
#endif  /* HTS221_BUS_TYPE_I2C */  
    osMutexRelease(*pObj->IO.Peripheral_mutexHandle);
  }
  
  return status;
}
#endif
/**
  * @}
  *
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
