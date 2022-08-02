#include <stdlib.h>
#include <string.h>
#include "LoraApp.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"
#include "HardwareInit.h"
#include "fatfs.h"
#include "UI.h"
#include "defs.h"
#include "LoraApp.h"
#include <stdio.h>


char        LoRaRxBuff[LRBuffSize];
uint8_t     LoRaTxBuff[LoRaTxBufferSize];
char LoraMessage[250];

extern uint8_t UTC_Day;
extern uint8_t UTC_Mon;
extern uint8_t UTC_Year;

extern uint8_t UTC_Hour;
extern uint8_t UTC_Min;
extern uint8_t UTC_Sec;
extern uint8_t v1;
extern uint8_t v2;



extern UART_HandleTypeDef huart3;




void LoRaSendInfo(void){


    sprintf(LoraMessage, "LoRa INFO: %d/%d/%d %d:%d:%d, %d, %d \r\n", UTC_Day, UTC_Mon, UTC_Year, UTC_Hour, UTC_Min, UTC_Sec, v1, v2);
    HAL_UART_Transmit(&huart3, (uint8_t *)LoraMessage, strlen(LoraMessage), 0x800);   

    }

//HAL_UART_Transmit(&huart3, buff, strlen(buff), 100);

void LoRaSendMessage(uint8_t dst_add, uint8_t channel, char *LoraMessage){

    uint8_t parameter_config[] = {0x00, dst_add, channel};
    
    //HAL_UART_Transmit(&huart3, parameter_config, sizeof(parameter_config), 0x800);
    HAL_UART_Transmit(&huart3, (uint8_t *)LoraMessage, strlen(LoraMessage), 0x800);   

    }


void LoRa_send_string(UART_HandleTypeDef *huart, char* s){
	HAL_UART_Transmit(huart, (uint8_t*)s, strlen(s), 1000);
}
