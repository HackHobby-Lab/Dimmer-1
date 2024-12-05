
#include "RBDdimmer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "driver/gpio.h"
#include <string.h>
#include <stdio.h>
#include <sys/param.h>
#include <stdlib.h>
#include <ctype.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#define DIMMER_PIN 27           // GPIO pin for dimmer output
#define ZERO_CROSS_PIN 35       // GPIO pin for zero-cross detection

void app_main(void) {
    // Initialize the dimmer
    dimmertyp *myDimmer = createDimmer(DIMMER_PIN, ZERO_CROSS_PIN);
    if (myDimmer == NULL) {
        ESP_LOGE(TAG, "Failed to create dimmer!");
        return;
    }

    // Begin the dimmer setup with specific frequency (e.g., 50 Hz)
    begin(myDimmer, NORMAL_MODE, ON, 50);

    // Set the dimmer power to 50% (for example)
    setPower(myDimmer, 1);
    ESP_LOGI(TAG, "Dimmer power set to 50%%");

    // Toggle the dimmer state (ON/OFF)
    // changeState(myDimmer);
    // ESP_LOGI(TAG, "Dimmer state changed");

    // // Optionally, configure the toggle mode to cycle between min/max values
    // toggleSettings(myDimmer, 1, 99);  // Cycle between 1% and 99% power
    // ESP_LOGI(TAG, "Dimmer in toggle mode");
    
    // If you have a debug mode, you can enable it to see zero-cross and timer interrupts
    // #if DEBUG_ZERO_CROSS_SIGNAL == ISR_DEBUG_ON
    //     ESP_LOGI(TAG, "Zero-cross signal debugging enabled");
    // #endif

    // #if DEBUG_ISR_TIMER == ISR_DEBUG_ON
    //     ESP_LOGI(TAG, "Timer ISR debugging enabled");
    // #endif
}