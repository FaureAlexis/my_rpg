/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

static void pos_fullscreen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->mid->help_b->shape,
    (sfVector2f){10, 10});
    sfRectangleShape_setPosition(game->btn->sml->right_b->shape,
    (sfVector2f){1000, 360});
    sfRectangleShape_setPosition(game->btn->sml->left_b->shape,
    (sfVector2f){750, 360});
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    (sfVector2f){1000, 780});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){520, 780});
    sfRectangleShape_setPosition(game->btn->sml->plus_b->shape,
    (sfVector2f){1200, 600});
    sfRectangleShape_setPosition(game->btn->sml->minus_b->shape,
    (sfVector2f){950, 600});
    sfRectangleShape_setPosition(game->btn->sml->plus_r_b->shape,
    (sfVector2f){1200, 440});
    sfRectangleShape_setPosition(game->btn->sml->minus_r_b->shape,
    (sfVector2f){950, 440});
    sfRectangleShape_setPosition(game->btn->mid->keybind_b->shape,
    (sfVector2f){1500, 600});
    sfRectangleShape_setPosition(game->btn->mid->mute_b->shape,
    (sfVector2f){1500, 200});
    sfRectangleShape_setPosition(game->btn->mid->unmute_b->shape,
    (sfVector2f){1500, 400});
}

static void pos_screen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->mid->help_b->shape,
    (sfVector2f){7.5, 7.5});
    sfRectangleShape_setPosition(game->btn->sml->right_b->shape,
    (sfVector2f){750, 270});
    sfRectangleShape_setPosition(game->btn->sml->left_b->shape,
    (sfVector2f){562.5, 270});
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    (sfVector2f){750, 585});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){390, 585});
    game->btn->big->return_b->position = (sfVector2f){390, 585};
    sfRectangleShape_setPosition(game->btn->sml->plus_b->shape,
    (sfVector2f){900, 450});
    sfRectangleShape_setPosition(game->btn->sml->minus_b->shape,
    (sfVector2f){712.5, 450});
    sfRectangleShape_setPosition(game->btn->sml->plus_r_b->shape,
    (sfVector2f){900, 330});
    sfRectangleShape_setPosition(game->btn->sml->minus_r_b->shape,
    (sfVector2f){712.5, 330});
    sfRectangleShape_setPosition(game->btn->mid->keybind_b->shape,
    (sfVector2f){1125, 450});
    sfRectangleShape_setPosition(game->btn->mid->mute_b->shape,
    (sfVector2f){1125, 150});
    sfRectangleShape_setPosition(game->btn->mid->unmute_b->shape,
    (sfVector2f){1125, 300});
}

void pos_button_settings_two(main_game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->w);

    sfSprite_setPosition(game->btn->sml->plus_b->sprite,
    (sfVector2f){1200, 600});
    sfSprite_setPosition(game->btn->sml->minus_b->sprite,
    (sfVector2f){950, 600});
    sfSprite_setPosition(game->btn->sml->plus_r_b->sprite,
    (sfVector2f){1200, 440});
    sfSprite_setPosition(game->btn->sml->minus_r_b->sprite,
    (sfVector2f){950, 440});
    if (size.x == 1920)
        pos_fullscreen(game);
    else
        pos_screen(game);
}

void pos_button_settings(main_game_t *game)
{
    sfSprite_setPosition(game->btn->mid->help_b->sprite, (sfVector2f){10, 10});
    sfSprite_setPosition(game->btn->sml->right_b->sprite,
    (sfVector2f){1000, 360});
    sfSprite_setPosition(game->btn->sml->left_b->sprite,
    (sfVector2f){750, 360});
    sfSprite_setPosition(game->btn->big->exit_b->sprite,
    (sfVector2f){1000, 780});
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    (sfVector2f){520, 780});
    sfSprite_setPosition(game->btn->mid->keybind_b->sprite,
    (sfVector2f){1500, 600});
    sfSprite_setPosition(game->btn->mid->mute_b->sprite,
    (sfVector2f){1500, 200});
    sfSprite_setPosition(game->btn->mid->unmute_b->sprite,
    (sfVector2f){1500, 400});
    pos_button_settings_two(game);
}
