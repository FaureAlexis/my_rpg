/*
** EPITECH PROJECT, 2022
** init_window
** File description:
** init_window
*/

#include "rpg.h"

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window = NULL;
    sfVideoMode mode = {1920, 1080, 32};
    sfImage *favicon = NULL;

    window = sfRenderWindow_create(mode, "Hasbullah le roi",
        sfResize | sfClose, NULL);
    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    favicon = sfImage_createFromFile("./assets/window/favicon.png");
    sfRenderWindow_setIcon(window, 514, 528, sfImage_getPixelsPtr(favicon));
    sfImage_destroy(favicon);
    return window;
}
