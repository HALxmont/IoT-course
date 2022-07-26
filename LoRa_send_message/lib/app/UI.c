#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"
#include "UI.h"
#include "defs.h"
#include "HardwareInit.h"
#include "LoraApp.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



char UI_Buffer[UI_Buff_Size];
extern char      LoRaRxBuff[LRBuffSize];
UI_SetParams_t UI; 
HATypeDefAlarms  HA_Alarms;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart1;

uint8_t UTC_Day;
uint8_t UTC_Mon;
uint8_t UTC_Year;
uint8_t UTC_Hour;
uint8_t UTC_Min;
uint8_t UTC_Sec;

uint8_t v1 = 11;
uint8_t v2 = 5;


//#####################################################################################
//##### UI RX PROCESSS 																  #
//#####################################################################################

void UI_SetParams()
{

const char delim[2] = ",";
char *token = NULL;
uint8_t tokenIndex = 0;
char t1[20];

int8_t tagetRxBuff[UIBuffLength];

//####################
//##### ?INFO CASE ###
//####################

memset(tagetRxBuff, 0, UIBuffLength); 
Delimiter(tagetRxBuff, UI_Buffer, "?INFO");

	if(  (UI.rxIndex>0))
	{
    	if(!strncmp(tagetRxBuff, "?INFO", 4)){  //DATA REQUEST

		UI_SendINFO(); //send info 
		UI.rxIndex=0;		//reset index
		
		} // endif "?LVV"	
	memset(tagetRxBuff, 0, UIBuffLength);  
   	}  //endif


//####################
//##### ?LORA CASE ####
//####################

memset(tagetRxBuff, 0, LRBuffSize); 
Delimiter(tagetRxBuff, LoRaRxBuff, "?LORA");

	if(  (UI.rxIndex>0))
	{
    	if(!strncmp(tagetRxBuff, "?LORA", 4)){  //DATA REQUEST
			
			LoRaSendInfo(); //send info through LoRa 
			UI.rxIndex=0;   //reset index

		} // end if "?LORA"	

	memset(tagetRxBuff, 0, LRBuffSize);  
   	}  //endif


//####################
//##### !RTC CASE ####
//####################
//!RTC_uart,13,07,2022,22,43,39,*
//dd,MM,yyyy,HH,mm,ss
memset(tagetRxBuff, 0, UIBuffLength); 
Delimiter(tagetRxBuff, UI_Buffer, "!RTC_uart");

	if(  (UI.rxIndex>0))
	{
    	if(!strncmp(tagetRxBuff, "!RTC_uart", 9)){
        	/* get the first token */
        	token = strtok(tagetRxBuff, delim);      
    		/* walk through other tokens */
    		while( token != NULL ) {

				token = strtok(NULL, delim);
        		tokenIndex++;

        		switch(tokenIndex){

            		case 1: 	
							t1[0] = token[0];
                    		t1[1] = token[1];
							t1[2] = '\0';
							UTC_Day = atoi(t1);
					break;

	            	case 2: 
							t1[0] = token[0];
							t1[1] = token[1];
							t1[2] = '\0';
							UTC_Mon = atoi(t1);
            		break;	
	    
					case 3: 
							t1[0] = token[2];
                    		t1[1] = token[3];
                    		t1[2] = '\0';
                    		UTC_Year = atoi(t1);
					break;

					case 4: 
							t1[0] = token[0];
                    		t1[1] = token[1];
                    		t1[2] = '\0';
                    		UTC_Hour = atoi(t1);
					case 5: 
							t1[0] = token[0];
                    		t1[1] = token[1];
                    		t1[2] = '\0';
                    		UTC_Min = atoi(t1);
					case 6: 
							t1[0] = token[0];
                    		t1[1] = token[1];
                    		t1[2] = '\0';
                    		UTC_Sec = atoi(t1);
					break;
   	     		} //endcase
			} //endwhile
		UI.rxIndex=0;		//reset index
		} // endif "!RTI"	
	memset(tagetRxBuff, 0, UIBuffLength);  

   	}  //endif


//LORA
//####################
//##### RTC CASE ####
//####################
//RTC_lora,13,07,2025,22,43,41,*
//dd,MM,yyyy,HH,mm,ss
memset(tagetRxBuff, 0, LRBuffSize); 
Delimiter(tagetRxBuff, LoRaRxBuff, "RTC_lora");

	if(  (UI.rxIndex>0))
	{
    	if(!strncmp(tagetRxBuff, "RTC_lora", 8)){
        	/* get the first token */
        	token = strtok(tagetRxBuff, delim);      
    		/* walk through other tokens */
    		while( token != NULL ) {

				token = strtok(NULL, delim);
        		tokenIndex++;

        		switch(tokenIndex){

            		case 1: 	
							t1[0] = token[0];
                    		t1[1] = token[1];
							t1[2] = '\0';
							UTC_Day = atoi(t1);
					break;

	            	case 2: 
							t1[0] = token[0];
							t1[1] = token[1];
							t1[2] = '\0';
							UTC_Mon = atoi(t1);
            		break;	
	    
					case 3: 
							t1[0] = token[2];
                    		t1[1] = token[3];
                    		t1[2] = '\0';
                    		UTC_Year = atoi(t1);
					break;

					case 4: 
							t1[0] = token[0];
                    		t1[1] = token[1];
                    		t1[2] = '\0';
                    		UTC_Hour = atoi(t1);
					case 5: 
							t1[0] = token[0];
                    		t1[1] = token[1];
                    		t1[2] = '\0';
                    		UTC_Min = atoi(t1);
					case 6: 
							t1[0] = token[0];
                    		t1[1] = token[1];
                    		t1[2] = '\0';
                    		UTC_Sec = atoi(t1);
					break;
   	     		} //endcase
					myprintf("Se han seteado los parametros correctamente via LoRa!\r\n");
			} //endwhile
		UI.rxIndex=0;		//reset index
		} // endif 	
	memset(tagetRxBuff, 0, LRBuffSize);  
	HAL_UART_Transmit(&huart3, "Se han seteado los parametros correctamente via LoRa!\r\n", 56, 0x800);
   	}  //endif
}//end function UI



void UI_SendINFO(void){
myprintf("UI INFO: %d/%d/%d %d:%d:%d, %d, %d \r\n", UTC_Day, UTC_Mon, UTC_Year, UTC_Hour, UTC_Min, UTC_Sec, v1, v2);

}



void Delimiter(int8_t *dst, uint8_t *src, const char *ref ){

 uint8_t *start, *stop, len;

	start = (uint8_t*) strstr(src, ref);
	stop  = (uint8_t*) strchr(start, '*');
	len = stop-start;
	if(len>0){
		memcpy(dst, (uint8_t*) start, len);
		dst[len] = 0;
		UI.rxIndex = len;
	}
}




