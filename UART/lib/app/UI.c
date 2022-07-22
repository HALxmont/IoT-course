#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"
#include "UI.h"
#include "defs.h"
#include "HardwareInit.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char UI_Buffer[UI_Buff_Size];
UI_SetParams_t UI; 
HATypeDefAlarms  HA_Alarms;

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
//##### ?LVL CASE ####
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
//##### !RTC CASE ####
//####################
//!RTC,13,07,2022,22,43,39,*
//dd,MM,yyyy,HH,mm,ss
memset(tagetRxBuff, 0, UIBuffLength); 
Delimiter(tagetRxBuff, UI_Buffer, "!RTC");

	if(  (UI.rxIndex>0))
	{
    	if(!strncmp(tagetRxBuff, "!RTC", 4)){
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

}//end function UI



void UI_SendINFO(void){
//HEAD,	LEVELS,	LastMeas_TIMESTAMP,	BoyaID,	GPSlat,	GPSlon,	VBattFanal,	VSolarChrg,	IBattFanal,	ISolarChrg, 	VBattMAX	VBattMIN	IBattMAX	IBattMIN	VSolMAX	VSolMIN	ISolMAX	ISolMIN	VBattHIalarm	VBattLOalarm	IBattHIalarm	IBattLOalarm	VSolHIalarm	VSolLOalarm	ISolHIalarm	ISolOalarm	Dint1	Dint2	Dint3	Tcore	TModem
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




