/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_main_menu
*/

#include "rpg.h"

int display_win(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    pos_button_lose(game);
    sfRenderWindow_drawSprite(game->w, game->mnu->win_m->object->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->main_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->exit_b->sprite, NULL);
    return EXIT_SUCCESS;
}
