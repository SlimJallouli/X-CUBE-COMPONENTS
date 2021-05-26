#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"
#include "wifi.h"
#include "app.h"
#include "led.h"
#include "button.h"

uint8_t RemoteIP[] = {RemoteIP_0,RemoteIP_1,RemoteIP_2,RemoteIP_3};

static uint8_t TxData[MAX_DATA_SIZE] = "STM32 : Hello!\n";
static uint8_t RxData[MAX_DATA_SIZE];

int32_t Socket = -1;
uint16_t Datalen;

static size_t string_parser( const char *input, char ***word_array) ;

int App_Init(void)
{
  WIFI_Status_t err = WIFI_STATUS_OK;
  int16_t Trials = CONNECTION_TRIAL_MAX;
  uint8_t  MAC_Addr[6];
  uint8_t  IP_Addr[4];
  uint16_t local_port = 0;
  
  LOG("****** WIFI Module in TCP Client mode demonstration ****** \n\n");
  LOG("TCP Client Instructions :\n");
  LOG("1- Make sure your Phone is connected to the same network that\n");
  LOG("   you configured using the Configuration Access Point.\n");
  LOG("2- Create a server by using the android application TCP Server\n");
  LOG("   with port(8002).\n");
  LOG("3- Get the Network Name or IP Address of your Android from the step 2.\n\n");
  
  /*Initialize  WIFI module */
  err = WIFI_Init();
  
  if(err !=  WIFI_STATUS_OK)
  {
    LOG("> ERROR : WIFI Module cannot be initialized.\n");
    BSP_LED_On(LED2);
    return -1;
  }
  
  LOG("> WIFI Module Initialized.\n");
  
  err = WIFI_GetMAC_Address(MAC_Addr);
  
  if(err != WIFI_STATUS_OK)
  {
    LOG("> ERROR : CANNOT get MAC address\n");
    BSP_LED_On(LED2);
  }
  
  LOG("> Wi-Fi module MAC Address : %X:%X:%X:%X:%X:%X\n", MAC_Addr[0], MAC_Addr[1], MAC_Addr[2], MAC_Addr[3], MAC_Addr[4], MAC_Addr[5]);
  
  err = WIFI_Connect(SSID, PASSWORD, WIFI_ECN_WPA2_PSK);
  
  if( err != WIFI_STATUS_OK)
  {
    LOG("> ERROR : Wi-Fi module NOT connected\n");
    BSP_LED_On(LED2);
    return -1;
  }
  
  LOG("> Wi-Fi module connected \n");
  
  err = WIFI_GetIP_Address(IP_Addr);
  
  if(err != WIFI_STATUS_OK)
  {
    LOG("> ERROR : Wi-Fi module CANNOT get IP address\n");
    BSP_LED_On(LED2);
    return -1;
  }
  
  LOG("> Wi-Fi module got IP Address : %d.%d.%d.%d\n", IP_Addr[0], IP_Addr[1], IP_Addr[2], IP_Addr[3]);
  LOG("> Trying to connect to Server   : %d.%d.%d.%d:%d\n", RemoteIP[0], RemoteIP[1], RemoteIP[2], RemoteIP[3], PORT);
  
  while (Trials--)
  {
    err = WIFI_OpenClientConnection(0, WIFI_TCP_PROTOCOL, "TCP_CLIENT", RemoteIP, PORT, local_port++) ;
    
    HAL_Delay(1000);
    
    BSP_LED_Toggle(LED_WIFI_ACTIVITY);
    
    if(err == WIFI_STATUS_OK)
    {
      LOG("> TCP Connection opened successfully.\n");
      Socket = 0;
      break;
    }
  }
  
  if(Socket == -1)
  {
    LOG("> ERROR : Cannot open Connection\n");
    BSP_LED_On(LED2);
    return -1;
  }

  sprintf((char *)TxData,"%s", "STM32 : Hello!\n");
  
  err = WIFI_SendData(Socket, TxData, sizeof(TxData), &Datalen, WIFI_WRITE_TIMEOUT);
  
  if (err != WIFI_STATUS_OK)
  {
    LOG("> ERROR : Failed to Send Data, connection closed\n");
    return -1;
  }
  
  return 0;
}

