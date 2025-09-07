#include "callback.h"
#include "driver/gpio.h"

void init_cb_vec(callback_vec *vec, size_t init_size)
{
    vec->callbacks = malloc(init_size * sizeof(void *));
    vec->used      = 0;
    vec->size      = init_size;
};

void register_callback(callback_vec *vec, void (*function)(void))
{
    if (vec->used == vec->size)
    {
        vec->size += 1;
        vec->callbacks = realloc(vec->callbacks, vec->size * sizeof(void *));
    }
    callback cb                 = {.function = function};
    vec->callbacks[vec->used++] = cb;
}

void free_callbacks(callback_vec *vec)
{
    free(vec->callbacks);
    vec->callbacks = NULL;
    vec->used      = 0;
    vec->size      = 0;
}
