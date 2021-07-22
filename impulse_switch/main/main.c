#include "freertos/FreeRTOS.h"

#include "driver/gpio.h"



void app_main(void)
{

    gpio_set_direction(GPIO_NUM_19, GPIO_MODE_OUTPUT);
    int level = 0;
    while (true) {
        gpio_set_level(GPIO_NUM_19, level);
        level = !level;
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }
}

