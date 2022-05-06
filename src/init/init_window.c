/*
** EPITECH PROJECT, 2022
** init_window
** File description:
** init_window
*/

#include "rpg.h"

sfView *init_view(sfRenderWindow *window, sfFloatRect size)
{
    sfView *view = sfView_createFromRect(size);

    if (window == NULL || view == NULL)
        return NULL;
    sfRenderWindow_setView(window, view);
    return view;
}

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window = NULL;
    sfVideoMode mode = {1920, 1080, 32};
    sfImage *favicon = NULL;

    window = sfRenderWindow_create(mode, "Hasbullah Quest", sfClose | sfResize,
    NULL);
    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    favicon = sfImage_createFromFile("./assets/window/favicon.png");
    if (!favicon)
        return NULL;
    sfRenderWindow_setIcon(window, 514, 528, sfImage_getPixelsPtr(favicon));
    sfImage_destroy(favicon);
    return window;
}
