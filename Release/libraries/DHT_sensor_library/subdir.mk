################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
I:\Sloeber\arduinoPlugin\libraries\DHT_sensor_library\1.3.8\DHT.cpp \
I:\Sloeber\arduinoPlugin\libraries\DHT_sensor_library\1.3.8\DHT_U.cpp 

LINK_OBJ += \
.\libraries\DHT_sensor_library\DHT.cpp.o \
.\libraries\DHT_sensor_library\DHT_U.cpp.o 

CPP_DEPS += \
.\libraries\DHT_sensor_library\DHT.cpp.d \
.\libraries\DHT_sensor_library\DHT_U.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\DHT_sensor_library\DHT.cpp.o: I:\Sloeber\arduinoPlugin\libraries\DHT_sensor_library\1.3.8\DHT.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"I:\Sloeber\arduinoPlugin\packages\esp32\tools\xtensa-esp32-elf-gcc\1.22.0-80-g6c4433a-5.2.0/bin/xtensa-esp32-elf-g++" -DESP_PLATFORM -DMBEDTLS_CONFIG_FILE="mbedtls/esp_config.h" -DHAVE_CONFIG_H -DGCC_NOT_5_2_0=0 -DWITH_POSIX "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/config" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/app_trace" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/app_update" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/asio" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/bootloader_support" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/bt" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/coap" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/console" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/driver" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp-tls" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp32" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_adc_cal" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_event" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_http_client" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_http_server" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_https_ota" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_ringbuf" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/ethernet" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/expat" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/fatfs" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/freemodbus" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/freertos" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/heap" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/idf_test" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/jsmn" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/json" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/libsodium" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/log" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/lwip" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/mbedtls" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/mdns" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/micro-ecc" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/mqtt" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/newlib" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/nghttp" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/nvs_flash" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/openssl" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/protobuf-c" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/protocomm" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/pthread" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/sdmmc" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/smartconfig_ack" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/soc" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/spi_flash" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/spiffs" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/tcp_transport" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/tcpip_adapter" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/ulp" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/vfs" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/wear_levelling" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/wifi_provisioning" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/wpa_supplicant" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/xtensa-debug-module" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp-face" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp32-camera" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp-face" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/fb_gfx" -std=gnu++11 -Os -g3 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -Wall -Werror=all -Wextra -Wno-error=maybe-uninitialized -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-missing-field-initializers -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=160000000L -DARDUINO=10802 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ESP32 -DARDUINO_BOARD="\"ESP32_DEV\"" -DARDUINO_VARIANT="esp32"  -DESP32 -DCORE_DEBUG_LEVEL=5    -I"I:\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.4\cores\esp32" -I"I:\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.4\variants\esp32" -I"I:\Sloeber\arduinoPlugin\libraries\DHT_sensor_library\1.3.8" -I"I:\Sloeber\arduinoPlugin\libraries\Adafruit_Unified_Sensor\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\DHT_sensor_library\DHT_U.cpp.o: I:\Sloeber\arduinoPlugin\libraries\DHT_sensor_library\1.3.8\DHT_U.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"I:\Sloeber\arduinoPlugin\packages\esp32\tools\xtensa-esp32-elf-gcc\1.22.0-80-g6c4433a-5.2.0/bin/xtensa-esp32-elf-g++" -DESP_PLATFORM -DMBEDTLS_CONFIG_FILE="mbedtls/esp_config.h" -DHAVE_CONFIG_H -DGCC_NOT_5_2_0=0 -DWITH_POSIX "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/config" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/app_trace" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/app_update" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/asio" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/bootloader_support" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/bt" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/coap" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/console" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/driver" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp-tls" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp32" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_adc_cal" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_event" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_http_client" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_http_server" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_https_ota" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp_ringbuf" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/ethernet" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/expat" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/fatfs" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/freemodbus" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/freertos" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/heap" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/idf_test" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/jsmn" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/json" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/libsodium" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/log" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/lwip" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/mbedtls" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/mdns" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/micro-ecc" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/mqtt" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/newlib" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/nghttp" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/nvs_flash" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/openssl" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/protobuf-c" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/protocomm" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/pthread" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/sdmmc" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/smartconfig_ack" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/soc" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/spi_flash" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/spiffs" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/tcp_transport" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/tcpip_adapter" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/ulp" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/vfs" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/wear_levelling" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/wifi_provisioning" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/wpa_supplicant" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/xtensa-debug-module" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp-face" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp32-camera" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/esp-face" "-II:\Sloeber\/arduinoPlugin/packages/esp32/hardware/esp32/1.0.4/tools/sdk/include/fb_gfx" -std=gnu++11 -Os -g3 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -Wall -Werror=all -Wextra -Wno-error=maybe-uninitialized -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-missing-field-initializers -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=160000000L -DARDUINO=10802 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ESP32 -DARDUINO_BOARD="\"ESP32_DEV\"" -DARDUINO_VARIANT="esp32"  -DESP32 -DCORE_DEBUG_LEVEL=5    -I"I:\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.4\cores\esp32" -I"I:\Sloeber\arduinoPlugin\packages\esp32\hardware\esp32\1.0.4\variants\esp32" -I"I:\Sloeber\arduinoPlugin\libraries\DHT_sensor_library\1.3.8" -I"I:\Sloeber\arduinoPlugin\libraries\Adafruit_Unified_Sensor\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

