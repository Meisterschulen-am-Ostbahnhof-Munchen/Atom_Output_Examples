/* board.c - Board-specific hooks */

/*
 * Copyright (c) 2017 Intel Corporation
 * Additional Copyright (c) 2018 Espressif Systems (Shanghai) PTE LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include "driver/gpio.h"
#include "esp_log.h"

#include "iot_button.h"
#include "board.h"

#define TAG "BOARD"

#define BUTTON_IO_NUM           32		// Pin 32.
#define BUTTON_ACTIVE_LEVEL     0		//Masse-Geschalten






static void button_tap_cb(void* arg)
{
    ESP_LOGI(TAG, "tap cb (%s)", (char *)arg);

}

static void board_button_init(void)
{
    button_handle_t btn_handle = iot_button_create(BUTTON_IO_NUM, BUTTON_ACTIVE_LEVEL);
    if (btn_handle) {
        iot_button_set_evt_cb(btn_handle, BUTTON_CB_RELEASE, button_tap_cb, "RELEASE");
    }
}

void board_init(void)
{
    board_button_init();
}
