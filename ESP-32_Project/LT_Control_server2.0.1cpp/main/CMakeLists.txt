set(SOURCES main.cpp src/CPPGPIO/cppgpio.cpp
                    src/WiFi/wifi_setup.cpp
                    src/SERVER/server.cpp
                    src/LT/LT.cpp
                    src/LED_STRIP/led_strip_encoder.cpp)

idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS . 
                    include/CPPGPIO
                    include/WiFi 
                    include/SERVER
                    include/LT
                    include/LED_STRIP)