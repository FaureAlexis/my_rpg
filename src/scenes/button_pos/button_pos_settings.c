/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

void pos_button_settings_two(main_game_t *game)
{
    sfSprite_setPosition(game->btn->sml->plus_b->sprite,
    (sfVector2f){1200, 600});
    sfRectangleShape_setPosition(game->btn->sml->plus_b->shape,
    (sfVector2f){1200, 600});
    sfSprite_setPosition(game->btn->sml->minus_b->sprite,
    (sfVector2f){950, 600});
    sfRectangleShape_setPosition(game->btn->sml->minus_b->shape,
    (sfVector2f){950, 600});
}
