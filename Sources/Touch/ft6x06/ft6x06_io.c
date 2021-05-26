/**
  ******************************************************************************
  * @file    ft6x06_io.c
  * @author  MCD Application Team
  * @brief   This file provides a set of firmware functions to manage LEDs,
  *          push-buttons, external SDRAM, external QSPI Flash, RF EEPROM,
  *          available on STM32F769I-Discovery board (MB1225) from 
  *          STMicroelectronics.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFIft6x06; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Dependencies
EndDependencies */

/* Includes ------------------------------------------------------------------*/
#include "ft6x06_io.h"

/** @addtogroup AUDIO
  * @{
  */

/** @addtogroup AUDIO
  * @{
  */

/** @defgroup AUDIO_IO_LOW_LEVEL AUDIO_IO LOW LEVEL
  * @{
  */

/** @defgroup AUDIO_IO_LOW_LEVEL_Private_TypesDefinitions STM32F769I Discovery Low Level Private Typedef
  * @{
  */
/**
  * @}
  */


static I2C_HandleTypeDef hI2cft6x06Handler = {0};

/** @defgroup AUDIO_IO_LOW_LEVEL_Private_Defines LOW_LEVEL Private Defines
  * @{
  */
/**
 * @brief STM32F769I Discovery BSP Driver version number V2.0.1
   */
#define __ft6x06_IO_BSP_VERSION_MAIN   (0x02) /*!< [31:24] main version */
#define __ft6x06_IO_BSP_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version */
#define __ft6x06_IO_BSP_VERSION_SUB2   (0x01) /*!< [15:8]  sub2 version */
#define __ft6x06_IO_BSP_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __ft6x06_IO_BSP_VERSION        ((__ft6x06_IO_BSP_VERSION_MAIN << 24)\
                                                 |(__ft6x06_IO_BSP_VERSION_SUB1 << 16)\
                                                 |(__ft6x06_IO_BSP_VERSION_SUB2 << 8 )\
                                                 |(__ft6x06_IO_BSP_VERSION_RC))

/**
  * @}
  */

/** @defgroup AUDIO_IO_BSP_Public_Functions BSP Public Functions
  * @{
  */

  /**
  * @brief  This method returns the STM32F769I Discovery BSP Driver revision
  * @retval version: 0xXYZR (8bits for each decimal, R for RC)
  */
uint32_t BSP_ft6x06_GetVersion(void)
{
  return __ft6x06_IO_BSP_VERSION;
}


/**
  * @}
  */

/** @defgroup AUDIO_IO_LOW_LEVEL_Private_Functions AUDIO_IO_LOW_LEVEL Private Functions
  * @{
  */


/*******************************************************************************
                            BUS OPERATIONS
*******************************************************************************/

/******************************* I2C Routines *********************************/
///**
//  * @brief  Initializes I2C MSP.
//  * @param  i2c_handler : I2C handler
//  * @retval None
//  */
//static void I2Cx_MspInit(I2C_HandleTypeDef *i2c_handler)
//{
//  GPIO_InitTypeDef  gpio_init_structure;
//
//  if (i2c_handler == (I2C_HandleTypeDef*)(&hI2cft6x06Handler))
//  {
//  /*** Configure the GPIOs ***/
//  /* Enable GPIO clock */
//  ft6x06_IO_EXT_I2Cx_SCL_SDA_GPIO_CLK_ENABLE();
//
//  /* Configure I2C Tx as alternate function */
//  gpio_init_structure.Pin = ft6x06_IO_EXT_I2Cx_SCL_PIN;
//  gpio_init_structure.Mode = GPIO_MODE_AF_OD;
//  gpio_init_structure.Pull = GPIO_NOPULL;
//  gpio_init_structure.Speed = GPIO_SPEED_FAST;
//  gpio_init_structure.Alternate = ft6x06_IO_EXT_I2Cx_SCL_SDA_AF;
//  HAL_GPIO_Init(ft6x06_IO_EXT_I2Cx_SCL_SDA_GPIO_PORT, &gpio_init_structure);
//
//  /* Configure I2C Rx as alternate function */
//  gpio_init_structure.Pin = ft6x06_IO_EXT_I2Cx_SDA_PIN;
//  HAL_GPIO_Init(ft6x06_IO_EXT_I2Cx_SCL_SDA_GPIO_PORT, &gpio_init_structure);
//
//  /*** Configure the I2C peripheral ***/
//  /* Enable I2C clock */
//  ft6x06_IO_EXT_I2Cx_CLK_ENABLE();
//
//  /* Force the I2C peripheral clock reset */
//  ft6x06_IO_EXT_I2Cx_FORCE_RESET();
//
//  /* Release the I2C peripheral clock reset */
//  ft6x06_IO_EXT_I2Cx_RELEASE_RESET();
//
//  /* Enable and set I2C1 Interrupt to a lower priority */
//  HAL_NVIC_SetPriority(ft6x06_IO_EXT_I2Cx_EV_IRQn, 0x0F, 0);
//  HAL_NVIC_EnableIRQ(ft6x06_IO_EXT_I2Cx_EV_IRQn);
//
//  /* Enable and set I2C1 Interrupt to a lower priority */
//  HAL_NVIC_SetPriority(ft6x06_IO_EXT_I2Cx_ER_IRQn, 0x0F, 0);
//  HAL_NVIC_EnableIRQ(ft6x06_IO_EXT_I2Cx_ER_IRQn);
//  }
//}


