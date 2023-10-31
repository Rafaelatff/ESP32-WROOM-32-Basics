#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    // GPIO Settings (GPIO22 as input, GPIO2 as output)
    gpio_set_direction(GPIO_NUM_22,GPIO_MODE_INPUT);
    gpio_set_pull_mode(GPIO_NUM_22,GPIO_PULLUP_ONLY);

    gpio_set_direction(GPIO_NUM_2,GPIO_MODE_OUTPUT);

    while(1){
        // GPIO Controlling
        if (gpio_get_level(GPIO_NUM_22)) {
            // Do nothing, to be implemented
        }
        //gpio_set_level(GPIO_NUM_2,0);
        //vTaskDelay(2400); // From freeRTOS lib
        gpio_set_level(GPIO_NUM_2,1); // To test - GPIO2 is connected to the anode of blue led.
        //vTaskDelay(2400);
    }
}