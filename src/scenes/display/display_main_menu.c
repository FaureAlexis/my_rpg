/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_main_menu
*/

#include "rpg.h"

int display_menu(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    pos_button_main(game);
    sfRenderWindow_drawSprite(game->w, game->mnu->main->object->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->play_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, \
    game->btn->big->settings_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->exit_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->help_b->sprite, NULL);
    return EXIT_SUCCESS;
}
