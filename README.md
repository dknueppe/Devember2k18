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

### December third.
Today I set up the Tools necessary to flash and debug the Chip. And wrote a little blinking LED program to test it

### December fourth.
I modified the Makefile to be able to compile C++ and duplicated a (slow) signal from the ADC on the DAC. Still needs
verification that it actually works.

### December fifth. 
Not so much coding as reading Documents, I'll still count that. So next to try is A/D and D/A Conversion with DMA.

### December sixth.
I got a lovely *cough* crooked sinewave output. Also more reading so can hopefully get some more speed into this. 

### December seventh.
Sadly I still can’t figure out this HAL. But I’ll invest tomorrow, this was a busy weak with an uni assignment.

### December eighth.
Just being stuck on the DAC through DMA.

### December ninth.
Further rummaging through manuals and code, did write some stuff for direct register access in hope that it either works or uncovers where I am misunderstanding the darn thing.

### December tenth
Still no concrete results in the DMA/DAC thing but I think I found another to do get sinusoidal waves, straight from the clock module, so I investigated today. I also got the hint to update my CubeMX version, which I’ll do tomorrow.

### December eleventh
Today I toyed around with parts of the RCC module in an effort to maybe generate waveforms that way, turns out you can modify plls dynamically without much hassle (at least some, have not tested all) so this might come in very useful.

### December twelveth
Today I invested more time into my Debugging setup and added the SVD file (peripheral register information). I feel like starting to get the hang of it.