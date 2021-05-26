/**
  ******************************************************************************
  * @file    ft6x06_io.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for STM32F769I-Discovery LEDs,
  *          push-buttons hardware resources.
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
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ft6x06_IO_H
#define __ft6x06_IO_H

#ifdef __cplusplus
 extern "C" {
#endif


 /* Includes ------------------------------------------------------------------*/
#include "main.h"

   /**
  * @brief User can use this section to tailor I2C1/I2C1 instance used and associated
  * resources.
  * Definition for I2C1 clock resources
  */
/**
  * @brief User can use this section to tailor I2C1/I2C1 instance used and associated
  * resources.
  * Definition for I2C1 clock resources
  */
#define ft6x06_IO_EXT_I2Cx                             I2C1
#define ft6x06_IO_EXT_I2Cx_CLK_ENABLE()                __HAL_RCC_I2C1_CLK_ENABLE()
#define ft6x06_IO_DMAx_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()
#define ft6x06_IO_EXT_I2Cx_SCL_SDA_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()

#define ft6x06_IO_EXT_I2Cx_FORCE_RESET()               __HAL_RCC_I2C1_FORCE_RESET()
#define ft6x06_IO_EXT_I2Cx_RELEASE_RESET()             __HAL_RCC_I2C1_RELEASE_RESET()

/** @brief Definition for I2C1 Pins
  */
#define ft6x06_IO_EXT_I2Cx_SCL_PIN                     GPIO_PIN_8 /*!< PB8 */
#define ft6x06_IO_EXT_I2Cx_SCL_SDA_GPIO_PORT           GPIOB
#define ft6x06_IO_EXT_I2Cx_SCL_SDA_AF                  GPIO_AF4_I2C1
#define ft6x06_IO_EXT_I2Cx_SDA_PIN                     GPIO_PIN_9 /*!< PB9 */

/** @brief Definition of I2C interrupt requests
  */
#define ft6x06_IO_EXT_I2Cx_EV_IRQn                     I2C1_EV_IRQn
#define ft6x06_IO_EXT_I2Cx_ER_IRQn                     I2C1_ER_IRQn

/* I2C TIMING Register define when I2C clock source is SYSCLK */
/* I2C TIMING is calculated from APB1 source clock = 50 MHz */
/* Due to the big MOFSET capacity for adapting the camera level the rising time is very large (>1us) */
/* 0x40912732 takes in account the big rising and aims a clock of 100khz */
#ifndef ft6x06_IO_I2Cx_TIMING  
#define ft6x06_IO_I2Cx_TIMING                      ((uint32_t)0x40912732)
#endif /* ft6x06_IO_I2Cx_TIMING */


#define ft6x06_IO_I2Cx_TIMING                      ((uint32_t)0x40912732)

   
   /* TouchScreen (ft6x06) IO functions */
void     ft6x06_IO_Init(void);
void     ft6x06_IO_Write(uint8_t Addr, uint8_t Reg, uint8_t Value);
uint8_t  ft6x06_IO_Read(uint8_t Addr, uint8_t Reg);
uint16_t ft6x06_IO_ReadMultiple(uint8_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length);
void     ft6x06_IO_WriteMultiple(uint8_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length);
void     ft6x06_IO_Delay(uint32_t Delay);

uint32_t BSP_ft6x06_GetVersion(void);

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

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* __STM32F769I_AUDIO_IOH */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
