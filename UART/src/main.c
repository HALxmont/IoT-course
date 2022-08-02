#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "stm32f1xx_hal.h"
#include "HardwareInit.h"
#include "main.h"
#include "UI.h"
#include "defs.h"
#include "stm32f1xx.h"

extern UART_HandleTypeDef huart1;

int main(void)
{
  SystemClock_Config();
  HardwareInit();

myprintf("Hi I am %s\r\n", MNAME);
myprintf("Welcome to the UART DEMO example %s\r\n", MNAME);


  while (1){
  }
}








