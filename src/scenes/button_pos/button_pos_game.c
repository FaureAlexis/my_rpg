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
    game->btn->mid->pause_b->position);
}

void pos_button_game(main_game_t *game)
{
    float win_x = 1920;
    float win_y = 1080;
    sfVector2u size = sfRenderWindow_getSize(game->w);

    game->btn->mid->pause_b->position = (sfVector2f){10, 10};
    sfSprite_setPosition(game->btn->mid->pause_b->sprite,
    game->btn->mid->pause_b->position);
    if (size.x == 1920 && size.y == 1080)
        pos_fullscreen(game);
    else
        resize_all_buttons(game, ((float){size.x} / win_x),
        ((float){size.y} / win_y));
}
