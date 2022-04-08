/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** set_rect_button
*/

#include "rpg.h"

void set_rect_small_buttons(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->sml->plus_b->sprite,
    (sfIntRect){15, 380, 350, 170});
    sfSprite_setTextureRect(game->btn->sml->minus_b->sprite,
    (sfIntRect){15, 10, 350, 180});
    sfSprite_setTextureRect(game->btn->sml->talk_b->sprite,
    (sfIntRect){350, 380, 350, 170});
    sfSprite_setTextureRect(game->btn->sml->accept_b->sprite,
    (sfIntRect){350, 10, 350, 170});
    sfSprite_setTextureRect(game->btn->sml->deny_b->sprite,
    (sfIntRect){20, 560, 190, 180});
    sfSprite_setTextureRect(game->btn->sml->left_b->sprite,
    (sfIntRect){690, 190, 350, 200});
    sfSprite_setTextureRect(game->btn->sml->right_b->sprite,
    (sfIntRect){610, 560, 190, 190});
    sfSprite_setTextureRect(game->btn->sml->top_b->sprite,
    (sfIntRect){350, 190, 350, 200});
    sfSprite_setTextureRect(game->btn->sml->bot_b->sprite,
    (sfIntRect){15, 200, 350, 170});
}
