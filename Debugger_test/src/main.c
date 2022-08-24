
#include "main.h"


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);




// user global vars
uint8_t counter;
int8_t negative_counter;

int16_t a, b;
int8_t c[2];


int main(void)
{


  
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();


  while (1)
  {
    //crete a breakepoint in line 38 (a = counter * 10;)
    //add to the wacth variables "a" and "counter". Launch the debugger and see what it's going on 0_0 
    for (counter = 0; counter <= 5 ; counter++)
    {
      a = counter * 10;
    }
  
    //crete a breakepoint in line 47 (b = negative_counter * 10;)
    //crete a breakepoint in line 48 (c[0] = b;)
    //crete a breakepoint in line 49 (c[1] = -1 * b;)
    //add to the wacth variables "b", "negative_counter" and "c". Launch the debugger and see what it's going on 0_0
    for (negative_counter = 0; negative_counter <= 5 ; negative_counter--)
    {
      b = negative_counter * 10;
      c[0] = b;
      c[1] = -1 * b;
    }

  }
  
}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}



void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}

