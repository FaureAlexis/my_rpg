/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** clicked_state
*/

#include "rpg.h"

void clicked_state_pause(main_game_t *game, sfRectangleShape *shape)
{
    for (int i = 0; i < 20; ++i) {
        display_pause(game);
        sfRenderWindow_drawRectangleShape(game->w, shape, NULL);
        sfRenderWindow_display(game->w);
    }
}
