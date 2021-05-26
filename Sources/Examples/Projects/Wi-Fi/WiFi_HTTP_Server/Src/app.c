#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "wifi.h"
#include "app.h"
#include "led.h"
#include "button.h"
#include "temperature_sensor.h"
#include "humidity_sensor.h"
#include <stdio.h>

uint8_t http[1024];
uint8_t  IP_Addr[4];
int     LedState = 0; 

/****************************** HTS221 ****************************************/
#if defined(HTS221_BUS_TYPE_I2C)  
extern I2C_HandleTypeDef HTS221_I2C_HANDLER;
#endif
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
static int wifi_start(void)
{
  uint8_t  MAC_Addr[6];
  WIFI_Status_t err;
  
  err = WIFI_Init(); /*Initialize and use WIFI module */
  
  if(err !=  WIFI_STATUS_OK)
  {
    LOG("> ERROR : WIFI Module cannot be initialized.\n");
    return -1;
  }
  
  LOG("> WIFI Module Initialized.\n");

  err = WIFI_GetMAC_Address(MAC_Addr);
  
  if(err != WIFI_STATUS_OK)
  {
    LOG("> ERROR : CANNOT get MAC address\n");
  }

  LOG("> es-wifi module MAC Address : %X:%X:%X:%X:%X:%X\n", MAC_Addr[0], MAC_Addr[1], MAC_Addr[2], MAC_Addr[3], MAC_Addr[4], MAC_Addr[5]);
  
  return 0;
}

int wifi_connect(void)
{
  int err = 0;
  
  err = wifi_start();
  
  if(err)
  {
    LOG("Error Starting the Wi-Fi\r\n");
    return err;
  }
  
  LOG("\nConnecting to %s , %s\n",SSID,PASSWORD);
  
  err = WIFI_Connect(SSID, PASSWORD, WIFI_ECN_WPA2_PSK);

  if(err  != WIFI_STATUS_OK)
  {
    LOG("ERROR : Wi-Fi module NOT connected\n");
    return -1;
  }
  
  err = WIFI_GetIP_Address(IP_Addr);
  
  if(err != WIFI_STATUS_OK)
  {
    LOG(" ERROR : Wi-Fi module CANNOT get IP address\n");
    return -1;
  }

  LOG("> Wi-Fi module connected: got IP Address : %d.%d.%d.%d\n", IP_Addr[0], IP_Addr[1], IP_Addr[2], IP_Addr[3]);

  return 0;
}

int wifi_server(void)
{
  bool StopServer = false;

  TMP_Obj.IO.BusType      = HTS221_I2C_BUS;
  TMP_Obj.IO.Address      = HTS221_I2C_ADDRESS;
  TMP_Obj.IO.hi2c         = &HTS221_I2C_HANDLER;
  TMP_Obj.is_initialized  = 0;
  TMP_Obj.hum_is_enabled  = 0;
  TMP_Obj.temp_is_enabled = 0; 

  TEMPERATURE_SENSOR_Init  (&TMP_Obj);
  TEMPERATURE_SENSOR_Enable(&TMP_Obj);
  TEMPERATURE_SENSOR_ReadID(&TMP_Obj, &TMP_Id);

  HUM_Obj.is_initialized  = 0;
  HUM_Obj.hum_is_enabled  = 0;
  HUM_Obj.temp_is_enabled = 0;  

  HUMIDITY_SENSOR_Init  (&HUM_Obj);
  HUMIDITY_SENSOR_Enable(&HUM_Obj);
  HUMIDITY_SENSOR_ReadID(&HUM_Obj, &HUM_Id);
  
  LOG("\nRunning HTML Server test\n");
  
  if (wifi_connect()!=0) 
  {
    return -1;
  }
  
  if (WIFI_STATUS_OK != WIFI_StartServer(SOCKET, WIFI_TCP_PROTOCOL, 1, "", PORT))
  {
    LOG("ERROR: Cannot start server.\n");
  }
  
  LOG("Server is running and waiting for an HTTP  Client connection to %d.%d.%d.%d\n",IP_Addr[0],IP_Addr[1],IP_Addr[2],IP_Addr[3]);
    
  do
  {
    uint8_t RemoteIP[4];
    uint16_t RemotePort;
    
    
    while (WIFI_STATUS_OK != WIFI_WaitServerConnection(SOCKET,1000,RemoteIP,&RemotePort))
    {
      LOG("Waiting connection to  %d.%d.%d.%d\n",IP_Addr[0],IP_Addr[1],IP_Addr[2],IP_Addr[3]);
      BSP_LED_Toggle(LED_WIFI_ACTIVITY);
    }
    
    LOG("Client connected %d.%d.%d.%d:%d\n",RemoteIP[0],RemoteIP[1],RemoteIP[2],RemoteIP[3],RemotePort);
    
    StopServer = WebServerProcess();
    
    if(WIFI_CloseServerConnection(SOCKET) != WIFI_STATUS_OK)
    {
      LOG("ERROR: failed to close current Server connection\n");
      return -1;
    }
  }
  
  while(StopServer == false);
  
  if (WIFI_STATUS_OK!=WIFI_StopServer(SOCKET))
  {
    LOG("ERROR: Cannot stop server.\n");
  }
  
  LOG("Server is stop\n");
  return 0;
}

