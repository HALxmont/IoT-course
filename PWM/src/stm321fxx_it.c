
#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#include "HardwareInit.h"
#include "defs.h"
#include "fatfs.h"
#include "ff.h"

extern UART_HandleTypeDef huart1;
extern ADC_HandleTypeDef hadc1;






void SysTick_Handler(void)
{
  HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

