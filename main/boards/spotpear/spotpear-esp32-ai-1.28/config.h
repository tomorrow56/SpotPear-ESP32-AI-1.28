#ifndef SPOTPEAR_ESP32_AI_1_28_CONFIG_H_
#define SPOTPEAR_ESP32_AI_1_28_CONFIG_H_

#include <driver/gpio.h>
#include <driver/i2s_std.h>

// Old non-legged board: manufacturer's ESP32S3-1.28inch-AI schematic (2025-03-21).
// Separate I2S clocks: MAX98357A TX on I2S0, NP0557 RX on I2S1.
#define AUDIO_INPUT_SAMPLE_RATE 16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000
#define AUDIO_I2S_MIC_GPIO_WS GPIO_NUM_4
#define AUDIO_I2S_MIC_GPIO_SCK GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_7
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_15
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_16
// Microphone L/R is grounded in the schematic; verify capture on the actual NP0557.
#define AUDIO_I2S_MIC_SLOT_MASK I2S_STD_SLOT_LEFT
#define AUDIO_I2S_SPK_SLOT_MASK I2S_STD_SLOT_LEFT

#define BOOT_BUTTON_GPIO GPIO_NUM_0

#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 240
#define DISPLAY_MOSI_PIN GPIO_NUM_17
#define DISPLAY_CLK_PIN GPIO_NUM_14
#define DISPLAY_DC_PIN GPIO_NUM_10
#define DISPLAY_CS_PIN GPIO_NUM_13
#define DISPLAY_RST_PIN GPIO_NUM_18
#define DISPLAY_BACKLIGHT_PIN GPIO_NUM_3
// GPIO3 drives the low-side NPN backlight transistor: high = on.
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
#define DISPLAY_SPI_MODE 0
#define DISPLAY_SPI_CLOCK_HZ (40 * 1000 * 1000)
// Starting values from the existing GC9A01 240x240 profile; verify on hardware.
#define DISPLAY_RGB_ORDER LCD_RGB_ELEMENT_ORDER_BGR
#define DISPLAY_INVERT_COLOR true
#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y false
#define DISPLAY_SWAP_XY false
#define DISPLAY_OFFSET_X 0
#define DISPLAY_OFFSET_Y 0

#endif  // SPOTPEAR_ESP32_AI_1_28_CONFIG_H_
