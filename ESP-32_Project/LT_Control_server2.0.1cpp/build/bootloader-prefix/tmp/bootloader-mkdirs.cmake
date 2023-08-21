# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/SEBIN/esp/esp-idf/components/bootloader/subproject"
  "D:/christy/ESP_32/projects/Terase_Control_Unit/Light_Control/LT_Control_server2.0.1cpp/build/bootloader"
  "D:/christy/ESP_32/projects/Terase_Control_Unit/Light_Control/LT_Control_server2.0.1cpp/build/bootloader-prefix"
  "D:/christy/ESP_32/projects/Terase_Control_Unit/Light_Control/LT_Control_server2.0.1cpp/build/bootloader-prefix/tmp"
  "D:/christy/ESP_32/projects/Terase_Control_Unit/Light_Control/LT_Control_server2.0.1cpp/build/bootloader-prefix/src/bootloader-stamp"
  "D:/christy/ESP_32/projects/Terase_Control_Unit/Light_Control/LT_Control_server2.0.1cpp/build/bootloader-prefix/src"
  "D:/christy/ESP_32/projects/Terase_Control_Unit/Light_Control/LT_Control_server2.0.1cpp/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/christy/ESP_32/projects/Terase_Control_Unit/Light_Control/LT_Control_server2.0.1cpp/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/christy/ESP_32/projects/Terase_Control_Unit/Light_Control/LT_Control_server2.0.1cpp/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
