/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** set_rect_button
*/

#include "rpg.h"

void set_rect_small_buttons2(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->sml->plus_r_b->sprite,
    (sfIntRect){25, 940, 150, 150});
    sfSprite_setTextureRect(game->btn->sml->minus_r_b->sprite,
    (sfIntRect){175, 940, 150, 150});
}

void set_rect_small_buttons(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->sml->plus_b->sprite,
    (sfIntRect){25, 940, 150, 150});
    sfSprite_setTextureRect(game->btn->sml->minus_b->sprite,
    (sfIntRect){175, 940, 150, 150});
    sfSprite_setTextureRect(game->btn->sml->talk_b->sprite,
    (sfIntRect){325, 940, 150, 150});
    sfSprite_setTextureRect(game->btn->sml->accept_b->sprite,
    (sfIntRect){475, 940, 150, 150});
    sfSprite_setTextureRect(game->btn->sml->deny_b->sprite,
    (sfIntRect){610, 940, 150, 150});
    sfSprite_setTextureRect(game->btn->sml->left_b->sprite,
    (sfIntRect){755, 940, 150, 150});
    sfSprite_setTextureRect(game->btn->sml->right_b->sprite,
    (sfIntRect){890, 940, 150, 150});
    sfSprite_setTextureRect(game->btn->sml->top_b->sprite,
    (sfIntRect){1045, 940, 150, 150});
    sfSprite_setTextureRect(game->btn->sml->bot_b->sprite,
    (sfIntRect){1190, 940, 150, 150});
    set_rect_small_buttons2(game);
}