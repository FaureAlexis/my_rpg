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
    (sfIntRect){35, 570, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->top_sc_b->sprite,
    (sfIntRect){230, 570, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->save_b->sprite,
    (sfIntRect){435, 568, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->pause_b->sprite,
    (sfIntRect){625, 570, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->right_b->sprite,
    (sfIntRect){825, 570, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->mute_b->sprite,
    (sfIntRect){1025, 570, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->help_b->sprite,
    (sfIntRect){35, 755, 190, 180});
}

void set_rect_mid_buttons2(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->mid->settings_b->sprite,
    (sfIntRect){235, 755, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->exit_b->sprite,
    (sfIntRect){430, 755, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->resume_b->sprite,
    (sfIntRect){625, 755, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->left_b->sprite,
    (sfIntRect){825, 755, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->unmute_b->sprite,
    (sfIntRect){1025, 755, 190, 180});
}
