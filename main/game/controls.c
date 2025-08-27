#include "game/controls.h"

#include "esp_log.h"

gpio_config_t register_button(gpio_num_t gpio_num)
{
    gpio_config_t button_conf = {
        .pin_bit_mask = (1ULL << gpio_num),
        .mode         = GPIO_MODE_INPUT_OUTPUT,
        .pull_up_en   = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_ENABLE,
        .intr_type    = GPIO_INTR_DISABLE};

    gpio_config(&button_conf);
    return button_conf;
}
