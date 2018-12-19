#include <math.h>
#include "stm32h743xx.h"
#include "stm32h7-dac.hpp"

void SystemClock_Config(void);

int main(void)
{
    const double pi = acos(-1);
    const int res = 36;
    uint32_t i = 0;
    uint32_t sine[res];
    for(int i = 0; i < res; i++){
        sine[i] = 2028 + 2000 * (sin(((2*pi)/res)*i));
    }

    stm32::DAC dac;
    dac.enable();
    dac.enableChannel1();    

    while (true)
    {
        i++;
        i = i % res;
        dac.Register.channel1.dataHoldR = sine[i];
    }
}
