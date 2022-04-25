/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

void pos_button_skin_cus(main_game_t *game)
{
    sfSprite_setPosition(game->btn->mid->exit_b->sprite,
    (sfVector2f){10, 10});
    sfRectangleShape_setPosition(game->btn->mid->exit_b->shape,
    (sfVector2f){10, 10});
    sfSprite_setPosition(game->btn->big->play_b->sprite,
    (sfVector2f){540, 780});
    sfRectangleShape_setPosition(game->btn->big->play_b->shape,
    (sfVector2f){540, 780});
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    (sfVector2f){960, 780});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){960, 780});
}
