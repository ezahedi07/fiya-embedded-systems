################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\Button.cpp \
..\sloeber.ino.cpp 

LINK_OBJ += \
.\Button.cpp.o \
.\sloeber.ino.cpp.o 

CPP_DEPS += \
.\Button.cpp.d \
.\sloeber.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Button.cpp.o: ..\Button.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\cmpez\Sloeber\arduinoPlugin\packages\esp32\tools\xtensa-esp32-elf-gcc\1.22.0-80-g6c4433a-5.2.0/bin/xtensa-esp32-elf-g++" -DESP_PLATFORM -DMBEDTLS_CONFIG_FILE="mbedtls/esp_config.h" -DHAVE_CONFIG_H "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/config" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/app_trace" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/app_update" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/asio" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/bootloader_support" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/bt" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/coap" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/console" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/driver" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp-tls" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp32" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_adc_cal" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_event" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_http_client" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_http_server" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_https_ota" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_https_server" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_ringbuf" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/ethernet" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/expat" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/fatfs" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/freemodbus" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/freertos" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/heap" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/idf_test" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/jsmn" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/json" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/libsodium" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/log" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/lwip" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/mbedtls" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/mdns" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/micro-ecc" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/mqtt" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/newlib" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/nghttp" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/nvs_flash" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/openssl" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/protobuf-c" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/protocomm" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/pthread" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/sdmmc" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/smartconfig_ack" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/soc" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/spi_flash" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/spiffs" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/tcp_transport" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/tcpip_adapter" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/ulp" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/unity" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/vfs" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/wear_levelling" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/wifi_provisioning" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/wpa_supplicant" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/xtensa-debug-module" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp32-camera" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp-face" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/fb_gfx" -std=gnu++11 -fno-exceptions -Os -g3 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -Wall -Werror=all -Wextra -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=160000000L -DARDUINO=10802 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ESP32 -DARDUINO_BOARD="\"ESP32_DEV\"" -DARDUINO_VARIANT="esp32"  -DESP32 -DCORE_DEBUG_LEVEL=5    -I"C:\Users\cmpez\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.1\cores\esp32" -I"C:\Users\cmpez\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.1\variants\esp32" -I"C:\Users\cmpez\Sloeber\arduinoPlugin\libraries\DHT_sensor_library_for_ESPx\1.17.0" -I"C:\Users\cmpez\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.1\libraries\Preferences\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

sloeber.ino.cpp.o: ..\sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\cmpez\Sloeber\arduinoPlugin\packages\esp32\tools\xtensa-esp32-elf-gcc\1.22.0-80-g6c4433a-5.2.0/bin/xtensa-esp32-elf-g++" -DESP_PLATFORM -DMBEDTLS_CONFIG_FILE="mbedtls/esp_config.h" -DHAVE_CONFIG_H "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/config" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/app_trace" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/app_update" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/asio" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/bootloader_support" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/bt" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/coap" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/console" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/driver" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp-tls" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp32" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_adc_cal" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_event" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_http_client" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_http_server" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_https_ota" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_https_server" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp_ringbuf" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/ethernet" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/expat" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/fatfs" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/freemodbus" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/freertos" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/heap" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/idf_test" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/jsmn" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/json" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/libsodium" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/log" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/lwip" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/mbedtls" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/mdns" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/micro-ecc" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/mqtt" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/newlib" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/nghttp" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/nvs_flash" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/openssl" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/protobuf-c" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/protocomm" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/pthread" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/sdmmc" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/smartconfig_ack" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/soc" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/spi_flash" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/spiffs" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/tcp_transport" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/tcpip_adapter" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/ulp" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/unity" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/vfs" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/wear_levelling" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/wifi_provisioning" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/wpa_supplicant" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/xtensa-debug-module" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp32-camera" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/esp-face" "-IC:\Users\cmpez\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.1/tools/sdk/include/fb_gfx" -std=gnu++11 -fno-exceptions -Os -g3 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -Wall -Werror=all -Wextra -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=160000000L -DARDUINO=10802 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ESP32 -DARDUINO_BOARD="\"ESP32_DEV\"" -DARDUINO_VARIANT="esp32"  -DESP32 -DCORE_DEBUG_LEVEL=5    -I"C:\Users\cmpez\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.1\cores\esp32" -I"C:\Users\cmpez\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.1\variants\esp32" -I"C:\Users\cmpez\Sloeber\arduinoPlugin\libraries\DHT_sensor_library_for_ESPx\1.17.0" -I"C:\Users\cmpez\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.1\libraries\Preferences\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"

	@echo 'Finished building: $<'
	@echo ' '


