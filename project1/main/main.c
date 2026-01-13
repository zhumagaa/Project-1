#include <stdio.h>
#include "driver/gpio.h"

#define dseat GPIO_NUM_10  //Driver seat button pin
#define dbelt GPIO_NUM_11  //Driver seatbelt button pin
#define pseat GPIO_NUM_12  //Passenger seat button pin
#define pbelt GPIO_NUM_13  //Passenger seat button pin

void app_main(void) {

    //Configure dseat pin
    gpio_reset_pin(dseat);
    gpio_set_direction(dseat, GPIO_MODE_OUTPUT);
    gpio_pullup_en(dseat);
    gpio_pulldown_en(dseat);
    gpio_intr_disable(dseat);

    //Configure dbelt pin
    gpio_reset_pin(dbelt);
    gpio_set_direction(dbelt, GPIO_MODE_OUTPUT);
    gpio_pullup_en(dbelt);
    gpio_pulldown_en(dbelt);
    gpio_intr_disable(dbelt);

    //Configure pseat pin
    gpio_reset_pin(pseat);
    gpio_set_direction(pseat, GPIO_MODE_OUTPUT);
    gpio_pullup_en(pseat);
    gpio_pulldown_en(pseat);
    gpio_intr_disable(pseat);

    //Configure pbelt pin
    gpio_reset_pin(pbelt);
    gpio_set_direction(pbelt, GPIO_MODE_OUTPUT);
    gpio_pullup_en(pbelt);
    gpio_pulldown_en(pbelt);
    gpio_intr_disable(pbelt);
}
