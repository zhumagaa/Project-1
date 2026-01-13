#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"


#define dseat GPIO_NUM_10  //Driver seat button pin
#define dbelt GPIO_NUM_11  //Driver seatbelt button pin
#define pseat GPIO_NUM_12  //Passenger seat button pin
#define pbelt GPIO_NUM_13  //Passenger seat button pin


void print_status() {                               //Define a function for printing reason for car not starting
    if (gpio_get_level(dseat)){                     //Check if driver is seated
        printf("Driver Not Seated \n");             //Print if driver not seated
    }

    if (gpio_get_level(dbelt)){                     //Check if driver is buckled
        printf("Driver Not Buckled \n");            //Print if driver not buckled
    }

    if (gpio_get_level(pseat)){                     //Check if passenger is seated
        printf("Passenger Not Seated \n");          //Print if passenger not seated
    }

    if (gpio_get_level(dbelt)){                     //Check if passenger is buckled
        printf("Passenger Not Buckled \n");         //Print if passenger not buckled
    }
}


void app_main(void) {

    //Configure dseat pin
    gpio_reset_pin(dseat);
    gpio_set_direction(dseat, GPIO_MODE_INPUT);
    gpio_pullup_en(dseat);
    gpio_pulldown_en(dseat);

    //Configure dbelt pin
    gpio_reset_pin(dbelt);
    gpio_set_direction(dbelt, GPIO_MODE_INPUT);
    gpio_pullup_en(dbelt);
    gpio_pulldown_en(dbelt);

    //Configure pseat pin
    gpio_reset_pin(pseat);
    gpio_set_direction(pseat, GPIO_MODE_INPUT);
    gpio_pullup_en(pseat);
    gpio_pulldown_en(pseat);

    //Configure pbelt pin
    gpio_reset_pin(pbelt);
    gpio_set_direction(pbelt, GPIO_MODE_OUTPUT);
    gpio_pullup_en(pbelt);
    gpio_pulldown_en(pbelt);
    gpio_intr_disable(pbelt);
    
    
    print_status();

}