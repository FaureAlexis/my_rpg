/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_main_menu
*/

#include "rpg.h"

int display_keybind(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    pos_button_keybind(game);
    sfRenderWindow_drawSprite(game->w, game->mnu->settings->bg_object->sprite,
    NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->return_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->exit_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->help_b->sprite, NULL);
    return EXIT_SUCCESS;
}
