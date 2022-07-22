
/*!
 *  \brief     All definitions related to the hardware of the HornSystem
 *  \details   This header includes macros and type definition in function of the hardware
 *             design: Main Board, Communication Board and PowerBoard
 *  \author    Krzysztof Herman
 *  \version   1.0
 *  \date      06.2022
 *  \warning   Under development
 *  \copyright KHerman
 */

#ifndef _DEFS_H_
#define _DEFS_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"

//#define BOYA_ID "PAR647"

#define MNAME "module1"
#define ADC_BUFF_SIZE 4
#define MA_SIZE    256

/**
 * \brief   Debug mode indicator 0 - Release, !0 - Debug.
 */
#define DEBUG 0

/**
 * \brief   Defines Uart timeout used in Transmission
 */
#define UartTimeout 400

/**
 * \brief   User interface: Bottons and Leds
 * \warning Led2 connected to the SDIO PIN, SW2 and SW3 labels related to the silckscreen description
 */

#define Led1_Port GPIOB
#define Led1_Pin GPIO_PIN_9
#define Led1_ON() HAL_GPIO_WritePin(Led1_Port, Led1_Pin, SET);
#define Led1_OFF() HAL_GPIO_WritePin(Led1_Port, Led1_Pin, RESET);
#define Led1_Toggle() HAL_GPIO_TogglePin(Led1_Port, Led1_Pin);
#define Led2_Port GPIOA
#define Led2_Pin GPIO_PIN_13
#define Led2_ON() HAL_GPIO_WritePin(Led2_Port, Led2_Pin, SET);
#define Led2_OFF() HAL_GPIO_WritePin(Led2_Port, Led2_Pin, RESET);
#define Led2_Toggle() HAL_GPIO_TogglePin(Led2_Port, Led2_Pin);
#define SW2_Port GPIOB
#define SW2_Pin GPIO_PIN_8
#define SW2() HAL_GPIO_ReadPin(SW2_Port, SW2_Pin);
#define SW3_Port GPIOB
#define SW3_Pin GPIO_PIN_15
#define SW3() HAL_GPIO_ReadPin(SW3_Port, SW3_Pin);

/**
 * \brief   SPI1 Interface
 * \warning
 */
#define NSS_LoRa_Port GPIOC
#define NSS_LoRa_Pin GPIO_PIN_10
#define NSS_LoRa_ON() HAL_GPIO_WritePin(NSS_LoRa_Port, NSS_LoRa_Pin, SET);
#define NSS_LoRa_OFF() HAL_GPIO_WritePin(NSS_LoRa_Port, NSS_LoRa_Pin, RESET);
#define NSS_LoRa_Toggle() HAL_GPIO_TogglePin(NSS_LoRa_Port NSS_LoRa_Pin);
#define NSS_SD_Port GPIOC
#define NSS_SD_Pin GPIO_PIN_13
#define NSS_SD_ON() HAL_GPIO_WritePin(NSS_SD_Port, NSS_SD_Pin, SET);
#define NSS_SD_OFF() HAL_GPIO_WritePin(NSS_SD_Port, NSS_SD_Pin, RESET);
#define NSS_SD_Toggle() HAL_GPIO_TogglePin(NSS_SD_Port NSS_SD_Pin);

/**
 * \brief   LoRa Interface DIO  0-5
 * \warning
 */
#define DIO0_Port GPIOC
#define DIO0_Pin GPIO_PIN_3
#define DIO0_ON() HAL_GPIO_WritePin(DIO0_Port, DIO0_Pin, SET);
#define DIO0_OFF() HAL_GPIO_WritePin(DIO0_Port, DIO0_Pin, RESET);
#define DIO0_Toggle() HAL_GPIO_TogglePin(DIO0_Port, DIO0_Pin);

#define DIO1_Port GPIOC
#define DIO1_Pin GPIO_PIN_11
#define DIO1_ON() HAL_GPIO_WritePin(DIO1_Port, DIO1_Pin, SET);
#define DIO1_OFF() HAL_GPIO_WritePin(DIO1_Port, DIO1_Pin, RESET);
#define DIO1_Toggle() HAL_GPIO_TogglePin(DIO1_Port, DIO1_Pin);

#define DIO2_Port GPIOB
#define DIO2_Pin GPIO_PIN_5
#define DIO2_ON() HAL_GPIO_WritePin(DIO2_Port, DIO2_Pin, SET);
#define DIO2_OFF() HAL_GPIO_WritePin(DIO2_Port, DIO2_Pin, RESET);
#define DIO2_Toggle() HAL_GPIO_TogglePin(DIO2_Port, DIO2_Pin);

