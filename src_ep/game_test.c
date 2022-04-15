/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "lib.h"
#include "rpg.h"
#include <SFML/Graphics.h>

void init_map_window(game_scene_t *src, char ***tab, int i)
{
    src->window = malloc(sizeof(wind_t));
    src->window->texture = sfTexture_createFromFile(tab[i][0], NULL);
    src->window->sprite = sfSprite_create();
    sfSprite_setTexture(src->window->sprite, src->window->texture, sfFalse);
}

void parce_tab(game_scene_t *src, char ***tab, int i)
{
    if (my_arraylen(tab[i]) == 3) {
        init_map_window(src, tab, i);
    }
    if (my_arraylen(tab[i]) == 7) {
        init_obstacle(src, tab, i);
    }
}

game_scene_t *init_param_scene(char ***tab)
{
    game_scene_t *src = NULL;

    if (tab) {
        src = malloc(sizeof(game_scene_t));
    } else {
        return NULL;
    }
    for (int i = 0; tab[i] != NULL; i += 1) {
        parce_tab(src, tab, i);
    }
    return src;
}

void init_event(wind_t *windo)
{
    if (windo->event.type == sfEvtClosed ||
    (windo->event.key.code == sfKeyEscape &&
    windo->event.type == sfEvtKeyReleased)) {
        sfRenderWindow_close(windo->window);
    }
}

void launch_rpg(char ***tab)
{
    game_scene_t *src = init_param_scene(tab);
    sfVideoMode mode = {1920, 1080, 32};

    src->window->window = sfRenderWindow_create(mode, "En Bas La"
    , sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(src->window->window)) {
        sfRenderWindow_clear(src->window->window, sfBlack);
        while (sfRenderWindow_pollEvent(src->window->window,
        &src->window->event)) {
            init_event(src->window);
        }
        sfRenderWindow_drawSprite(src->window->window, src->window->sprite,
        NULL);
        display_obstacle(src);
        sfRenderWindow_display(src->window->window);
    }
    sfSprite_destroy(src->window->sprite);
    sfRenderWindow_destroy(src->window->window);
}
