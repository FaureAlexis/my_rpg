/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_help
*/

#include "rpg.h"

int display_help(main_game_t *game)
{
    pos_button_help(game);
    sfRenderWindow_drawSprite(game->w, game->mnu->help_play->bg_object->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->mnu->help_play->object->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->return_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->exit_b->sprite, NULL);
    return EXIT_SUCCESS;
}
