#pragma once

#include "stm32.hpp"
#include "stm32h743xx.h"

namespace stm32
{
typedef uint32_t timType;

class TIM : McuModule<timType>
{

};
}