int App_Run(void)
{
  WIFI_Status_t err = WIFI_STATUS_OK;
  
  static GPIO_PinState BUTTON_State_Saved = GPIO_PIN_SET;
  static GPIO_PinState BUTTON_State       = GPIO_PIN_SET;
  char ** word_array = NULL;
  size_t n;
  
  if(Socket != -1)
  {
    err = WIFI_ReceiveData(Socket, RxData, sizeof(RxData)-1, &Datalen, WIFI_READ_TIMEOUT);
    
    if(err == WIFI_STATUS_OK)
    {
      if(Datalen > 0)
      {
        RxData[Datalen] = 0;
        
        LOG("Received: %s\n",RxData);
        
        n = string_parser( (const char *)RxData, &word_array );
        
        for(int i = 0; i<n; i++)
        {
          LOG("%s\r\n", word_array[i]);
        }
        
//        sprintf((char *)TxData,"%s", "STM32 : Hello!\n");
//        err = WIFI_SendData(Socket, TxData, sizeof(TxData), &Datalen, WIFI_WRITE_TIMEOUT);
        
        if(strstr((char *)RxData, "LED_On"))
        {
          BSP_LED_On(LED2);
        }
        else if(strstr((char *)RxData, "LED_Off"))
        {
          BSP_LED_Off(LED2);
        }
        
        free( word_array );
        
        if (err != WIFI_STATUS_OK)
        {
          LOG("> ERROR : Failed to Send Data, connection closed\n");
          return -1;
        }
      }
    }
    else
    {
      LOG("> ERROR : Failed to Receive Data, connection closed\n");
      return -1;
    }

    BUTTON_State = BSP_PB_GetState(BUTTON);
    
    if(BUTTON_State_Saved != BUTTON_State)
    {
      BUTTON_State_Saved = BUTTON_State;
      
      if(BUTTON_State == GPIO_PIN_RESET)
      {
        sprintf((char *)TxData,"%s", "Button pressed\n");
        
        err = WIFI_SendData(Socket, TxData, sizeof(TxData), &Datalen, WIFI_WRITE_TIMEOUT);
        
        if (err != WIFI_STATUS_OK)
        {
          LOG("> ERROR : Failed to Send Data, connection closed\n");
          return -1;
        }
      }
    }
  }
  
  return 0;  
}

/**
* @brief  EXTI line detection callback.
* @param  GPIO_Pin: Specifies the port pin connected to corresponding EXTI line.
* @retval None
*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch (GPIO_Pin)
  {
  case (WIFI_DATA_READY_Pin):
    {
      WIFI_DATA_READY_ISR();
      break;
    }
  default:
    {
      break;
    }
  }
}

/**
  * @brief Rx Transfer completed callback.
  * @param  hspi: pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval None
  */
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
  WIFI_RxCpltCallback();
}

/**
  * @brief Tx Transfer completed callback.
  * @param  hspi: pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval None
  */
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
  WIFI_TxCpltCallback();
}

size_t string_parser( const char *input, char ***word_array) 
{
  size_t n = 0;
  const char *p = input;
  
  while ( *p )
  {
    while ( isspace( ( unsigned char )*p ) ) ++p;
    n += *p != '\0';
    while ( *p && !isspace( ( unsigned char )*p ) ) ++p;
  }
  
  if ( n )
  {
    size_t i = 0;
    
    *word_array = malloc( n * sizeof( char * ) ); 
    
    p = input;
    
    while ( *p )
    {
      while ( isspace( ( unsigned char )*p ) ) ++p;
      if ( *p )
      {
        const char *q = p;
        while ( *p && !isspace( ( unsigned char )*p ) ) ++p;
        
        size_t length = p - q;
        
        ( *word_array )[i] = ( char * )malloc( length + 1 );
        
        strncpy( ( *word_array )[i], q, length );
        ( *word_array )[i][length] = '\0';
        
        ++i;
      }
    }           
  }
  
  return n;
} 