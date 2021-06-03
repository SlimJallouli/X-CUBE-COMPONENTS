/**
  ******************************************************************************
  * @file           : app.c
  * @brief          : Main application header
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#define SSID     "SSID"
#define PASSWORD "PSWD"

#define RemoteIP_0 192
#define RemoteIP_1 168
#define RemoteIP_2 1
#define RemoteIP_3 211

#define PORT	               8080

#define WIFI_WRITE_TIMEOUT     10000
#define WIFI_READ_TIMEOUT      0

#define CONNECTION_TRIAL_MAX   10

#define MAX_DATA_SIZE          512

int App_Init(void);
int App_Run(void);