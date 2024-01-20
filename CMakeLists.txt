cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico-tv-blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

# Initialize the SDK
pico_sdk_init()

add_executable(pico-tv-blink
	pico-tv-blink.c 
)

#pico_generate_pio_header(pico-tv-blink ${CMAKE_CURRENT_LIST_DIR}/tv-blink.pio)

target_include_directories(pico-tv-blink PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts
)

target_link_libraries(pico-tv-blink pico_stdlib)
#target_link_libraries(pico-tv-blink pico_multicore)
#target_link_libraries(pico-tv-blink hardware_uart)
#target_link_libraries(pico-tv-blink hardware_pwm)
#target_link_libraries(pico-tv-blink hardware_pio)
#target_link_libraries(pico-tv-blink hardware_i2c)

pico_enable_stdio_usb(pico-tv-blink 1)
pico_enable_stdio_uart(pico-tv-blink 1)

pico_add_extra_outputs(pico-tv-blink)


	
