/**
******************************************************************************
* @file    es_wifi_io.c
* @author  MCD Application Team
* @brief   This file implements the IO operations to deal with the es-wifi
*          module. It mainly Inits and Deinits the SPI interface. Send and
*          receive data over it.
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V. 
* All rights reserved.</center></h2>
*
* This software component is licensed by ST under Ultimate Liberty license
* SLA0044, the "License"; You may not use this file except in compliance with
* the License. You may obtain a copy of the License at:
*                             www.st.com/SLA0044
*
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "es_wifi.h"
#include "es_wifi_io.h"
#include <string.h>
#include "es_wifi_conf.h"
#include <core_cm4.h>
#include "main.h"
#include "RTE_Components.h"
#include "STMicroelectronics.X-CUBE-COMPONENTS_conf.h"

/* Private define ------------------------------------------------------------*/
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
//SPI_HandleTypeDef hspi;
static  int volatile spi_rx_event = 0;
static  int volatile spi_tx_event = 0;
static  int volatile cmddata_rdy_rising_event = 0;

#if WIFI_USE_CMSIS_OS
osMutexId es_wifi_mutex;
osMutexDef(es_wifi_mutex);

static    osMutexId spi_mutex;
osMutexDef(spi_mutex);

static    osSemaphoreId spi_rx_sem;
osSemaphoreDef(spi_rx_sem);

static    osSemaphoreId spi_tx_sem;
osSemaphoreDef(spi_tx_sem);

static    osSemaphoreId cmddata_rdy_rising_sem;
osSemaphoreDef(cmddata_rdy_rising_sem);

#endif


/* Private function prototypes -----------------------------------------------*/
static  int wait_cmddata_rdy_high(int timeout);
static  int wait_cmddata_rdy_rising_event(int timeout);
static  int wait_spi_tx_event(int timeout);
static  int wait_spi_rx_event(int timeout);
static  void ISM43362_DelayUs(uint32_t);
/* Private functions ---------------------------------------------------------*/
#if defined(ISM43362_BUS_TYPE_SPI)
extern SPI_HandleTypeDef ISM43362_SPI_HANDLER;

#define SM43362_IO_Receive      HAL_SPI_Receive
#define SM43362_IO_Receive_IT   HAL_SPI_Receive_IT
#define SM43362_IO_Transmit_IT  HAL_SPI_Transmit_IT

#define ISM43362_ENABLE_NSS()              do{HAL_GPIO_WritePin( ISM43362_NSS_GPIO_Port, ISM43362_NSS_Pin, GPIO_PIN_RESET );}while(0);
#define ISM43362_DISABLE_NSS()             do{HAL_GPIO_WritePin( ISM43362_NSS_GPIO_Port, ISM43362_NSS_Pin, GPIO_PIN_SET );}while(0);

#elif defined(ISM43362_BUS_TYPE_UART) /* Not supported/tested yet */
#error "Not supported/tested yet"

extern UART_HandleTypeDef       ISM43362_UART_HANDLER;

#define SM43362_IO_Receive      HAL_UART_Receive
#define SM43362_IO_Receive_IT   HAL_UART_Receive_IT
#define SM43362_IO_Transmit_IT  HAL_UART_Transmit_IT

#define ISM43362_ENABLE_NSS()
#define ISM43362_DISABLE_NSS()

#else
#error "Bus not defined/supported"
#endif


#define ISM43362_IS_CMDDATA_READY()        (HAL_GPIO_ReadPin(ISM43362_DATA_READY_GPIO_Port, ISM43362_DATA_READY_Pin) == GPIO_PIN_SET)

static void ISM43362_RESET_MODULE(void)
{
  HAL_GPIO_WritePin(ISM43362_RESET_GPIO_Port, ISM43362_RESET_Pin, GPIO_PIN_RESET);
  HAL_Delay(10);
  HAL_GPIO_WritePin(ISM43362_RESET_GPIO_Port, ISM43362_RESET_Pin, GPIO_PIN_SET);
  HAL_Delay(500);
}

