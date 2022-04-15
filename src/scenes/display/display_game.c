/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_main_menu
*/

#include "rpg.h"

int display_game(main_game_t *game)
{
    pos_button_game(game);
    // sfRenderWindow_drawSprite(game->w, game->mnu->gameplay->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->pause_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->player->sprite, NULL);
    return EXIT_SUCCESS;
}
