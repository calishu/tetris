#ifndef INCLUDE_GAME_CONTROLS_H_
#define INCLUDE_GAME_CONTROLS_H_

#include "driver/gpio.h"

typedef struct buttons
{
    gpio_config_t button_left;
    gpio_config_t button_right;
} buttons;

gpio_config_t init_button(gpio_num_t gpio_num);
buttons register_buttons();
void control_loop(volatile bool *stop_action);

#endif // INCLUDE_GAME_CONTROLS_H_