#define DIO3_Port GPIOC
#define DIO3_Pin GPIO_PIN_6
#define DIO3_ON() HAL_GPIO_WritePin(DIO3_Port, DIO3_Pin, SET);
#define DIO3_OFF() HAL_GPIO_WritePin(DIO3_Port, DIO3_Pin, RESET);
#define DIO3_Toggle() HAL_GPIO_TogglePin(DIO3_Port, DIO3_Pin);

#define DIO4_Port GPIOC
#define DIO4_Pin GPIO_PIN_7
#define DIO4_ON() HAL_GPIO_WritePin(DIO4_Port, DIO4_Pin, SET);
#define DIO4_OFF() HAL_GPIO_WritePin(DIO4_Port, DIO4_Pin, RESET);
#define DIO4_Toggle() HAL_GPIO_TogglePin(DIO4_Port, DIO4_Pin);

#define DIO5_Port GPIOC
#define DIO5_Pin GPIO_PIN_8
#define DIO5_ON() HAL_GPIO_WritePin(DIO5_Port, DIO5_Pin, SET);
#define DIO5_OFF() HAL_GPIO_WritePin(DIO5_Port, DIO5_Pin, RESET);
#define DIO5_Toggle() HAL_GPIO_TogglePin(DIO5_Port, DIO5_Pin);

#define RST_LoRa_Port GPIOC
#define RST_LoRa_Pin GPIO_PIN_12
#define RST_LoRa_ON() HAL_GPIO_WritePin(RST_LoRa_Port, RST_LoRa_Pin, SET);
#define RST_LoRa_OFF() HAL_GPIO_WritePin(RST_LoRa_Port, RST_LoRa_Pin, RESET);
#define RST_LoRa_Toggle() HAL_GPIO_TogglePin(RST_LoRa_Port RST_LoRa_Pin);

#define RXTX_RF_LoRa_Port GPIOB
#define RXTX_RF_LoRa_Pin GPIO_PIN_3
#define RXTX_RF_LoRa_ON() HAL_GPIO_WritePin(RXTX_RF_LoRa_Port, RXTX_RF_LoRa_Pin, SET);
#define RXTX_RF_LoRa_OFF() HAL_GPIO_WritePin(RXTX_RF_LoRa_Port, RXTX_RF_LoRa_Pin, RESET);
#define RXTX_RF_LoRa_Toggle() HAL_GPIO_TogglePin(RXTX_RF_LoRa_Port RXTX_RF_LoRa_Pin);

/**
 * \brief   SAT Modem interface
 * \warning
 */
#define GPIO_Port GPIOA
#define GPIO_Pin GPIO_PIN_8
#define GPIO_ON() HAL_GPIO_WritePin(GPIO_Port, GPIO_Pin, SET);
#define GPIO_OFF() HAL_GPIO_WritePin(GPIO_Port, GPIO_Pin, RESET);
#define GPIO_Toggle() HAL_GPIO_TogglePin(GPIO_Port, GPIO_Pin);
#define GPIO() HAL_GPIO_ReadPin(GPIO_Port, GPIO_Pin);

#define TR_Port GPIOC
#define TR_Pin GPIO_PIN_9
#define TR_ON() HAL_GPIO_WritePin(TR_Port, TR_Pin, SET);
#define TR_OFF() HAL_GPIO_WritePin(TR_Port, TR_Pin, RESET);
#define TR_Toggle() HAL_GPIO_TogglePin(TR_Port, TR_Pin);
#define TR() HAL_GPIO_ReadPin(TR_Port, TR_Pin);

/**
 * \brief   Digital inputs configuration
 *          Should be asociated with External interrupts
 * \warning
 */
#define DIN1_Port GPIOC
#define DIN1_Pin GPIO_PIN_4
#define DIN1_ON() HAL_GPIO_WritePin(DIN1_Port, DIN1_Pin, SET);
#define DIN1_OFF() HAL_GPIO_WritePin(DIN1_Port, DIN1_Pin, RESET);
#define DIN1_Toggle() HAL_GPIO_TogglePin(DIN1_Port, DIN1_Pin);
#define DIN1() HAL_GPIO_ReadPin(DIN1_Port, DIN1_Pin);

#define DIN2_Port GPIOC
#define DIN2_Pin GPIO_PIN_5
#define DIN2_ON() HAL_GPIO_WritePin(DIN2_Port, DIN2_Pin, SET);
#define DIN2_OFF() HAL_GPIO_WritePin(DIN2_Port, DIN2_Pin, RESET);
#define DIN2_Toggle() HAL_GPIO_TogglePin(DIN2_Port, DIN2_Pin);
#define DIN2() HAL_GPIO_ReadPin(DIN2_Port, DIN2_Pin);

