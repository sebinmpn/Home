#include "nvs_flash.h"
#include "wifi_setup.h"
#include "server.h"

#define __cplusplus

WebServer webserver;

extern "C" void app_main(void)
{
    nvs_flash_init(); 
    wifi_init_sta();      
    webserver.start();
}