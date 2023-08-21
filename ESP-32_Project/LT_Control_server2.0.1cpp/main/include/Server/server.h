#pragma once

#include <stdio.h>
#include<string>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include <netdb.h>
#include "nvs_flash.h"
#include "esp_netif.h"

#include "esp_http_server.h"
#include "page.h"
#include "page_lt.h"
#include "LT.h"

extern "C"
{

#define TAG "Server"

//**********************************************************************//

esp_err_t get_handler (httpd_req_t *req);
esp_err_t get_handler_LT (httpd_req_t *req);
esp_err_t get_handler_STRIP (httpd_req_t *req);

//**********************************************************************//

httpd_uri_t uri_get = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = get_handler,
    .user_ctx = NULL};

httpd_uri_t uri_get_LT = {
    .uri = "/LT",
    .method = HTTP_GET,
    .handler = get_handler_LT,
    .user_ctx = NULL};

httpd_uri_t uri_get_STRIP = {
    .uri = "/STRIP",
    .method = HTTP_GET,
    .handler = get_handler_STRIP,
    .user_ctx = NULL};

//**********************************************************************//
//**********************************************************************//

esp_err_t get_handler (httpd_req_t *req)
{   
  httpd_resp_send (req, home_page, HTTPD_RESP_USE_STRLEN);
  return ESP_OK;
}

//**********************************************************************//



esp_err_t get_handler_LT (httpd_req_t *req)
{ 
    char *buf;
    size_t buf_len;
    
     // Read the URI line and get the parameters
    buf_len = httpd_req_get_url_query_len(req) + 1;
    if (buf_len > 1) 
    {    
        buf = (char*)malloc(buf_len);
        if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) 
        {
            ESP_LOGI(TAG, "Found URL query: %s", buf); 
            char param[32];
            
            if (httpd_query_key_value(buf, "lt1", param, sizeof(param)) == ESP_OK) 
            {
                lightcontext.set(0, atoi (param));              
            }
        }
        free(buf);
    }
    lightcontext.update();

    httpd_resp_send (req, LT_page(), HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

//**********************************************************************//

esp_err_t get_handler_STRIP(httpd_req_t *req)
{
    // strip_ctl (req);
    return ESP_OK;
}

//**********************************************************************//
//**********************************************************************//

class WebServer
{
private:  
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
public: 
    void start();
    void stop();
};

//**********************************************************************//

void WebServer::start()
 {   
    light_init();
    
    if (httpd_start (&server, &config) == ESP_OK)
    {        
        httpd_register_uri_handler (server, &uri_get);      
        httpd_register_uri_handler (server, &uri_get_LT);
    }    
    ESP_LOGI("Server ", "started");
}

void WebServer::stop() { if(server) httpd_stop(server); }

//**********************************************************************//
//**********************************************************************//

}//extern "C"