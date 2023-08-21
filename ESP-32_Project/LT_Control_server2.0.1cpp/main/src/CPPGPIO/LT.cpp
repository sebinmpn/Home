#include "../include/LT.h"

#include <cstdlib>
#include <thread>
#include "esp_log.h"
#include "gpio_cxx.hpp"

using namespace idf;
using namespace std;


void fun()
{
GPIO_Output gpio(GPIONum(2));
    
             try {
        /* This line may throw an exception if the pin number is invalid.
         * Alternatively to 4, choose another output-capable pin. */
        

        while (true) {
            printf("LED ON\n");
            gpio.set_high();
            this_thread::sleep_for(std::chrono::seconds(1));
            printf("LED OFF\n");
            gpio.set_low();
            this_thread::sleep_for(std::chrono::seconds(1));
        }
    } catch (GPIOException &e) {
        printf("GPIO exception occurred: %s\n", esp_err_to_name(e.error));
        printf("stopping.\n");
    }
}
