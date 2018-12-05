# Devember2k18
This is my repository for the Devember2k18 challange.

## Goals 
* Getting more knowledge of baremetal setups (namely STM32)
* Mainly focusing on the Analog periphirals in an effort to build something resembling a basic Network Analyzer
* Extended Goal: Try to use C++
## Tools
### Software
* VS Code (serving as the IDE)
* OpenOCD (for flashing and debugging)
* STM32CubeMX
### Harware
* STM32 NucleoH743ZI
* Oscilloscope (for measurement verification)
## Libraries
* STM32 HAL
* C++ STL (where possible and appropriate)

## LOGs

December third.

Today I set up the Tools necessary to flash and debug the Chip. And wrote a little blinking LED program to test it

December fourth.

I modified the Makefile to be able to compile C++ and duplicated a (slow) signal from the ADC on the DAC. Still needs
verification that it actually works.