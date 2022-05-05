/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** resize_buttons
*/

#include "rpg.h"

int resize_pos_mid_buttons(main_game_t *game, float x, float y)
{
    sfRectangleShape_setPosition(game->btn->mid->main_b->shape,
    (sfVector2f){game->btn->mid->main_b->position.x * x,
    game->btn->mid->main_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->mid->pause_b->shape,
    (sfVector2f){game->btn->mid->pause_b->position.x * x,
    game->btn->mid->pause_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->mid->unmute_b->shape,
    (sfVector2f){game->btn->mid->unmute_b->position.x * x,
    game->btn->mid->unmute_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->mid->mute_b->shape,
    (sfVector2f){game->btn->mid->mute_b->position.x * x,
    game->btn->mid->mute_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->mid->help_b->shape,
    (sfVector2f){game->btn->mid->help_b->position.x * x,
    game->btn->mid->help_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->mid->keybind_b->shape,
    (sfVector2f){game->btn->mid->keybind_b->position.x * x,
    game->btn->mid->keybind_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->mid->settings_b->shape,
    (sfVector2f){game->btn->mid->settings_b->position.x * x,
    game->btn->mid->settings_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->mid->exit_b->shape,
    (sfVector2f){game->btn->mid->exit_b->position.x * x,
    game->btn->mid->exit_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->mid->unmute_b->shape,
    (sfVector2f){game->btn->mid->unmute_b->position.x * x,
    game->btn->mid->unmute_b->position.y * y});
    return EXIT_SUCCESS;
}

int resize_mid_buttons(main_game_t *game, float x, float y)
{
    sfRectangleShape_setSize(game->btn->mid->main_b->shape,
    (sfVector2f){game->btn->mid->main_b->size.x * x,
    game->btn->mid->main_b->size.y * y});
    sfRectangleShape_setSize(game->btn->mid->pause_b->shape,
    (sfVector2f){game->btn->mid->pause_b->size.x * x,
    game->btn->mid->pause_b->size.y * y});
    sfRectangleShape_setSize(game->btn->mid->unmute_b->shape,
    (sfVector2f){game->btn->mid->unmute_b->size.x * x,
    game->btn->mid->unmute_b->size.y * y});
    sfRectangleShape_setSize(game->btn->mid->mute_b->shape,
    (sfVector2f){game->btn->mid->mute_b->size.x * x,
    game->btn->mid->mute_b->size.y * y});
    sfRectangleShape_setSize(game->btn->mid->keybind_b->shape,
    (sfVector2f){game->btn->mid->keybind_b->size.x * x,
    game->btn->mid->keybind_b->size.y * y});
    sfRectangleShape_setSize(game->btn->mid->help_b->shape,
    (sfVector2f){game->btn->mid->help_b->size.x * x,
    game->btn->mid->help_b->size.y * y});
    sfRectangleShape_setSize(game->btn->mid->settings_b->shape,
    (sfVector2f){game->btn->mid->settings_b->size.x * x,
    game->btn->mid->settings_b->size.y * y});
    sfRectangleShape_setSize(game->btn->mid->exit_b->shape,
    (sfVector2f){game->btn->mid->exit_b->size.x * x,
    game->btn->mid->exit_b->size.y * y});
    sfRectangleShape_setSize(game->btn->mid->unmute_b->shape,
    (sfVector2f){game->btn->mid->unmute_b->size.x * x,
    game->btn->mid->unmute_b->size.y * y});
    return EXIT_SUCCESS;
}

int set_mid_buttons_sprite_pos(main_game_t *game)
{
    sfSprite_setPosition(game->btn->mid->main_b->sprite,
    game->btn->mid->main_b->position);
    sfSprite_setPosition(game->btn->mid->pause_b->sprite,
    game->btn->mid->pause_b->position);
    sfSprite_setPosition(game->btn->mid->help_b->sprite,
    game->btn->mid->help_b->position);
    sfSprite_setPosition(game->btn->mid->exit_b->sprite,
    game->btn->mid->exit_b->position);
    sfSprite_setPosition(game->btn->mid->settings_b->sprite,
    game->btn->mid->settings_b->position);
    sfSprite_setPosition(game->btn->mid->keybind_b->sprite,
    game->btn->mid->keybind_b->position);
    sfSprite_setPosition(game->btn->mid->mute_b->sprite,
    game->btn->mid->mute_b->position);
    sfSprite_setPosition(game->btn->mid->unmute_b->sprite,
    game->btn->mid->unmute_b->position);
    return EXIT_SUCCESS;
}
