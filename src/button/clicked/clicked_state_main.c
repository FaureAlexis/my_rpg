/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** clicked_state
*/

#include "rpg.h"

void clicked_state_main(main_game_t *game, sfRectangleShape *shape)
{
    for (int i = 0; i < 20; ++i) {
        display_menu(game);
        sfRenderWindow_drawRectangleShape(game->w, shape, NULL);
        sfRenderWindow_display(game->w);
    }
}
