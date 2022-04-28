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
    (sfVector2f){750, 650});
    sfRectangleShape_setPosition(game->btn->mid->main_b->shape,
    (sfVector2f){1800, 0});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){500, 330});
    sfRectangleShape_setPosition(game->btn->big->settings_b->shape,
    (sfVector2f){1010, 330});
}

static void pos_screen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    (sfVector2f){562.5, 487.5});
    sfRectangleShape_setPosition(game->btn->mid->main_b->shape,
    (sfVector2f){1350, 0});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){375, 247.5});
    sfRectangleShape_setPosition(game->btn->big->settings_b->shape,
    (sfVector2f){757.5, 247.5});
}

void pos_button_pause(main_game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->w);

    sfSprite_setPosition(game->btn->big->exit_b->sprite,
    (sfVector2f){750, 650});
    sfSprite_setPosition(game->btn->mid->main_b->sprite,
    (sfVector2f){1800, 0});
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    (sfVector2f){500, 330});
    sfSprite_setPosition(game->btn->big->settings_b->sprite,
    (sfVector2f){1010, 330});
    if (size.x == 1920)
        pos_fullscreen(game);
    else
        pos_screen(game);
}
