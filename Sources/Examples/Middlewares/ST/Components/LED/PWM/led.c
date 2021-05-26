#include "led.h"
#include "math.h"
#include "STMicroelectronics.X-CUBE-COMPONENTS_conf.h"

extern TIM_HandleTypeDef LED_TIM_HANDLER;

#define PWM_TABLE_SIZE 1024
static uint32_t PWM_Pulse[PWM_TABLE_SIZE];
static uint32_t PWM_Value = 0;
static uint16_t current_luminosity = 0;

#if (LED_TIM_CHANNEL == TIM_CHANNEL_1)
  #define TIM_CCRx CCR1
#elif (LED_TIM_CHANNEL == TIM_CHANNEL_2)
  #define TIM_CCRx CCR2
#elif (LED_TIM_CHANNEL == TIM_CHANNEL_3)
  #define TIM_CCRx CCR3
#elif (LED_TIM_CHANNEL == TIM_CHANNEL_4)
  #define TIM_CCRx CCR4
#endif

void BSP_LED_Init(Led_TypeDef LED)
{
  for(uint32_t i = 0; i < PWM_TABLE_SIZE-1; i++) /* Generate sine table */
  {
    float SinValue = 1 + cos((i *4 * 3.14)/(float)(PWM_TABLE_SIZE-1));
    PWM_Pulse[i] = (uint32_t)((LED_TIM_HANDLER.Init.Period) * (SinValue/2));
  }
}

void BSP_LED_On(Led_TypeDef LED)
{
  BSP_LED_SetLuminosity(LED, 100);
}

void BSP_LED_Off(Led_TypeDef LED)
{
  BSP_LED_SetLuminosity(LED, 0);
}

void BSP_LED_Toggle(Led_TypeDef LED)
{
  BSP_LED_SetLuminosity(LED, 100 - current_luminosity);
}

void BSP_LED_Write(Led_TypeDef LED, GPIO_PinState PinState)
{
  BSP_LED_SetLuminosity(LED, PinState == GPIO_PIN_SET? 100:0);
}

void BSP_LED_Fade(Led_TypeDef LED)
{
  HAL_TIM_PWM_Stop_DMA (&LED_TIM_HANDLER, LED_TIM_CHANNEL);
  HAL_TIM_PWM_Start_DMA(&LED_TIM_HANDLER, LED_TIM_CHANNEL, (uint32_t *)PWM_Pulse, PWM_TABLE_SIZE); /* Start Timer in PWM mode. Update with DMA */
}

void BSP_LED_SetLuminosity(Led_TypeDef LED, uint16_t luminosity)
{
  if(luminosity > 100)
  {
    luminosity = 100;
  }
  
  current_luminosity = luminosity;
  
  PWM_Value = (LED_TIM_HANDLER.Init.Period * luminosity)/100;
    
  HAL_TIM_PWM_Stop_DMA (&LED_TIM_HANDLER, LED_TIM_CHANNEL);
  LED_TIM_HANDLER.Instance->TIM_CCRx = PWM_Value;
  HAL_TIM_PWM_Start(&LED_TIM_HANDLER, LED_TIM_CHANNEL);
}