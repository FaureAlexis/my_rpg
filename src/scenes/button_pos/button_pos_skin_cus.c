/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

static int set_sprite_pos(main_game_t *game)
{
    sfSprite_setPosition(game->btn->mid->exit_b->sprite,
    game->btn->mid->exit_b->position);
    sfSprite_setPosition(game->btn->big->play_b->sprite,
    game->btn->big->play_b->position);
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    game->btn->big->return_b->position);
    return EXIT_SUCCESS;
}

static void pos_fullscreen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->mid->exit_b->shape,
    game->btn->mid->exit_b->position);
    sfRectangleShape_setPosition(game->btn->big->play_b->shape,
    game->btn->big->play_b->position);
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    game->btn->big->return_b->position);
    sfRectangleShape_setPosition(game->skin->red, game->skin->pos_red);
    sfRectangleShape_setPosition(game->skin->green, game->skin->pos_green);
    sfRectangleShape_setPosition(game->skin->blue, game->skin->pos_blue);
}

void pos_button_skin_cus(main_game_t *game)
{
    float win_x = MAX_W_X;
    float win_y = MAX_W_Y;
    sfVector2u size = sfRenderWindow_getSize(game->w);

    game->btn->mid->exit_b->position = POS_HELP;
    game->btn->big->play_b->position = POS_PLAY;
    game->btn->big->return_b->position = POS_RETURN4;
    game->skin->pos_red = RED_POS;
    game->skin->pos_green = GREEN_POS;
    game->skin->pos_blue = BLUE_POS;
    set_sprite_pos(game);
    if (size.x == MAX_W_X && size.y == MAX_W_Y)
        pos_fullscreen(game);
    else {
        resize_all_buttons(game, ((float){size.x} / win_x),
        ((float){size.y} / win_y));
    }
}
