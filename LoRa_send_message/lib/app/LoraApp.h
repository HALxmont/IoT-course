#ifndef LORAAPP_H_
#define LORAAPP_H_
#include"stm32f1xx.h"

#define M1_LOW()                               HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, RESET);
#define M0_LOW()                               HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, RESET);
#define M1_HIGH()                              HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, SET);
#define M0_HIGH()                              HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, SET);
#define LRBuffSize 256
#define MainLoopDly   10000
#define LoRaTxBufferSize 36
#define DSTADDR           0x01
#define SRCADDR           0x00
#define CHANNEL           0x01


uint8_t *txbufferLoRa;

void LoRaSendInfo(void);
void LoRaSendMessage(uint8_t dst_add, uint8_t channel, char *LoraMessage);
void LoRa_send_string(UART_HandleTypeDef *huart, char* s);
#endif