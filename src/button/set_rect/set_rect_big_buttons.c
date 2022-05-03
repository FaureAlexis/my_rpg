/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_rect_big_buttons
*/

#include "rpg.h"

void set_rect_big_buttons(main_game_t *game)
{
    sfSprite_setTextureRect(game->btn->big->score_b->sprite,
    (sfIntRect){35, 10, 330, 170});
    sfSprite_setTextureRect(game->btn->big->resume_b->sprite,
    (sfIntRect){330, 10, 330, 170});
    sfSprite_setTextureRect(game->btn->big->help_b->sprite,
    (sfIntRect){35, 195, 330, 170});
    sfSprite_setTextureRect(game->btn->big->settings_b->sprite,
    (sfIntRect){365, 195, 330, 180});
    sfSprite_setTextureRect(game->btn->big->return_b->sprite,
    (sfIntRect){705, 195, 330, 180});
    sfSprite_setTextureRect(game->btn->big->play_b->sprite,
    (sfIntRect){35, 390, 330, 170});
    sfSprite_setTextureRect(game->btn->big->exit_b->sprite,
    (sfIntRect){365, 390, 330, 170});
    sfSprite_setTextureRect(game->btn->big->newsave_b->sprite,
    (sfIntRect){710, 390, 330, 170});
    sfSprite_setTextureRect(game->btn->big->load_b->sprite,
    (sfIntRect){1040, 10, 330, 170});
}