/**
  * @brief  Reads multiple data.
  * @param  i2c_handler : I2C handler
  * @param  Addr: I2C address
  * @param  Reg: Reg address
  * @param  MemAddress: memory address
  * @param  Buffer: Pointer to data buffer
  * @param  Length: Length of the data
  * @retval HAL status
  */
static HAL_StatusTypeDef I2Cx_ReadMultiple(I2C_HandleTypeDef *i2c_handler, uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t *Buffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_I2C_Mem_Read(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 1000);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* I2C error occured */
    //I2Cx_Error(i2c_handler, Addr);
  }
  return status;
}


/**
  * @brief  Writes a value in a register of the device through BUS in using DMA mode.
  * @param  i2c_handler : I2C handler
  * @param  Addr: Device address on BUS Bus.
  * @param  Reg: The target register address to write
  * @param  MemAddress: memory address
  * @param  Buffer: The target register value to be written
  * @param  Length: buffer size to be written
  * @retval HAL status
  */
static HAL_StatusTypeDef I2Cx_WriteMultiple(I2C_HandleTypeDef *i2c_handler, uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t *Buffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_I2C_Mem_Write(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 1000);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initiaize the I2C Bus */
    //I2Cx_Error(i2c_handler, Addr);
  }
  return status;
}

///**
//  * @brief  Checks if target device is ready for communication. 
//  * @note   This function is used with Memory devices
//  * @param  i2c_handler : I2C handler
//  * @param  DevAddress: Target device address
//  * @param  Trials: Number of trials
//  * @retval HAL status
//  */
//static HAL_StatusTypeDef I2Cx_IsDeviceReady(I2C_HandleTypeDef *i2c_handler, uint16_t DevAddress, uint32_t Trials)
//{ 
//  return (HAL_I2C_IsDeviceReady(i2c_handler, DevAddress, Trials, 1000));
//}


/**
  * @}
  */

/*******************************************************************************
                            LINK OPERATIONS
*******************************************************************************/



/******************************** LINK ft6x06 (TouchScreen) ***********************/

/**
  * @brief  Initializes Touchscreen low level.
  * @retval None
  */
void ft6x06_IO_Init(void)
{
  //I2Cx_Init(&hI2cft6x06Handler);
}

/**
  * @brief  Writes a single data.
  * @param  Addr: I2C address
  * @param  Reg: Reg address
  * @param  Value: Data to be written
  * @retval None
  */
void ft6x06_IO_Write(uint8_t Addr, uint8_t Reg, uint8_t Value)
{
  I2Cx_WriteMultiple(&hI2cft6x06Handler, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT,(uint8_t*)&Value, 1);
}

/**
  * @brief  Reads a single data.
  * @param  Addr: I2C address
  * @param  Reg: Reg address
  * @retval Data to be read
  */
uint8_t ft6x06_IO_Read(uint8_t Addr, uint8_t Reg)
{
  uint8_t read_value = 0;

  I2Cx_ReadMultiple(&hI2cft6x06Handler, Addr, Reg, I2C_MEMADD_SIZE_8BIT, (uint8_t*)&read_value, 1);

  return read_value;
}

/**
  * @brief  Reads multiple data with I2C communication
  *         channel from TouchScreen.
  * @param  Addr: I2C address
  * @param  Reg: Register address
  * @param  Buffer: Pointer to data buffer
  * @param  Length: Length of the data
  * @retval Number of read data
  */
uint16_t ft6x06_IO_ReadMultiple(uint8_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length)
{
 return I2Cx_ReadMultiple(&hI2cft6x06Handler, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, Buffer, Length);
}

/**
  * @brief  Writes multiple data with I2C communication
  *         channel from MCU to TouchScreen.
  * @param  Addr: I2C address
  * @param  Reg: Register address
  * @param  Buffer: Pointer to data buffer
  * @param  Length: Length of the data
  * @retval None
  */
void ft6x06_IO_WriteMultiple(uint8_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length)
{
  I2Cx_WriteMultiple(&hI2cft6x06Handler, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, Buffer, Length);
}

/**
  * @brief  Delay function used in TouchScreen low level driver.
  * @param  Delay: Delay in ms
  * @retval None
  */
void ft6x06_IO_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
