/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include <stdint.h>
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define LED1_Pin GPIO_PIN_7
#define LED1_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */
#define _DAC_BASE 0x400077FF

namespace stm32
{
enum class dacTrigger {SWTRIG, TIM1_TRGO, TIM2_TRG, TIM4_TRG,
                    TIM5_TRG, TIM6_TRG, TIM7_TRG, TIM8_TRG,
                    TIM15_TRG, HRTIM1_DACTRG1, HRTIM1_DACTRG2,
                    LPTIM1_OUT, LIPTIM2_OUT, EXTI9};

enum class dacChannel{DAC_CHANNEL1, DAC_CHANNEL2 = (1 << 16)};

class DAC
{
private:
  uint32_t volatile const* DAC_CR_ADDR      = (uint32_t*)(_DAC_BASE + 0x00);
  uint32_t volatile const* DAC_SWTRGR_ADDR  = (uint32_t*)(_DAC_BASE + 0x04);
  uint32_t volatile const* DAC_DHR12R1_ADDR = (uint32_t*)(_DAC_BASE + 0x08);
  uint32_t volatile const* DAC_DHR12L1_ADDR = (uint32_t*)(_DAC_BASE + 0x0C);
  uint32_t volatile const* DAC_DHR8R1_ADDR  = (uint32_t*)(_DAC_BASE + 0x10);
  uint32_t volatile const* DAC_DHR12R2_ADDR = (uint32_t*)(_DAC_BASE + 0x14);
  uint32_t volatile const* DAC_DHR12L2_ADDR = (uint32_t*)(_DAC_BASE + 0x18);
  uint32_t volatile const* DAC_DHR8R2_ADDR  = (uint32_t*)(_DAC_BASE + 0x1C);
  uint32_t volatile const* DAC_DHR12RD_ADDR = (uint32_t*)(_DAC_BASE + 0x20);
  uint32_t volatile const* DAC_DHR12LD_ADDR = (uint32_t*)(_DAC_BASE + 0x24);
  uint32_t volatile const* DAC_DHR8RD_ADDR  = (uint32_t*)(_DAC_BASE + 0x28);
  uint32_t volatile const* DAC_DOR1_ADDR    = (uint32_t*)(_DAC_BASE + 0x2C);
  uint32_t volatile const* DAC_DOR2_ADDR    = (uint32_t*)(_DAC_BASE + 0x30);
  uint32_t volatile const* DAC_SR_ADDR      = (uint32_t*)(_DAC_BASE + 0x34);
  uint32_t volatile const* DAC_CCR_ADDR     = (uint32_t*)(_DAC_BASE + 0x38);
  uint32_t volatile const* DAC_MCR_ADDR     = (uint32_t*)(_DAC_BASE + 0x3C);
  uint32_t volatile const* DAC_SHSR1_ADDR   = (uint32_t*)(_DAC_BASE + 0x40);
  uint32_t volatile const* DAC_SHSR2_ADDR   = (uint32_t*)(_DAC_BASE + 0x44);
  uint32_t volatile const* DAC_SHHR_ADDR    = (uint32_t*)(_DAC_BASE + 0x48);
  uint32_t volatile const* DAC_SHRR_ADDR    = (uint32_t*)(_DAC_BASE + 0x4C);
  uint32_t volatile const& DAC_CR           = *DAC_CR_ADDR;
  uint32_t volatile const& DAC_SWTRGR       = *DAC_SWTRGR_ADDR;
  uint32_t volatile const& DAC_DHR12R1      = *DAC_DHR12R1_ADDR;
  uint32_t volatile const& DAC_DHR12L1      = *DAC_DHR12L1_ADDR;
  uint32_t volatile const& DAC_DHR8R1       = *DAC_DHR8R1_ADDR;
  uint32_t volatile const& DAC_DHR12R2      = *DAC_DHR12R2_ADDR;
  uint32_t volatile const& DAC_DHR12L2      = *DAC_DHR12L2_ADDR;
  uint32_t volatile const& DAC_DHR8R2       = *DAC_DHR8R2_ADDR;
  uint32_t volatile const& DAC_DHR12RD      = *DAC_DHR12RD_ADDR;
  uint32_t volatile const& DAC_DHR12LD      = *DAC_DHR12LD_ADDR;
  uint32_t volatile const& DAC_DHR8RD       = *DAC_DHR8RD_ADDR;
  uint32_t volatile const& DAC_DOR1         = *DAC_DOR1_ADDR;
  uint32_t volatile const& DAC_DOR2         = *DAC_DOR2_ADDR;
  uint32_t volatile const& DAC_SR           = *DAC_SR_ADDR;
  uint32_t volatile const& DAC_CCR          = *DAC_CCR_ADDR;
  uint32_t volatile const& DAC_MCR          = *DAC_MCR_ADDR;
  uint32_t volatile const& DAC_SHSR1        = *DAC_SHSR1_ADDR;
  uint32_t volatile const& DAC_SHSR2        = *DAC_SHSR2_ADDR;
  uint32_t volatile const& DAC_SHHR         = *DAC_SHHR_ADDR;
  uint32_t volatile const& DAC_SHRR         = *DAC_SHRR_ADDR;
public:
  void enableChannel(dacChannel chan);
  void disableChannel(dacChannel chan);
  void setTrigger(dacTrigger trig, dacChannel chan);
  void unsetTrigger(dacChannel chan);

};
}
/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