/**
* @brief  Initialize the SPI3
* @param  None
* @retval None
*/
int8_t ISM43362_Init(ES_WIFIObject_t *Obj)
{
#if defined(ISM43362_BUS_TYPE_SPI)  
  Obj->fops.BusType = SPI_BUS; /*0 means I2C, 1 means SPI-3-Wires */
  Obj->fops.hspi    = &ISM43362_SPI_HANDLER;
#endif
  
#if defined(ISM43362_BUS_TYPE_UART)  
  Obj->fops.BusType = SPI_UART; /*0 means I2C, 1 means SPI-3-Wires */
  Obj->fops.hspi    = &ISM43362_UART_HANDLER;
#endif  
  
#if WIFI_USE_CMSIS_OS
  cmddata_rdy_rising_event=0;
  es_wifi_mutex = osMutexCreate(osMutex(es_wifi_mutex));
  spi_mutex = osMutexCreate(osMutex(spi_mutex));
  spi_rx_sem = osSemaphoreCreate(osSemaphore(spi_rx_sem) , 1 );
  spi_tx_sem = osSemaphoreCreate(osSemaphore(spi_tx_sem) , 1 );
  cmddata_rdy_rising_sem = osSemaphoreCreate(osSemaphore(cmddata_rdy_rising_sem) , 1 );
  /* take semaphore */
  SEM_WAIT(cmddata_rdy_rising_sem, 1);
  SEM_WAIT(spi_rx_sem, 1);
  SEM_WAIT(spi_tx_sem, 1);
#endif
  
  return ISM43362_ResetModule(Obj);
}


int8_t ISM43362_ResetModule(ES_WIFIObject_t *Obj)
{
  uint32_t tickstart = HAL_GetTick();
  uint8_t Prompt[6];
  uint8_t count = 0;
  HAL_StatusTypeDef  Status;
  
  ISM43362_RESET_MODULE();
  ISM43362_ENABLE_NSS(); 
  ISM43362_DelayUs(15);
  
  while (ISM43362_IS_CMDDATA_READY())
  {
    Status = SM43362_IO_Receive(Obj->fops.hspi , &Prompt[count], 1, 0xFFFF);
    count += 2;
    if(((HAL_GetTick() - tickstart ) > 0xFFFF) || (Status != HAL_OK))
    {
      ISM43362_DISABLE_NSS();
      return -1;
    }    
  }
  
  ISM43362_DISABLE_NSS();
  
  if((Prompt[0] != 0x15) ||(Prompt[1] != 0x15) ||(Prompt[2] != '\r')|| (Prompt[3] != '\n') ||(Prompt[4] != '>') ||(Prompt[5] != ' '))
  {
    return -1;
  }    
  return 0;
}

/**
* @brief  DeInitialize the SPI
* @param  None
* @retval None
*/
int8_t ISM43362_DeInit(ES_WIFIObject_t *Obj)
{
#if  WIFI_USE_CMSIS_OS
  osMutexDelete(spi_mutex);
  osMutexDelete(es_wifi_mutex);
  osSemaphoreDelete(spi_tx_sem);
  osSemaphoreDelete(spi_rx_sem);
  osSemaphoreDelete(cmddata_rdy_rising_sem);
#endif
  return 0;
}

/**
* @brief  Receive wifi Data from SPI
* @param  pdata : pointer to data
* @param  len : Data length
* @param  timeout : send timeout in mS
* @retval Length of received data (payload)
*/

int wait_cmddata_rdy_high(int timeout)
{
  int tickstart = HAL_GetTick();
  while (ISM43362_IS_CMDDATA_READY()==0)
  {
    if((HAL_GetTick() - tickstart ) > timeout)
    {
      return -1;
    }
  }
  return 0;
}

int wait_cmddata_rdy_rising_event(int timeout)
{
#ifdef SEM_WAIT
  return SEM_WAIT(cmddata_rdy_rising_sem, timeout);
#else
  int tickstart = HAL_GetTick();
  while (cmddata_rdy_rising_event==1)
  {
    if((HAL_GetTick() - tickstart ) > timeout)
    {
      return -1;
    }
  }
  return 0;
#endif
}

int wait_spi_rx_event(int timeout)
{
#ifdef SEM_WAIT
  return SEM_WAIT(spi_rx_sem, timeout);
#else
  int tickstart = HAL_GetTick();
  while (spi_rx_event==1)
  {
    if((HAL_GetTick() - tickstart ) > timeout)
    {
      return -1;
    }
  }
  return 0;
#endif
}

int wait_spi_tx_event(int timeout)
{
#ifdef SEM_WAIT
  return SEM_WAIT(spi_tx_sem, timeout);
#else
  int tickstart = HAL_GetTick();
  while (spi_tx_event==1)
  {
    if((HAL_GetTick() - tickstart ) > timeout)
    {
      return -1;
    }
  }
  return 0;
#endif
}

