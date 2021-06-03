#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "wifi.h"

#define SSID     "JSEC_2.4"
#define PASSWORD "$limEmn@"

#define WIFI_WRITE_TIMEOUT 10000
#define WIFI_READ_TIMEOUT  10000
#define SOCKET             0
#define PORT               80

#define APP_DEBUG 1

#if  APP_DEBUG
#define LOG printf
#else
#define LOG(x, ...)
#endif

int wifi_start(void);
int wifi_connect(void);
int wifi_server(void);
bool WebServerProcess(void);
WIFI_Status_t SendWebPage(uint8_t ledIsOn, uint8_t temperature);


