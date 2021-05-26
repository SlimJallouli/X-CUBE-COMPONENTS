

#define SSID     "JSEC_2.4"
#define PASSWORD "SlimEmn@!"

#define RemoteIP_0 192
#define RemoteIP_1 168
#define RemoteIP_2 1
#define RemoteIP_3 4

#define PORT	               8080

#define WIFI_WRITE_TIMEOUT     10000
#define WIFI_READ_TIMEOUT      0

#define CONNECTION_TRIAL_MAX   10

#define MAX_DATA_SIZE          512

#define APP_DEBUG 1

#if  (APP_DEBUG == 1)
#define LOG printf
#else
#define LOG //
#endif

int App_Init(void);
int App_Run(void);