#define DIN3_Port GPIOB
#define DIN3_Pin GPIO_PIN_12
#define DIN3_ON() HAL_GPIO_WritePin(DIN3_Port, DIN3_Pin, SET);
#define DIN3_OFF() HAL_GPIO_WritePin(DIN3_Port, DIN3_Pin, RESET);
#define DIN3_Toggle() HAL_GPIO_TogglePin(DIN3_Port, DIN3_Pin);
#define DIN3() HAL_GPIO_ReadPin(DIN3_Port, DIN3_Pin);

/**
 * \brief   Power managment
 *          Shutdown controls lines switches
 *          Run 1&2 control the switching converters on the power boards
 *          PWRKEY controls the GSM modem
 * \warning
 */

#define Shutdown_Port GPIOB
#define Shutdown_Pin GPIO_PIN_4
#define Shutdown_ON() HAL_GPIO_WritePin(Shutdown_Port, Shutdown_Pin, SET);
#define Shutdown_OFF() HAL_GPIO_WritePin(Shutdown_Port, Shutdown_Pin, RESET);
#define Shutdown_Toggle() HAL_GPIO_TogglePin(_ShutdownPort, Shutdown_Pin);
#define Shutdown() HAL_GPIO_ReadPin(Shutdown_Port, Shutdown_Pin);

#define Run1_Port GPIOB
#define Run1_Pin GPIO_PIN_13
#define Run1_ON() HAL_GPIO_WritePin(Run1_Port, Run1_Pin, SET);
#define Run1_OFF() HAL_GPIO_WritePin(Run1_Port, Run1_Pin, RESET);
#define Run1_Toggle() HAL_GPIO_TogglePin(Run1_Port, Run1_Pin);
#define Run1() HAL_GPIO_ReadPin(Run1_Port, Run1_Pin);

#define Run2_Port GPIOB
#define Run2_Pin GPIO_PIN_14
#define Run2_ON() HAL_GPIO_WritePin(Run2_Port, Run2_Pin, SET);
#define Run2_OFF() HAL_GPIO_WritePin(Run2_Port, Run2_Pin, RESET);
#define Run2_Toggle() HAL_GPIO_TogglePin(Run2_Port, Run2_Pin);
#define Run2() HAL_GPIO_ReadPin(Run2_Port, Run2_Pin);

#define PWRKEY_Port GPIOD
#define PWRKEY_Pin GPIO_PIN_2
#define PWRKEY_ON() HAL_GPIO_WritePin(PWRKEY_Port, PWRKEY_Pin, SET);
#define PWRKEY_OFF() HAL_GPIO_WritePin(PWRKEY_Port, PWRKEY_Pin, RESET);
#define PWRKEY_Toggle() HAL_GPIO_TogglePin(PWRKEY_Port, PWRKEY_Pin);
#define PWRKEY() HAL_GPIO_ReadPin(PWRKEY_Port, PWRKEY_Pin);


/**
 * \brief   Local UART
 * \warning
 */
#define TX_Local_Port   GPIOA
#define TX_Local_Pin    GPIO_PIN_9
#define RX_Local_Port   GPIOA
#define RX_Local_Pin    GPIO_PIN_10

/**
 * \brief   Communication Uart
 * \warning
 */
#define TX_Port   GPIOA
#define TX_Pin    GPIO_PIN_2
#define RX_Port   GPIOA
#define RX_Pin    GPIO_PIN_3

/**
 * \brief   SPI1 
 *          Shared between SD and LoRa
 * \warning
 */
#define SPI1_Port        GPIOA
#define SPI1_SCK_Pin     GPIO_PIN_5
#define SPI1_MOSI_Pin    GPIO_PIN_7
#define SPI1_MISO_Pin    GPIO_PIN_6

/**
 * \brief   I2C1 
 *          
 * \warning
 */
#define I2C1_Port        GPIOB
#define I2C1_SCK_Pin     GPIO_PIN_6
#define I2C1_SDA_Pin     GPIO_PIN_7


/**
 * \brief   I2C2 
 *          
 * \warning
 */
#define I2C2_Port        GPIOB
#define I2C2_SCK_Pin     GPIO_PIN_10
#define I2C2_SDA_Pin     GPIO_PIN_11

/**
 * \brief   Analog ports 
 *          Analog_Current1 = AD-ch0
 *          Analog_Current2 = AD-ch1
 *          Analog_Voltage1 = AD-ch11
 *          Analog_Voltage2 = AD-ch10
                      
 * \warning
 */
#define Analog_Current_Port           GPIOC
#define Analog_Current1               GPIO_PIN_0
#define Analog_Current2               GPIO_PIN_1
 
#define Analog_Voltage1_Port           GPIOA
#define Analog_Voltage2_Port           GPIOC
#define Analog_Voltage1               GPIO_PIN_0
#define Analog_Voltage2               GPIO_PIN_12


#endif
