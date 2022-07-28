#include "HardwareInit.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "UI.h"
#include "defs.h"
#include "LoraApp.h"

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;
DMA_HandleTypeDef dma1;
DMA_HandleTypeDef dma3;


extern char UI_Buffer[UI_Buff_Size];
extern char LoRaRxBuff[LRBuffSize];


void HardwareInit()
{
  HAL_Init();
  Gpio_Init();
  Uart_init();
}

void Gpio_Init(void)
{

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_USART1_CLK_ENABLE(); // UI UART
  __HAL_RCC_USART3_CLK_ENABLE(); // Lora Uart

  GPIO_InitTypeDef GPIO_InitStruct;

  /*                        UART On  microUSB port                     */

  /*------------------UART 1 Pins Configuration begins -----------------------------*/

  GPIO_InitStruct.Pin = TX_Local_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(TX_Local_Port, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RX_Local_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_INPUT;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RX_Port, &GPIO_InitStruct);


  /*------------------UART 3 Pins Configuration begins -----------------------------*/
  // LORA

  GPIO_InitStruct.Pin = GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  
  // SDA1 - RX - USART3
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_INPUT;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

void Uart_init(void)
{

 //UI 
  __HAL_RCC_DMA1_CLK_ENABLE();
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;

//LORA
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 9600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;

  
  if (HAL_UART_Init(&huart1) != HAL_OK)
    asm("bkpt 255");
  if (HAL_UART_Init(&huart3) != HAL_OK)
    asm("bkpt 255");

  HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART1_IRQn);

  __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
  __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);


  dma1.Instance = DMA1_Channel5;
  dma1.Init.Direction = DMA_PERIPH_TO_MEMORY;
  dma1.Init.PeriphInc = DMA_PINC_DISABLE;
  dma1.Init.MemInc = DMA_MINC_ENABLE;
  dma1.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
  dma1.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
  dma1.Init.Mode = DMA_NORMAL;
  dma1.Init.Priority = DMA_PRIORITY_HIGH;
  HAL_DMA_Init(&dma1);
  __HAL_LINKDMA(&huart1, hdmarx, dma1);
  __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
  HAL_UART_Receive_DMA(&huart1, UI_Buffer, UI_Buff_Size); //link UI buffer to DMA1


  dma3.Instance = DMA1_Channel3;
  dma3.Init.Direction = DMA_PERIPH_TO_MEMORY;
  dma3.Init.PeriphInc = DMA_PINC_DISABLE;
  dma3.Init.MemInc = DMA_MINC_ENABLE;
  dma3.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
  dma3.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
  dma3.Init.Mode = DMA_NORMAL;
  dma3.Init.Priority = DMA_PRIORITY_HIGH;
  HAL_DMA_Init(&dma3);
  __HAL_LINKDMA(&huart3, hdmarx, dma3);
  __HAL_UART_ENABLE_IT(&huart3, UART_IT_IDLE);
  HAL_UART_Receive_DMA(&huart3, LoRaRxBuff, LRBuffSize);

  HAL_NVIC_SetPriority(USART3_IRQn, 4, 5);
  HAL_NVIC_EnableIRQ(USART3_IRQn);
  __HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);

  /*------------------UART  Configuration ends -------------------------------*/
}

void myprintf(const char *fmt, ...)
{
  static char buffer[256];
  __va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);

  int len = strlen(buffer);
  HAL_UART_Transmit(&huart1, (uint8_t *)buffer, len, -1);
}



void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef rccPeriphCLKInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
      in the RCC_OscInitTypeDef structure.*/
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSI; // HSE and LSI oscilator
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON; // rtc clock source enable
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /** Initializes the CPU, AHB and APB buses clocks */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

  __HAL_RCC_ADC1_CLK_ENABLE();

  rccPeriphCLKInit.PeriphClockSelection = RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_RTC;
  rccPeriphCLKInit.AdcClockSelection = RCC_ADCPCLK2_DIV4;

  rccPeriphCLKInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI; // RTC clock source

  HAL_RCCEx_PeriphCLKConfig(&rccPeriphCLKInit);
}
