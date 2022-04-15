/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** clicked_state
*/

#include "rpg.h"

void clicked_state_game(main_game_t *game, sfRectangleShape *shape)
{
    for (int i = 0; i < 20; ++i) {
        player_animations(game->player);
        display_game(game);
        sfRenderWindow_drawRectangleShape(game->w, shape, NULL);
        sfRenderWindow_display(game->w);
    }
}
