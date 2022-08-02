/*! 
 *  \brief     Pretty nice class.
 *  \details   This class is used to demonstrate a number of section commands.
 *  \author    Jan Doe
 *  \version   4.1a
 *  \date      1990-2011
 *  \pre       First initialize the system.
 *  \bug       Not all memory is freed when deleting an object of this class.
 *  \warning   Improper use can crash your application
 *  \copyright GNU Public License.
 */

#ifndef _SENSORS_H_
#define _SENSORS_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"


/**
 * \brief   Indicates if the structure was read ( sets 0 ) or written (sets 1) 
*/
typedef enum{Unmodified = 0, Modified } ReadFlag;

/**
 * \brief   Definition of the structure, which holds measured data 
*/
typedef struct{

uint16_t    MeasurementIndex;
uint16_t    Vbat;
uint16_t    Vsol;
uint16_t    Cbat;
uint16_t    Csol;
uint8_t     DigitalIn;
uint16_t    Temperature;
uint8_t     LocalAlerts;
ReadFlag    rflag;

} MeasurementTypeDef; 



typedef struct{

uint16_t    MeasurementIndex;
uint16_t    Vbat;
uint16_t    Vsol;
uint16_t    Cbat;
uint16_t    Csol;
uint8_t     DigitalIn;
uint16_t    Temperature;
uint8_t     LocalAlerts;
ReadFlag    rflag;

} ResultsTypeDef;

/**
 * \brief   Definition of the structure, which holds tresholds 
*/
typedef struct{

uint16_t    VbatMin;
uint16_t    VsolMin;
uint16_t    CbatMin;
uint16_t    CsolMin;
uint16_t    VbatMax;
uint16_t    VsolMax;
uint16_t    CbatMax;
uint16_t    CsolMax;
ReadFlag    rflag;

} TresholdTypeDef;

/**
 * \brief   The function bar. 
 * \details This function does something which is doing nothing. So this text
 * \note    This text shall only show you, how such a \"note\" section
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 * \return        The error return code of the function.
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */

void SENS_function(void);

#endif
