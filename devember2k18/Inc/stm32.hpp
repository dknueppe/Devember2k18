#pragma once

#include "stm32h743xx.h"

namespace stm32
{

template<typename T>
class McuModule
{
    protected:
    T* baseAddr;
};

template<typename T>
class UtilModule
{
    public:
    T id;
};
}