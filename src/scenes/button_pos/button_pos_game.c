/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

static void pos_fullscreen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->mid->pause_b->shape,
    (sfVector2f){10, 10});
}

static void pos_screen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->mid->pause_b->shape,
    (sfVector2f){7.5, 7.5});
}

void pos_button_game(main_game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->w);

    sfSprite_setPosition(game->btn->mid->pause_b->sprite,
    (sfVector2f){10, 10});
    if (size.x == 1920)
        pos_fullscreen(game);
    else
        pos_screen(game);
}
