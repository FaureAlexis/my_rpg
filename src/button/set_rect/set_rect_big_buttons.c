/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_rect_big_buttons
*/

#include "rpg.h"

void set_rect_big_buttons(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->big->help_b->sprite, BIG_HELP);
    sfSprite_setTextureRect(game->btn->big->settings_b->sprite, BIG_SETTINGS);
    sfSprite_setTextureRect(game->btn->big->return_b->sprite, BIG_RETURN);
    sfSprite_setTextureRect(game->btn->big->play_b->sprite, BIG_PLAY);
    sfSprite_setTextureRect(game->btn->big->exit_b->sprite, BIG_EXIT);
    sfSprite_setTextureRect(game->btn->big->newsave_b->sprite, BIG_NEWSAVE);
    sfSprite_setTextureRect(game->btn->big->load_b->sprite, BIG_LOAD);
}
