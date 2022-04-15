/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_pause
*/

#include "rpg.h"

int display_pause(main_game_t *game)
{
    pos_button_pause(game);
    sfRenderWindow_drawSprite(game->w, game->mnu->pause_m->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->return_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->exit_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->main_b->sprite, NULL);
    return EXIT_SUCCESS;
}
