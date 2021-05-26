
#ifndef _BAROMETER_SENSORS_H_
#define _BAROMETER_SENSORS_H_

#include "lps22hb.h"

#define BAROMETER_Object_t                  LPS22HB_Object_t
#define BAROMETERCapabilities_t             LPS22HB_Capabilities_t

#define BAROMETER_Init                      LPS22HB_Init
#define BAROMETER_DeInit                    LPS22HB_DeInit
#define BAROMETER_ReadID                    LPS22HB_ReadID
#define BAROMETER_GetCapabilities           LPS22HB_GetCapabilities
#define BAROMETER_Get_Init_Status           LPS22HB_Get_Init_Status

#define BAROMETER_PRESS_Enable              LPS22HB_PRESS_Enable
#define BAROMETER_PRESS_Disable             LPS22HB_PRESS_Disable
#define BAROMETER_PRESS_GetOutputDataRate   LPS22HB_PRESS_GetOutputDataRate
#define BAROMETER_PRESS_SetOutputDataRate   LPS22HB_PRESS_SetOutputDataRate
#define BAROMETER_PRESS_GetPressure         LPS22HB_PRESS_GetPressure
#define BAROMETER_PRESS_Get_DRDY_Status     LPS22HB_PRESS_Get_DRDY_Status
#define BAROMETER_PRESS_Get_FThStatus       LPS22HB_PRESS_Get_FThStatus

#define BAROMETER_TEMP_Enable               LPS22HB_TEMP_Enable
#define BAROMETER_TEMP_Disable              LPS22HB_TEMP_Disable
#define BAROMETER_TEMP_GetOutputDataRate    LPS22HB_TEMP_GetOutputDataRate
#define BAROMETER_TEMP_SetOutputDataRate    LPS22HB_TEMP_SetOutputDataRate
#define BAROMETER_TEMP_GetTemperature       LPS22HB_TEMP_GetTemperature
#define BAROMETER_TEMP_Get_DRDY_Status      LPS22HB_TEMP_Get_DRDY_Status

#define BAROMETER_FIFO_Get_Data             LPS22HB_FIFO_Get_Data
#define BAROMETER_FIFO_Get_FTh_Status       LPS22HB_FIFO_Get_FTh_Status
#define BAROMETER_FIFO_Get_Full_Status      LPS22HB_FIFO_Get_Full_Status
#define BAROMETER_FIFO_Get_Level            LPS22HB_FIFO_Get_Level
#define BAROMETER_FIFO_Get_Ovr_Status       LPS22HB_FIFO_Get_Ovr_Status
#define BAROMETER_FIFO_Reset_Interrupt      LPS22HB_FIFO_Reset_Interrupt
#define BAROMETER_FIFO_Set_Interrupt        LPS22HB_FIFO_Set_Interrupt
#define BAROMETER_FIFO_Set_Mode             LPS22HB_FIFO_Set_Mode
#define BAROMETER_FIFO_Set_Watermark_Level  LPS22HB_FIFO_Set_Watermark_Level
#define BAROMETER_FIFO_Usage                LPS22HB_FIFO_Usage

#define BAROMETER_Get_Press                 LPS22HB_Get_Press
#define BAROMETER_Get_Temp                  LPS22HB_Get_Temp

#define BAROMETER_Set_One_Shot              LPS22HB_Set_One_Shot
#define BAROMETER_Get_One_Shot_Status       LPS22HB_Get_One_Shot_Status

#endif