#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdarg>

#include <string.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include <queue>

#define TAG "lightpage"

/*
-------------+
 light x gpio|
  cnt    pin | 
-------------+
 Light1  25  |
 Light2  26  |
 Light3  27  |
 Light4  14  |
 Light5  12  | 
-------------+
*/


extern "C"
{
/*define gpio pins map to the light*/
int lt_cnt_to_pin[5] = {25, 26, 27, 14, 12};

//**********************************************************************//
//**********************************************************************//
#define TAG "gpio_digital_write"
void gpio_digital_write (int pin, int state)
{ 
    ESP_LOGI(TAG, "pin:%d state : %d", pin, state);
  if (state == 1)
    gpio_set_level ( (gpio_num_t)pin,1);
  if (state == 0)
    gpio_set_level ( (gpio_num_t)pin,0);
}

void gpio_pin_mode (int pin) // pssible be an inline function 
    { 
        ESP_LOGI(TAG, "pin:%d  become output pin", pin);
        gpio_set_direction ( (gpio_num_t)pin, GPIO_MODE_OUTPUT);
    }

//**********************************************************************//
//**********************************************************************//

class Light
{
public:
    Light() {}
    // Light (Light &t);
    Light(int pin) : 
    _gpio_pin(pin)
    {
         gpio_pin_mode(_gpio_pin);
    ESP_LOGI(TAG, "pin:%d _gpio_pin : %d", pin, _gpio_pin);
     }

public:
    void set (int state) { gpio_digital_write(_gpio_pin, state); }
    bool get_state() { return _state; }

private:
    std::string name;
    int _gpio_pin;
    bool _state = 0;
};

//**********************************************************************//
//**********************************************************************//
 enum lt_state { OFF = 0, ON = 1 } ;

 class LightContext
{
public:
    void add (int gpio_pin); // make a queue of Light class
public:
    void set (int, int);
    bool get (int n) { return state[n]; }
    void update(); // update all light class

private:
    std::vector <Light> lt;
    std::vector <bool> state;

public:
    LightContext (){}
    LightContext (int pins,...);

};

//**********************************************************************//

LightContext::LightContext(int pins,...)
{
    va_list args;
    va_start (args, pins);

   for(int i = 0; i < pins; i++)
   {
        int pin = va_arg(args, int);
        ESP_LOGI(TAG, "pin:%d is get defined", pin);
        lt.push_back(Light(pin));
        state.push_back(0);
    }   
    va_end(args);
}

void LightContext::set(int _pin , int _state)
{
    state[_pin] = (bool) _state;
}

void LightContext::update()
{
    int cnt = 0;
    for(auto _lt : lt )
    {   
        // LT_state[cnt] = state[cnt];
        _lt.set(state[cnt++]);
    }

}

void LightContext::add (int gpio_pin)
{
    lt.push_back (Light(gpio_pin));
    state.push_back (0);
}

LightContext lightcontext;

void light_init()
{
    lightcontext.add(2);
    lightcontext.add(25);
    lightcontext.add(26);
}
} //extern "C"


