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
    sfSprite_setScale(game->mnu->keybind_m->object->sprite, MENU_BG_SIZE);
    sfSprite_setPosition(game->mnu->keybind_m->object->sprite,
    SETTINGS_BG_POS);
    sfRenderWindow_drawSprite(game->w, game->mnu->keybind_m->bg_object->sprite,
    NULL);

    pos_button_keybind(game);
    sfRenderWindow_drawSprite(game->w, game->mnu->keybind_m->bg_object->sprite,
    NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->return_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->exit_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->help_b->sprite, NULL);
    return EXIT_SUCCESS;
}
