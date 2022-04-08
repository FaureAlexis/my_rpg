/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_rect_mid_butons
*/

#include "rpg.h"

void set_rect_mid_buttons(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->mid->main_b->sprite,
    (sfIntRect){20, 560, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->top_sc_b->sprite,
    (sfIntRect){15, 380, 350, 170});
    sfSprite_setTextureRect(game->btn->mid->save_b->sprite,
    (sfIntRect){15, 10, 350, 180});
    sfSprite_setTextureRect(game->btn->mid->pause_b->sprite,
    (sfIntRect){610, 560, 190, 190});
    sfSprite_setTextureRect(game->btn->mid->right_b->sprite,
    (sfIntRect){690, 190, 350, 200});
    sfSprite_setTextureRect(game->btn->mid->mute_b->sprite,
    (sfIntRect){690, 190, 350, 200});
    sfSprite_setTextureRect(game->btn->mid->help_b->sprite,
    (sfIntRect){15, 200, 350, 170});
}

void set_rect_mid_buttons2(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->mid->settings_b->sprite,
    (sfIntRect){350, 190, 350, 200});
    sfSprite_setTextureRect(game->btn->mid->exit_b->sprite,
    (sfIntRect){350, 380, 350, 170});
    sfSprite_setTextureRect(game->btn->mid->resume_b->sprite,
    (sfIntRect){350, 10, 350, 170});
    sfSprite_setTextureRect(game->btn->mid->left_b->sprite,
    (sfIntRect){810, 740, 190, 190});
    sfSprite_setTextureRect(game->btn->mid->unmute_b->sprite,
    (sfIntRect){810, 560, 190, 190});
}
