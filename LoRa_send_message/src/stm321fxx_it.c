
#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#include "HardwareInit.h"
#include "UI.h"
#include "defs.h"
#include "LoraApp.h"


extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef dma1;

extern UART_HandleTypeDef huart3;
extern DMA_HandleTypeDef dma3;

extern uint8_t   UI_Buffer[UI_Buff_Size];
extern char      LoRaRxBuff[LRBuffSize];


//######################################
//##### UART1 INTERRUPT
//######################################

void USART1_IRQHandler(void)
{
  uint8_t data_length = 0;
  char str[20];

  static uint8_t i = 0;
  if (RESET != __HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE))
  {
    __HAL_UART_CLEAR_FLAG(&huart1, UART_FLAG_RXNE);
  }

  if (RESET != __HAL_UART_GET_FLAG(&huart1, UART_FLAG_IDLE))
  {
    __HAL_UART_CLEAR_IDLEFLAG(&huart1);
    HAL_UART_DMAStop(&huart1);
    data_length = UI_Buff_Size - __HAL_DMA_GET_COUNTER(&dma1);
    UI_SetParams();
    HAL_UART_Receive_DMA(&huart1, UI_Buffer, UI_Buff_Size);
    
  }
}

//######################################
//##### UART3 INTERRUPT
//######################################
void USART3_IRQHandler(void)
{
  uint8_t data_length = 0;

  if (RESET != __HAL_UART_GET_FLAG(&huart3, UART_FLAG_RXNE))
  {
    __HAL_UART_CLEAR_FLAG(&huart3, UART_FLAG_RXNE);
  }

  if (RESET != __HAL_UART_GET_FLAG(&huart3, UART_FLAG_IDLE))
  {
    HAL_UART_DMAStop(&huart3);
    data_length = LRBuffSize - __HAL_DMA_GET_COUNTER(&dma3);
    LoRaRxBuff[data_length + 1] = 0;
    HAL_UART_Receive_DMA(&huart3, LoRaRxBuff, LRBuffSize);
    __HAL_UART_CLEAR_IDLEFLAG(&huart3);
  }
}

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

