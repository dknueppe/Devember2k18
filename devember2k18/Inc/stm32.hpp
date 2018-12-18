#pragma once

namespace stm32
{

template<typename T>
class McuModule
{
    protected:
    T* baseAddr;
};

enum moduleID {RCC, TIM1};

template<typename T>
class UtilModule
{
    public:
    T id;
};
