#ifndef INCLUDE_INCLUDE_CALLBACK_H_
#define INCLUDE_INCLUDE_CALLBACK_H_

#include <stdlib.h>

#include "driver/gpio.h"
#include "game/controls.h"

typedef struct callback
{
    void *function;
    gpio_config_t activation_key;
} callback;

typedef struct callback_vec
{
    callback *callbacks;
    size_t used;
    size_t size;
} callback_vec;

void init_cb_vec(callback_vec *vec, size_t init_size);
void register_callback(callback_vec *vec, void *function, gpio_config_t activation_key);
void free_callbacks(callback_vec *vec);

#endif // INCLUDE_INCLUDE_CALLBACK_H_
