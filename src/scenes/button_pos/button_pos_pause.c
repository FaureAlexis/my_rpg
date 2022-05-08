/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

static void pos_fullscreen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape, \
    game->btn->big->exit_b->position);
    sfRectangleShape_setPosition(game->btn->mid->main_b->shape, \
    game->btn->mid->main_b->position);
    sfRectangleShape_setPosition(game->btn->big->return_b->shape, \
    game->btn->big->return_b->position);
    sfRectangleShape_setPosition(game->btn->big->settings_b->shape, \
    game->btn->big->settings_b->position);
}

void pos_button_pause(main_game_t *game)
{
    float win_x = MAX_W_X;
    float win_y = MAX_W_Y;
    sfVector2u size = sfRenderWindow_getSize(game->w);

    game->btn->big->exit_b->position = POS_EXIT2;
    game->btn->mid->main_b->position = POS_MAIN;
    game->btn->big->return_b->position = POS_RETURN2;
    game->btn->big->settings_b->position = POS_SETTINGS2;
    set_mid_buttons_sprite_pos(game);
    set_big_buttons_sprite_pos(game);
    if (size.x == MAX_W_X && size.y == MAX_W_Y)
        pos_fullscreen(game);
    else {
        resize_all_buttons(game, ((float){size.x} / win_x), \
        ((float){size.y} / win_y));
    }
}
