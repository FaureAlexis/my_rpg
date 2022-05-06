/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_rect_mid_butons
*/

#include "rpg.h"

void set_rect_mid_buttons(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->mid->main_b->sprite, MID_MAIN);
    sfSprite_setTextureRect(game->btn->mid->pause_b->sprite, MID_PAUSE);
    sfSprite_setTextureRect(game->btn->mid->mute_b->sprite, MID_MUTE);
    sfSprite_setTextureRect(game->btn->mid->help_b->sprite, MID_HELP);
    sfSprite_setTextureRect(game->btn->mid->exit_b->sprite, MID_EXIT);
    sfSprite_setTextureRect(game->btn->mid->unmute_b->sprite, MID_UNMUTE);
    sfSprite_setTextureRect(game->btn->mid->keybind_b->sprite, MID_KEYBIND);
}
