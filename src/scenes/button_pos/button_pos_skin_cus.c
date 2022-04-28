/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

static void pos_fullscreen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->mid->exit_b->shape,
    (sfVector2f){10, 10});
    sfRectangleShape_setPosition(game->btn->big->play_b->shape,
    (sfVector2f){960, 780});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){540, 780});
}

static void pos_screen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->mid->exit_b->shape,
    (sfVector2f){7.5, 7.5});
    sfRectangleShape_setPosition(game->btn->big->play_b->shape,
    (sfVector2f){720, 585});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){405, 585});
}

void pos_button_skin_cus(main_game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->w);

    sfSprite_setPosition(game->btn->mid->exit_b->sprite,
    (sfVector2f){10, 10});
    sfSprite_setPosition(game->btn->big->play_b->sprite,
    (sfVector2f){960, 780});
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    (sfVector2f){540, 780});
    if (size.x == 1920)
        pos_fullscreen(game);
    else
        pos_screen(game);
}
