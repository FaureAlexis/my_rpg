/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

static void pos_fullscreen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    (sfVector2f){1000, 760});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){520, 760});
}

static void pos_screen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    (sfVector2f){750, 570});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){390, 570});
}

void pos_button_help(main_game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->w);

    sfSprite_setPosition(game->btn->big->exit_b->sprite,
    (sfVector2f){1000, 760});
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    (sfVector2f){520, 760});
    if (size.x == 1920)
        pos_fullscreen(game);
    else
        pos_screen(game);
}
