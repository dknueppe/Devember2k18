#pragma once

#include "stm32.hpp"
#include "stm32h743xx.h"

namespace stm32
{
union DMA_TypeDef
{
    int i;
}

class DMA : McuModule<dmaType>
{

};
}