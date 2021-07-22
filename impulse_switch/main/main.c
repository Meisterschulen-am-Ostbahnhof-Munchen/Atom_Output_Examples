/* main.c - Application main entry point */

/*
 * Copyright (c) 2017 Intel Corporation
 * Additional Copyright (c) 2018 Espressif Systems (Shanghai) PTE LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <string.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_system.h"
#include "board.h"


static const char *TAG = "impulse_switch";

#define BLINK_GPIO GPIO_NUM_19

void app_main(void)
{



    ESP_LOGI(TAG, "Initializing...");

    board_init();
	
	
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    int level = 0;
    while (true) {
        gpio_set_level(BLINK_GPIO, level);
        level = !level;
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }
}

