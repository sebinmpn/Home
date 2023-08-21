#include "wifi_setup.h"

void wifi_init_sta(void)
{
    s_wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
    ESP_ERROR_CHECK (esp_event_handler_instance_register (WIFI_EVENT,    ESP_EVENT_ANY_ID, &event_handler,sta_netif,&instance_any_id));
    ESP_ERROR_CHECK (esp_event_handler_instance_register (  IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler,sta_netif,&instance_got_ip));

    // wifi_config_t wifi_config = {
    //     .sta = {
    //         .ssid = EXAMPLE_WIFI_SSID,
    //         .password = EXAMPLE_WIFI_PASS,
    //         /* Setting a password implies station will connect to all security modes including WEP/WPA.
    //          * However these modes are deprecated and not advisable to be used. Incase your Access point
    //          * doesn't support WPA2, these mode can be enabled by commenting below line */
	//      .threshold.authmode = WIFI_AUTH_WPA2_PSK,
    //     },
    // };
//**************************************************************************//
        uint8_t _ssid[32]     = "Keralavision-61";
        uint8_t _password[64] = "francis1779";

      wifi_config_t wifi_config;
      
      int i_cnt = 0;
    for (auto i : _ssid)
        wifi_config.sta.ssid[i_cnt++] = (uint8_t) i; //EXAMPLE_WIFI_SSID;
    
    i_cnt = 0;
    for (auto i : _password)
    {
        wifi_config.sta.password[i_cnt++] = (uint8_t) i; //EXAMPLE_WIFI_PASS;
    }
        wifi_config.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;
//**************************************************************************//

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start() );

    ESP_LOGI(TAG, "wifi_init_sta finished.");

    /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
     * number of re-tries (WIFI_FAIL_BIT). The bits are set by event_handler() (see above) */
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
            WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
            pdFALSE,
            pdFALSE,
            portMAX_DELAY);

    /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
     * happened. */
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s",
                 EXAMPLE_WIFI_SSID, EXAMPLE_WIFI_PASS);
    } else if (bits & WIFI_FAIL_BIT) {
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
                 EXAMPLE_WIFI_SSID, EXAMPLE_WIFI_PASS);
    } else {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }

    /* The event will not be processed after unregister */
    // ESP_ERROR_CHECK(esp_event_handler_instance_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, instance_got_ip));
    // ESP_ERROR_CHECK(esp_event_handler_instance_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, instance_any_id));
    // vEventGroupDelete(s_wifi_event_group);
}
