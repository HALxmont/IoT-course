#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "stm32f1xx_hal.h"
#include "HardwareInit.h"
#include "defs.h"
#include "stm32f1xx.h"


int main(void)
{
  SystemClock_Config();
  HardwareInit();
  while (1){
    //big loop
    DIO5_ON();
   // Led1_Toggle()
    HAL_Delay(500); //wait 100ms
    DIO5_OFF();
   // Led1_Toggle()
    HAL_Delay(500); //wait 100ms
  }
}








