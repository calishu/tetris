#ifndef INCLUDE_GAME_CONTROLS_H_
#define INCLUDE_GAME_CONTROLS_H_

#include "driver/gpio.h"

gpio_config_t register_button(gpio_num_t gpio_num);
[[deprecated]] void control_loop();

#endif // INCLUDE_GAME_CONTROLS_H_
