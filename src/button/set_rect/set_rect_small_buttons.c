/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** set_rect_button
*/

#include "rpg.h"

void set_rect_small_buttons(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->sml->plus_b->sprite, SML_PLUS);
    sfSprite_setTextureRect(game->btn->sml->minus_b->sprite, SML_MINUS);
    sfSprite_setTextureRect(game->btn->sml->talk_b->sprite, SML_TALK);
    sfSprite_setTextureRect(game->btn->sml->left_b->sprite, SML_LEFT);
    sfSprite_setTextureRect(game->btn->sml->right_b->sprite, SML_RIGHT);
    sfSprite_setTextureRect(game->btn->sml->plus_r_b->sprite, SML_PLUS_R);
    sfSprite_setTextureRect(game->btn->sml->minus_r_b->sprite, SML_MINUS_R);
}
