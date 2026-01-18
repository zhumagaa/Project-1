#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"


//Would be preferable for these to be active high

#define dseat GPIO_NUM_4                            //Driver seat button pin
#define dbelt GPIO_NUM_6                            //Driver seatbelt button pin
#define pseat GPIO_NUM_5                            //Passenger seat button pin
#define pbelt GPIO_NUM_7                            //Passenger seat button pin
#define transmission GPIO_NUM_10                    //Passenger seat button pin
#define gLED GPIO_NUM_13                            //Green LED pin
#define rLED GPIO_NUM_14                            //Red LED pin
#define alarm GPIO_NUM_12                           //Alarm pin


void print_status() {                               //Define a function for printing reason for car not starting
    if (gpio_get_level(dseat) == 0){                //Check if driver is seated
        printf("Driver Not Seated \n");             //Print if driver not seated
    }

    if (gpio_get_level(dbelt) == 0){                //Check if driver is buckled
        printf("Driver Not Buckled \n");            //Print if driver not buckled
    }

    if (gpio_get_level(pseat) == 0){                //Check if passenger is seated
        printf("Passenger Not Seated \n");          //Print if passenger not seated
    }

    if (gpio_get_level(pbelt) == 0){                //Check if passenger is buckled
        printf("Passenger Not Buckled \n");         //Print if passenger not buckled
    }
}


//Configured for active high
bool ready() {                                      //Define a function to check if all conditions are fufilled
    return gpio_get_level(dseat) 
    && gpio_get_level(dbelt) 
    && gpio_get_level(pseat) 
    && gpio_get_level(pbelt);
}


void app_main(void) {

    //Configure dseat pin
    gpio_reset_pin(dseat);
    gpio_set_direction(dseat, GPIO_MODE_INPUT);
    gpio_pulldown_en(dseat);

    //Configure dbelt pin
    gpio_reset_pin(dbelt);
    gpio_set_direction(dbelt, GPIO_MODE_INPUT);
    gpio_pulldown_en(dbelt);

    //Configure pseat pin
    gpio_reset_pin(pseat);
    gpio_set_direction(pseat, GPIO_MODE_INPUT);
    gpio_pulldown_en(pseat);

    //Configure pbelt pin
    gpio_reset_pin(pbelt);
    gpio_set_direction(pbelt, GPIO_MODE_INPUT);
    gpio_pulldown_en(pbelt);

    //Configure transmission pin
    gpio_reset_pin(transmission);
    gpio_set_direction(transmission, GPIO_MODE_INPUT);
    gpio_pulldown_en(transmission);

    //Configure gLED pin
    gpio_reset_pin(gLED);
    gpio_set_direction(gLED, GPIO_MODE_OUTPUT);

    //Configure rLED pin
    gpio_reset_pin(rLED);
    gpio_set_direction(rLED, GPIO_MODE_OUTPUT);

    //Configure alarm pin
    gpio_reset_pin(alarm);
    gpio_set_direction(alarm, GPIO_MODE_OUTPUT);

    while(1) {                                      //Start the actual process
        if (gpio_get_level(dseat) == 1) {
            printf("Welcome to enhanced alarm system model 218-W25. \n");
            while(1) {
                while (ready() == 1) {
                    gpio_set_level(gLED, 1);
                    if (gpio_get_level(transmission) == 1) {
                        gpio_set_level(rLED, 1);
                        gpio_set_level(gLED, 0);
                        printf("Engine Started \n");
                        while(1) {
                            vTaskDelay(20/portTICK_PERIOD_MS);
                        }
                    }
                    vTaskDelay(20/portTICK_PERIOD_MS);
                }
                gpio_set_level(gLED, 0);
                if (gpio_get_level(transmission) == 1) {
                    gpio_set_level(alarm, 1);
                    print_status();
                    vTaskDelay(500/portTICK_PERIOD_MS);
                    gpio_set_level(alarm, 0);
                    while(1) {
                        vTaskDelay(20/portTICK_PERIOD_MS);
                    }
                }
                vTaskDelay(20/portTICK_PERIOD_MS);
            }
        }
        if (gpio_get_level(transmission) == 1) {
            gpio_set_level(alarm, 1);
            print_status();
            vTaskDelay(500/portTICK_PERIOD_MS);
            gpio_set_level(alarm, 0);
            while(1) {
                vTaskDelay(20/portTICK_PERIOD_MS);
            }
        }
        vTaskDelay(20/portTICK_PERIOD_MS);
    }
}