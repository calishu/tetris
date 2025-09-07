#include "config.h"

#include <stdint.h>

uint8_t **framebuffer_init()
{
    uint8_t **framebuf = malloc(DISPLAY_SIZE_HEIGHT * sizeof(int *));
    if (!framebuf) return NULL;

    for (size_t y = 0; y < DISPLAY_SIZE_HEIGHT; ++y)
    {
        framebuf[y] = calloc(DISPLAY_SIZE_WIDTH, sizeof(int));

        if (!framebuf[y])
        {
            for (size_t i = 0; i < y; ++i)
                free(framebuf[i]);
            free(framebuf);
            return NULL;
        }
    }

    return framebuf;
}

void framebuffer_free(int **framebuf)
{
    for (size_t i = 0; i < DISPLAY_SIZE_HEIGHT; ++i)
        free(framebuf[i]);
    free(framebuf);
}
