/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

static void pos_fullscreen2(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->sml->minus_b->shape, \
    game->btn->mid->mute_b->position);
    sfRectangleShape_setPosition(game->btn->sml->plus_r_b->shape, \
    game->btn->mid->unmute_b->position);
    sfRectangleShape_setPosition(game->btn->sml->minus_r_b->shape, \
    game->btn->sml->plus_b->position);
    sfRectangleShape_setPosition(game->btn->mid->keybind_b->shape, \
    game->btn->sml->minus_b->position);
    sfRectangleShape_setPosition(game->btn->mid->mute_b->shape, \
    game->btn->sml->plus_r_b->position);
    sfRectangleShape_setPosition(game->btn->mid->unmute_b->shape, \
    game->btn->sml->minus_r_b->position);
}

static void pos_fullscreen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->mid->help_b->shape, \
    game->btn->mid->help_b->position);
    sfRectangleShape_setPosition(game->btn->sml->right_b->shape, \
    game->btn->sml->right_b->position);
    sfRectangleShape_setPosition(game->btn->sml->left_b->shape, \
    game->btn->sml->left_b->position);
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape, \
    game->btn->big->exit_b->position);
    sfRectangleShape_setPosition(game->btn->big->return_b->shape, \
    game->btn->big->return_b->position);
    sfRectangleShape_setPosition(game->btn->sml->plus_b->shape, \
    game->btn->mid->keybind_b->position);
    pos_fullscreen2(game);
}

static void pos_screen(main_game_t *game, float x, float y)
{
    resize_all_buttons(game, x, y);
    game->btn->big->return_b->position = \
    (sfVector2f){game->btn->big->return_b->position.x * x, \
    game->btn->big->return_b->position.y * y};
}

void change_button_pos(main_game_t *game)
{
    game->btn->mid->help_b->position = POS_HELP;
    game->btn->sml->right_b->position = POS_RIGHT;
    game->btn->sml->left_b->position = POS_LEFT;
    game->btn->big->exit_b->position = POS_EXIT;
    game->btn->big->return_b->position = POS_RETURN;
    game->btn->mid->keybind_b->position = POS_KEYBIND;
    game->btn->mid->mute_b->position = POS_MUTE;
    game->btn->mid->unmute_b->position = POS_UNMUTE;
    game->btn->sml->plus_b->position = POS_PLUS;
    game->btn->sml->minus_b->position = POS_MINUS;
    game->btn->sml->plus_r_b->position = POS_PLUS_R;
    game->btn->sml->minus_r_b->position = POS_MINUS_R;
}

void pos_button_settings(main_game_t *game)
{
    float win_x = MAX_W_X;
    float win_y = MAX_W_Y;
    sfVector2u size = sfRenderWindow_getSize(game->w);

    change_button_pos(game);
    set_big_buttons_sprite_pos(game);
    set_mid_buttons_sprite_pos(game);
    set_sml_buttons_sprite_pos(game);
    if (size.x == MAX_W_X && size.y == MAX_W_Y)
        pos_fullscreen(game);
    else
        pos_screen(game, ((float){size.x} / win_x), ((float){size.y} / win_y));
}
