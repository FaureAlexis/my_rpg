/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

void pos_button_main(main_game_t *game)
{
    sfSprite_setPosition(game->btn->big->exit_b->sprite,
    (sfVector2f){750, 700});
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    (sfVector2f){760, 700});
    sfSprite_setPosition(game->btn->big->play_b->sprite,
    (sfVector2f){540, 450});
    sfRectangleShape_setPosition(game->btn->big->play_b->shape,
    (sfVector2f){550, 450});
    sfSprite_setPosition(game->btn->big->settings_b->sprite,
    (sfVector2f){960, 450});
    sfRectangleShape_setPosition(game->btn->big->settings_b->shape,
    (sfVector2f){970, 450});
    sfSprite_setPosition(game->btn->mid->help_b->sprite, (sfVector2f){0, 0});
    sfRectangleShape_setPosition(game->btn->mid->help_b->shape,
    (sfVector2f){0, 0});
}

void pos_button_settings(main_game_t *game)
{
    sfSprite_setPosition(game->btn->mid->help_b->sprite, (sfVector2f){0, 0});
    sfRectangleShape_setPosition(game->btn->mid->help_b->shape,
    (sfVector2f){0, 0});
    sfSprite_setPosition(game->btn->sml->right_b->sprite,
    (sfVector2f){1000, 360});
    sfRectangleShape_setPosition(game->btn->sml->right_b->shape,
    (sfVector2f){1000, 360});
    sfSprite_setPosition(game->btn->sml->left_b->sprite,
    (sfVector2f){750, 360});
    sfRectangleShape_setPosition(game->btn->sml->left_b->shape,
    (sfVector2f){750, 360});
    sfSprite_setPosition(game->btn->big->exit_b->sprite,
    (sfVector2f){1000, 780});
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    (sfVector2f){1000, 760});
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    (sfVector2f){520, 780});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){520, 760});
}

void pos_button_help(main_game_t *game)
{
    sfSprite_setPosition(game->btn->big->exit_b->sprite,
    (sfVector2f){1000, 760});
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    (sfVector2f){1000, 760});
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    (sfVector2f){520, 760});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){520, 760});
}

void pos_button_game(main_game_t *game)
{
    sfSprite_setPosition(game->btn->mid->pause_b->sprite, (sfVector2f){0, 0});
    sfRectangleShape_setPosition(game->btn->mid->pause_b->shape,
    (sfVector2f){0, 0});
}

void pos_button_pause(main_game_t *game)
{
    sfSprite_setPosition(game->btn->big->exit_b->sprite,
    (sfVector2f){750, 650});
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    (sfVector2f){790, 660});
    sfSprite_setPosition(game->btn->mid->main_b->sprite,
    (sfVector2f){1800, 0});
    sfRectangleShape_setPosition(game->btn->mid->main_b->shape,
    (sfVector2f){1800, 0});
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    (sfVector2f){500, 330});
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){540, 340});
}
