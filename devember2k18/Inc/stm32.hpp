#pragma once

#include "stm32h743xx.h"

namespace stm32
{

template<typename T>
class McuModule
{
    protected:
    volatile T* baseAddr;
};

template<typename T>
class UtilModule
{
    public:
    T id;
};

struct sample12
{
    uint16_t sample : 12;
};
}
