/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#n
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
#n
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */
#n
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

#n
#t/* MCU Configuration--------------------------------------------------------*/
#n#t/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
#tHAL_Init();
#n
#t/* USER CODE BEGIN Init */
#n#t/* USER CODE END Init */
#n
#n#t/* Configure the system clock */
#tSystemClock_Config();
#n
#t/* USER CODE BEGIN SysInit */
#n#t/* USER CODE END SysInit */
#n
#n#t/* Initialize all configured peripherals */
#tMX_GPIO_Init();
#tMX_DMA_Init();
#tMX_DAC1_Init();
#tMX_ADC1_Init();
#tMX_TIM6_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */



#n
#t/* Infinite loop */
#t/* USER CODE BEGIN WHILE */
#twhile (1)
#t{
#t#t/* USER CODE END WHILE */
#n
#t#t/* USER CODE BEGIN 3 */
#t}
#t/* USER CODE END 3 */
}
#n/**
#t* @brief System Clock Configuration
#t* @retval None
#t*/
void SystemClock_Config(void)
{
#tRCC_OscInitTypeDef RCC_OscInitStruct = {0};
#tRCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
#tRCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};#n
#t/**Supply configuration update enable #n#t*/
#tMODIFY_REG(PWR->CR3, PWR_CR3_SCUEN, 0);
#t/**Configure the main internal regulator output voltage #n#t*/
#t__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
#n#twhile ((PWR->D3CR & (PWR_D3CR_VOSRDY)) != PWR_D3CR_VOSRDY) #n#t{#n#t#t#n#t}
#t/**Macro to configure the PLL clock source #n#t*/
#t__HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_PLLSOURCE_HSI);
#t/**Initializes the CPU, AHB and APB busses clocks #n#t*/
#tRCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
#tRCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
#tRCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
#tRCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
#tRCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
#tRCC_OscInitStruct.PLL.PLLM = 4;
#tRCC_OscInitStruct.PLL.PLLN = 24;
#tRCC_OscInitStruct.PLL.PLLP = 4;
#tRCC_OscInitStruct.PLL.PLLQ = 4;
#tRCC_OscInitStruct.PLL.PLLR = 2;
#tRCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
#tRCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
#tRCC_OscInitStruct.PLL.PLLFRACN = 0;
#tif (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
#t{
#t#tError_Handler();
#t}
#t/**Initializes the CPU, AHB and APB busses clocks #n#t*/
#tRCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK#n#t#t#t#t#t#t#t#t#t#t#t#t#t#t#t|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2#n#t#t#t#t#t#t#t#t#t#t#t#t#t#t#t|RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
#tRCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
#tRCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
#tRCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
#tRCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
#tRCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
#tRCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
#tRCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;
#n
#tif (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
#t{
#t#tError_Handler();
#t}
#tPeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC;
#tPeriphClkInitStruct.PLL2.PLL2M = 4;
#tPeriphClkInitStruct.PLL2.PLL2N = 10;
#tPeriphClkInitStruct.PLL2.PLL2P = 3;
#tPeriphClkInitStruct.PLL2.PLL2Q = 2;
#tPeriphClkInitStruct.PLL2.PLL2R = 2;
#tPeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_3;
#tPeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOMEDIUM;
#tPeriphClkInitStruct.PLL2.PLL2FRACN = 0;
#tPeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL2;
#tif (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
#t{
#t#tError_Handler();
#t}
#tHAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSI, RCC_MCODIV_10);
}


 
#n
#n

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */
#n

 


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
