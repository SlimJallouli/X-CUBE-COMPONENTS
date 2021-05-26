#include "main.h"
#include <stdio.h>

#define APP_DEBUG

#ifdef  APP_DEBUG
#define LOG printf
#else
#define LOG //
#endif

int App_Init(void);
int App_Run(void);