static bool WebServerProcess(void)
{
  uint8_t  temp;
  uint8_t  hum;
  uint16_t respLen;
  static   uint8_t resp[1024];
  bool     stopserver = false;
  float    fTemp;
  float    fHum;
  
  if (WIFI_STATUS_OK == WIFI_ReceiveData(SOCKET, resp, 1000, &respLen, WIFI_READ_TIMEOUT))
  {
    LOG("get %d byte from server\n",respLen);
      
    if( respLen > 0)
    {
      if(strstr((char *)resp, "POST"))/* POST: received info */
      {
        LOG("Post request\n");
        
        if(strstr((char *)resp, "radio"))
        {
          if(strstr((char *)resp, "radio=0"))
          {
            LedState = 0;
            BSP_LED_Off(LED2);
          }
          else if(strstr((char *)resp, "radio=1"))
          {
            LedState = 1;
            BSP_LED_On(LED2);
          }
        }
        
        if(strstr((char *)resp, "stop_server"))
        {
          if(strstr((char *)resp, "stop_server = 0"))
          {
            stopserver = false;
          }
          else if(strstr((char *)resp, "stop_server=1"))
          {
            stopserver = true;
          }
        }
      }

      TEMPERATURE_SENSOR_GetTemperature(&TMP_Obj, &fTemp);
      temp = (int)fTemp;
      
      HUMIDITY_SENSOR_GetHumidity(&HUM_Obj, &fHum);
      hum = (int)fHum;
      hum = hum; /* To keep the compiler happy */
      
      if(SendWebPage(LedState, temp) != WIFI_STATUS_OK)
      {
        LOG("> ERROR : Cannot send web page\n");
      }
      else
      {
        LOG("Send page after  GET command\n");
      }
    }
  }
  else
  {
    LOG("Client close connection\n");
  }
  
  return stopserver;
  
}

/**
* @brief  Send HTML page
* @param  None
* @retval None
*/
static WIFI_Status_t SendWebPage(uint8_t ledIsOn, uint8_t temperature)
{
  uint8_t  temp[50];
  uint16_t SentDataLength;
  WIFI_Status_t ret;
  
  /* construct web page content */
  strcpy ((char *)http, (char *)"HTTP/1.0 200 OK\r\nContent-Type: text/html\r\nPragma: no-cache\r\n\r\n");
  strcat ((char *)http, (char *)"<html>\r\n<body>\r\n");
  strcat ((char *)http, (char *)"<title>STM32 Web Server</title>\r\n");
  strcat ((char *)http, (char *)"<h2>InventekSys : Web Server using Es-Wifi with STM32</h2>\r\n");
  strcat ((char *)http, (char *)"<br /><hr>\r\n");
  strcat ((char *)http, (char *)"<p><form method=\"POST\"><strong>Temp: <input type=\"text\" value=\"");
  sprintf((char *)temp, "%d", temperature);
  strcat ((char *)http, (char *)temp);
  strcat ((char *)http, (char *)"\"> <sup>O</sup>C");
  
  if (ledIsOn)
  {
    strcat((char *)http, (char *)"<p><input type=\"radio\" name=\"radio\" value=\"0\" >LED off");
    strcat((char *)http, (char *)"<br><input type=\"radio\" name=\"radio\" value=\"1\" checked>LED on");
  }
  else
  {
    strcat((char *)http, (char *)"<p><input type=\"radio\" name=\"radio\" value=\"0\" checked>LED off");
    strcat((char *)http, (char *)"<br><input type=\"radio\" name=\"radio\" value=\"1\" >LED on");
  }
  
  strcat((char *)http, (char *)"</strong><p><input type=\"submit\"></form></span>");
  strcat((char *)http, (char *)"</body>\r\n</html>\r\n");
  
  ret = WIFI_SendData(0, (uint8_t *)http, strlen((char *)http), &SentDataLength, WIFI_WRITE_TIMEOUT);
  
  if((ret == WIFI_STATUS_OK) && (SentDataLength != strlen((char *)http)))
  {
    ret = WIFI_STATUS_ERROR;
  }
  
  return ret;
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
