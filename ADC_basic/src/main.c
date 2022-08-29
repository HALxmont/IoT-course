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
extern ADC_HandleTypeDef hadc1;

uint16_t raw_data;
float voltage;

int main(void)
{

  SystemClock_Config();
  HardwareInit();

//ADC_Enable(&hadc1);

HAL_ADC_Start(&hadc1); //adc start

myprintf("Welcome to the basic ADC DEMO example \r\n", 1);



  while (1){

    	  HAL_ADC_PollForConversion(&hadc1, 100); //convertimos (100ms de conversion)
	      raw_data = HAL_ADC_GetValue(&hadc1); //leemos el valor convertido
        myprintf("ADC RAW VALUE: %d\r\n", raw_data); //enviamos por serial el dato RAW

        voltage = (3.3 * raw_data) / 4096; 

        myprintf("VOLTAGE VALUE: %f\r\n", voltage); //enviamos por serial el dato convertido a voltaje


      


  }
}