int16_t ISM43362_ReceiveData(ES_WIFIObject_t *Obj, uint8_t *pData, uint16_t len, uint32_t timeout)
{
  int16_t length = 0;
  uint8_t tmp[2];
  
  ISM43362_DISABLE_NSS();
  UNLOCK_SPI();
  ISM43362_DelayUs(3);
  
  
  if (wait_cmddata_rdy_rising_event(timeout)<0)
  {
    return ES_WIFI_ERROR_WAITING_DRDY_FALLING;
  }
  
  LOCK_SPI();
  ISM43362_ENABLE_NSS();
  ISM43362_DelayUs(15);
  
  while (ISM43362_IS_CMDDATA_READY())
  {
    if((length < len) || (!len))
    {
      spi_rx_event=1;
      
      if (SM43362_IO_Receive_IT(Obj->fops.hspi, tmp, 1) != HAL_OK)
      {
        ISM43362_DISABLE_NSS();
        UNLOCK_SPI();
        return ES_WIFI_ERROR_SPI_FAILED;
      }
      
      wait_spi_rx_event(timeout);
      
      pData[0] = tmp[0];
      pData[1] = tmp[1];
      length += 2;
      pData  += 2;
      
      if (length >= ES_WIFI_DATA_SIZE) 
      {
        ISM43362_DISABLE_NSS();
        ISM43362_ResetModule(Obj);
        UNLOCK_SPI();
        return ES_WIFI_ERROR_STUFFING_FOREVER;
      }
    }
    else
    {
      break;
    }
  }
  ISM43362_DISABLE_NSS();
  UNLOCK_SPI();
  return length;
}

/**
* @brief  Send wifi Data thru SPI
* @param  pdata : pointer to data
* @param  len : Data length
* @param  timeout : send timeout in mS
* @retval Length of sent data
*/
int16_t ISM43362_SendData(ES_WIFIObject_t *Obj, uint8_t *pdata,  uint16_t len, uint32_t timeout)
{
  uint8_t Padding[2];
  
  if (wait_cmddata_rdy_high(timeout)<0)
  {
    return ES_WIFI_ERROR_SPI_FAILED;
  }
  
  /* arm to detect rising event */
  cmddata_rdy_rising_event=1;
  
  LOCK_SPI();
  ISM43362_ENABLE_NSS();
  ISM43362_DelayUs(15);
  
  if (len > 1)
  {
    spi_tx_event=1;
    if( SM43362_IO_Transmit_IT(Obj->fops.hspi, (uint8_t *)pdata , len/2) != HAL_OK)
    {
      ISM43362_DISABLE_NSS();
      UNLOCK_SPI();
      return ES_WIFI_ERROR_SPI_FAILED;
    }
    wait_spi_tx_event(timeout);
  }
  
  if ( len & 1)
  {
    Padding[0] = pdata[len-1];
    Padding[1] = '\n';
    
    spi_tx_event=1;
    if( SM43362_IO_Transmit_IT(Obj->fops.hspi, Padding, 1) != HAL_OK)
    {
      ISM43362_DISABLE_NSS();
      UNLOCK_SPI();
      return ES_WIFI_ERROR_SPI_FAILED;
    }  
    wait_spi_tx_event(timeout);
    
  }
  return len;
}

/**
* @brief  Delay
* @param  Delay in ms
* @retval None
*/
void ISM43362_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}

/**
* @brief  Delay
* @param  Delay in us
* @retval None
*/
void ISM43362_DelayUs(uint32_t n)
{
  volatile        uint32_t ct = 0;
  uint32_t        loop_per_us = 0;
  static uint32_t cycle_per_loop = 0;
  
  /* calibration happen on first call for a duration of 1 ms * nbcycle per loop */
  /* 10 cycle for STM32L4 */
  if (cycle_per_loop == 0 ) 
  {
    uint32_t cycle_per_ms = (SystemCoreClock/1000UL);
    uint32_t t = 0;
    ct = cycle_per_ms;
    t = HAL_GetTick();
    while(ct) ct--;
    cycle_per_loop = HAL_GetTick()-t;
    if (cycle_per_loop == 0) cycle_per_loop = 1;
  }
  
  loop_per_us = SystemCoreClock/1000000UL/cycle_per_loop;
  ct = n * loop_per_us;
  while(ct) ct--;
  return;
}

/**
* @brief Rx Transfer completed callback.
* @param  hspi: pointer to a SPI_HandleTypeDef structure that contains
*               the configuration information for SPI module.
* @retval None
*/
void ISM43362_RxCpltCallback(void)
{
  if (spi_rx_event)
  {
    SEM_SIGNAL(spi_rx_sem);
    spi_rx_event = 0;
  }
}

/**
* @brief Tx Transfer completed callback.
* @param  hspi: pointer to a SPI_HandleTypeDef structure that contains
*               the configuration information for SPI module.
* @retval None
*/
void ISM43362_TxCpltCallback(void)
{
  if (spi_tx_event)
  {
    SEM_SIGNAL(spi_tx_sem);
    spi_tx_event = 0;
  }
}

/**
* @brief  Interrupt handler for  Data RDY signal
* @param  None
* @retval None
*/
void    ISM43362_DATA_READY_ISR(void)
{
  if (cmddata_rdy_rising_event==1)  
  {
    SEM_SIGNAL(cmddata_rdy_rising_sem);
    cmddata_rdy_rising_event = 0;
  }
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
