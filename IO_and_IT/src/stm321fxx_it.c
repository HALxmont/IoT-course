
#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#include "HardwareInit.h"
#include "defs.h"


void EXTI9_IRQHandler(void) // <----- The ISR Function We're Looking For!
{
  if (__HAL_GPIO_EXTI_GET_IT((uint16_t)DIN1_Pin) != 0x00u)
  {
      //INTERRUPT CODE WAS HERE
    __HAL_GPIO_EXTI_CLEAR_IT(DIN1_Pin); // Clears The Interrupt Flag
  }

    if (__HAL_GPIO_EXTI_GET_IT((uint16_t) SW3_Pin) != 0x00u)  //LINK SW3 to this interrupt
  {
    Led1_Toggle();    //TOGGLE LED 1 WHEN SW3 IS PRESS
    HAL_Delay(100);
    __HAL_GPIO_EXTI_CLEAR_IT(SW3_Pin); // Clears The Interrupt Flag
  }
}

void EXTI9_5_IRQHandler(void)
{

  if (__HAL_GPIO_EXTI_GET_IT((uint16_t) SW2_Pin) != 0x00u)
  {
   DIO3_Toggle();
   Led1_Toggle();
    __HAL_GPIO_EXTI_CLEAR_IT(SW2_Pin); // Clears The Interrupt Flag
  }

  if (__HAL_GPIO_EXTI_GET_IT((uint16_t)DIN2_Pin) != 0x00u)
  {
   //INTERRUPT CODE WAS HERE
    __HAL_GPIO_EXTI_CLEAR_IT(DIN2_Pin); // Clears The Interrupt Flag
  }

  //   if (__HAL_GPIO_EXTI_GET_IT((uint16_t) SW3_Pin) != 0x00u)  //LINK SW3 to this interrupt
  // {
  //   Led1_Toggle();    //TOGGLE LED 1 WHEN SW3 IS PRESS
  //   __HAL_GPIO_EXTI_CLEAR_IT(SW3_Pin); // Clears The Interrupt Flag
  // }

}

void EXTI15_IRQHandler(void) // <----- The ISR Function We're Looking For!
{

  if (__HAL_GPIO_EXTI_GET_IT((uint16_t) SW3_Pin) != 0x00u)  //LINK SW3 to this interrupt
  {
    //Led1_Toggle();    //TOGGLE LED 1 WHEN SW3 IS PRESS
    __HAL_GPIO_EXTI_CLEAR_IT(SW3_Pin); // Clears The Interrupt Flag
  }

  if (__HAL_GPIO_EXTI_GET_IT((uint16_t)DIN3_Pin) != 0x00u)
  {
    //INTERRUPT CODE WAS HERE
    
    __HAL_GPIO_EXTI_CLEAR_IT(DIN3_Pin); // Clears The Interrupt Flag
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

