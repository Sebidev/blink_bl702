/**
 * Copyright (c) 2016-2021 Bouffalolab Co., Ltd.
 *
 * Contact information:
 * web site:    https://www.bouffalolab.com/
 */

#include <FreeRTOS.h>
#include <task.h>

#include <aos/kernel.h>
#include <aos/yloop.h>
#include <cli.h>
#include <blog.h>
#include <stdlib.h>
#include <bl_gpio.h>
#include <hosal_gpio.h>
#include <hosal_dma.h>


/**
 *  APP main entry
 */

#define GPIO_LED_PIN 27

void blink_test(void *param)
{
    uint8_t value = 1;
    while(1) {
        bl_gpio_enable_output(GPIO_LED_PIN, 0, 0);
        bl_gpio_output_set(GPIO_LED_PIN, value);
        value = !value;
        vTaskDelay(1000);
    }
}

void main(void)
{
    xTaskCreate(blink_test, "blink", 1024, NULL, 15, NULL);
}
