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
    (sfIntRect){215, 560, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->save_b->sprite,
    (sfIntRect){415, 560, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->pause_b->sprite,
    (sfIntRect){615, 560, 190, 190});
    sfSprite_setTextureRect(game->btn->mid->right_b->sprite,
    (sfIntRect){815, 560, 190, 190});
    sfSprite_setTextureRect(game->btn->mid->mute_b->sprite,
    (sfIntRect){1015, 560, 190, 190});
    sfSprite_setTextureRect(game->btn->mid->help_b->sprite,
    (sfIntRect){15, 750, 190, 180});
}

void set_rect_mid_buttons2(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->mid->settings_b->sprite,
    (sfIntRect){215, 750, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->exit_b->sprite,
    (sfIntRect){415, 750, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->resume_b->sprite,
    (sfIntRect){615, 750, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->left_b->sprite,
    (sfIntRect){815, 750, 190, 180});
    sfSprite_setTextureRect(game->btn->mid->unmute_b->sprite,
    (sfIntRect){1015, 750, 190, 180});
}
