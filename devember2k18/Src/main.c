#include <math.h>
#include "stm32h743xx.h"

void SystemClock_Config(void);
void DAC_Init();

int main(void)
{
    const double pi = acos(-1);
    const int res = 36;
    uint32_t i = 0;
    uint32_t sine[res];
    for(int i = 0; i < res; i++){
        sine[i] = 2028 + 2000 * (sin(((2*pi)/res)*i));
    }

    DAC_Init();
    DAC1->CR |= 0x1U;

    while (1)
    {
      i++;
      i = i % res;
      DAC1->DHR12R1 = sine[i];
    }
}

void DAC_Init()
{
    DAC1->CR = 0x0U;
    DAC1->
    RCC->APB1LENR |= RCC_APB1LENR_DAC12EN;
    DAC1->MCR = 0x2U;
    DAC1->CCR = 0x12000eU;
}
