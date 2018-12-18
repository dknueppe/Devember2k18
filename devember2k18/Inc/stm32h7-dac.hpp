#pragma once

#include <stdint.h>
#include "stm32.hpp"

namespace stm32 
{
enum triggerSelect {SWTRIG,    TIM1_TRGO, TIM2_TRGO,
                    TIM3_TRGO, TIM4_TRGO, TIM5_TRGO,
                    TIM6_TRGO, TIM7_TRGO, TIM8_TRGO,
                    TIM15_TRGO, HRTIM1_DACTRG1, HRTIM1_DACTRG2,
                    LPTIM1_OUT, LPTIM2_OUT, EXTI9};

enum waveSelect {waveDisabled, noiseGen, triangleGen};

enum outputSelect {extBuf, extOnBuf, extNobuf, onNobuf};

union dacType
{
    struct 
    {
        //DAC_CR
        volatile uint32_t enable                    :  1;
        volatile uint32_t enableTrig                :  1;
        volatile triggerSelect selectTrig           :  4;
        volatile waveSelect selectWave              :  2;
        volatile uint32_t selectAmplitude           :  4;
        volatile uint32_t enableDma                 :  1;
        volatile uint32_t enableDmaUnderrunInterrupt:  1;
        volatile uint32_t enableCalibration         :  1;
        const volatile uint32_t /* unused */        :  1;
        const volatile uint32_t /* unused */        : 16;
        //DAC_SWTRGR
        volatile uint32_t setSoftwareTrigger        :  1;
        const volatile uint32_t /* unused */        :  1;
        const volatile uint32_t /* unused */        : 30;
        //DAC_DHR12R1
        volatile uint32_t dataHoldR                 : 12;
        const volatile uint32_t /* unused */        : 20;
        //DAC_DHR12L1
        const volatile uint32_t /* unused */        :  4;
        volatile uint32_t dataHoldL                 : 12;
        const volatile uint32_t /* unused */        : 16;
        //DAC_DHR8R1
        volatile uint32_t dataHold8                 :  8;
        const volatile uint32_t /* unused */        : 24;
        //DAC_DHR12R2
        const volatile uint32_t /* unused */        : 32;
        //DAC_DHR12L2
        const volatile uint32_t /* unused */        : 32;
        //DAC_DHR8R2
        const volatile uint32_t /* unused */        : 32;
        //DAC_DHR12RD
        volatile uint32_t dataHoldDualR             : 12;
        const volatile uint32_t /* unused */        : 20;
        //DAC_DHR12LD
        const volatile uint32_t /* unused */        :  4;
        volatile uint32_t dataHoldDualL             : 12;
        const volatile uint32_t /* unused */        : 16;
        //DAC_DHR8RD
        volatile uint32_t dataHoldDual8             :  8;
        const volatile uint32_t /* unused */        : 24;
        //DAC_DOR1
        const volatile uint32_t dataOut             : 12;
        const volatile uint32_t /* unused */        : 20;
        //DAC_DOR2
        const volatile uint32_t /* unused */        : 32;
        //DAC_SR
        const volatile uint32_t /* unused */        : 13;
        const volatile uint32_t dmaUnderrunFlag     :  1;
        const volatile uint32_t calibGreaterEqual   :  1;
        const volatile uint32_t busyWritingSample   :  1;
        const volatile uint32_t /* unused */        : 16;
        //DAC_CCR
        volatile uint32_t offsetTrim                :  4;
        const volatile uint32_t /* unused */        : 28;
        //DAC_MCR
        volatile outputSelect selectOutput          :  2;
        volatile uint32_t sampleHoldMode            :  1;
        const volatile uint32_t /* unused */        : 29;
        //DAC_SHSR1
        volatile uint32_t dataSample                : 10;
        const volatile uint32_t /* unused */        : 22;
        //DAC_SHSR2
        const volatile uint32_t /* unused */        : 32;
        //DAC_SHHR
        volatile uint32_t holdTime                  : 10;
        const volatile uint32_t /* unused */        : 22;
        //DAC_SHRR
        volatile uint32_t refreshTime               :  8;
        const volatile uint32_t /* unused */        : 24;
    } channel1;
    
    struct 
    {
        const volatile uint32_t /* unused */        : 16;
        volatile uint32_t enable                    :  1;
        volatile uint32_t enableTrig                :  1;
        volatile triggerSelect selectTrig           :  4;
        volatile waveSelect selectWave              :  2;
        volatile uint32_t selectAmplitude           :  4;
        volatile uint32_t enableDma                 :  1;
        volatile uint32_t enableDmaUnderrunInterrupt:  1;
        volatile uint32_t enableCalibration         :  1;
        const volatile uint32_t /* unused */        :  1;

        const volatile uint32_t /* unused */        :  1;
        volatile uint32_t setSoftwareTrigger        :  1;
        const volatile uint32_t /* unused */        : 30;

        const volatile uint32_t /* unused */        : 32;

        const volatile uint32_t /* unused */        : 32;

        const volatile uint32_t /* unused */        : 32;

        volatile uint32_t dataHoldR                 : 12;
        const volatile uint32_t /* unused */        : 20;

        const volatile uint32_t /* unused */        :  4;
        volatile uint32_t dataHoldL                 : 12;
        const volatile uint32_t /* unused */        : 16;

        volatile uint32_t dataHold8                 :  8;
        const volatile uint32_t /* unused */        : 24;

        const volatile uint32_t /* unused */        : 16;
        volatile uint32_t dataHoldDualR             : 12;
        const volatile uint32_t /* unused */        :  4;

        const volatile uint32_t /* unused */        : 20;
        volatile uint32_t dataHoldDualL             : 12;

        const volatile uint32_t /* unused */        :  8;
        volatile uint32_t dataHoldDual8             :  8;
        const volatile uint32_t /* unused */        : 16;

        const volatile uint32_t /* unused */        : 32;

        const volatile uint32_t dataOut             : 12;
        const volatile uint32_t /* unused */        : 20;

        const volatile uint32_t /* unused */        : 13;
        const volatile uint32_t /* unused */        : 16;
        const volatile uint32_t dmaUnderrunFlag     :  1;
        const volatile uint32_t calibGreaterEqual   :  1;
        const volatile uint32_t busyWritingSample   :  1;

        const volatile uint32_t /* unused */        : 16;
        volatile uint32_t offsetTrim                :  4;
        const volatile uint32_t /* unused */        : 12;

        const volatile uint32_t /* unused */        : 16;
        volatile outputSelect selectOutput          :  2;
        volatile uint32_t sampleHoldMode            :  1;
        const volatile uint32_t /* unused */        : 13;

        const volatile uint32_t /* unused */        : 32;

        volatile uint32_t dataSample                : 10;
        const volatile uint32_t /* unused */        : 22;

        const volatile uint32_t /* unused */        : 16;
        volatile uint32_t holdTime                  : 10;
        const volatile uint32_t /* unused */        :  6;

        const volatile uint32_t /* unused */        : 16;
        volatile uint32_t refreshTime               :  8;
        const volatile uint32_t /* unused */        :  8;
    } channel2;
};

class DAC : McuModule<dacType>, dacType
{
    public:
    DAC(){baseAddr = (dacType*)DAC1;};

    DAC* operator->(){return this->baseAddr};
    void enable(){RCC->APB1LENR |= RCC_APB1LENR_DAC12EN};



};
}