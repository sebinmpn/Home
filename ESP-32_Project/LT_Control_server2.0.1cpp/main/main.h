#pragma once
#include "cppgpio.h"

// Main class used for testing only
class Main final
{
public:
    void run(void);

    CPPGPIO::GpioOutput cppLed { GPIO_NUM_2 };
    CPPGPIO::GpioInput cppButton { GPIO_NUM_12 };
}; // Main Class