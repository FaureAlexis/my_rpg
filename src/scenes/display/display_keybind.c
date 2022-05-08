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
    sfSprite_setScale(game->mnu->keybind_m->object->sprite, KEYBIND_SIZE);
    sfSprite_setPosition(game->mnu->keybind_m->object->sprite, KEYBIND_POS);
    sfRenderWindow_drawSprite(game->w, game->mnu->keybind_m->bg_object->sprite,
    NULL);
    sfRenderWindow_drawSprite(game->w, game->mnu->keybind_m->bg_object->sprite,
    NULL);
    sfRenderWindow_drawSprite(game->w, game->mnu->keybind_m->object->sprite,
    NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->return_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->exit_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->help_b->sprite, NULL);
    return EXIT_SUCCESS;
}
