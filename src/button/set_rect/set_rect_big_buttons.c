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
    (sfIntRect){15, 10, 350, 180});
    sfSprite_setTextureRect(game->btn->big->resume_b->sprite,
    (sfIntRect){350, 10, 350, 170});
    sfSprite_setTextureRect(game->btn->big->help_b->sprite,
    (sfIntRect){15, 200, 350, 170});
    sfSprite_setTextureRect(game->btn->big->settings_b->sprite,
    (sfIntRect){350, 190, 350, 200});
    sfSprite_setTextureRect(game->btn->big->return_b->sprite,
    (sfIntRect){690, 190, 350, 200});
    sfSprite_setTextureRect(game->btn->big->play_b->sprite,
    (sfIntRect){15, 380, 350, 170});
    sfSprite_setTextureRect(game->btn->big->exit_b->sprite,
    (sfIntRect){350, 380, 350, 170});
}
