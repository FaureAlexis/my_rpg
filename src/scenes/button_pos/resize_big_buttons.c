/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** resize_buttons
*/

#include "rpg.h"

int resize_pos_big_buttons(main_game_t *game, float x, float y)
{
    sfRectangleShape_setPosition(game->btn->big->return_b->shape, \
    (sfVector2f){game->btn->big->return_b->position.x * x, \
    game->btn->big->return_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->big->newsave_b->shape, \
    (sfVector2f){game->btn->big->newsave_b->position.x * x, \
    game->btn->big->newsave_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->big->load_b->shape, \
    (sfVector2f){game->btn->big->load_b->position.x * x, \
    game->btn->big->load_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape, \
    (sfVector2f){game->btn->big->exit_b->position.x * x, \
    game->btn->big->exit_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->big->settings_b->shape, \
    (sfVector2f){game->btn->big->settings_b->position.x * x, \
    game->btn->big->settings_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->big->play_b->shape, \
    (sfVector2f){game->btn->big->play_b->position.x * x, \
    game->btn->big->play_b->position.y * y});
    return EXIT_SUCCESS;
}

int resize_big_buttons(main_game_t *game, float x, float y)
{
    sfRectangleShape_setSize(game->btn->big->return_b->shape, \
    (sfVector2f){game->btn->big->return_b->size.x * x, \
    game->btn->big->return_b->size.y * y});
    sfRectangleShape_setSize(game->btn->big->newsave_b->shape, \
    (sfVector2f){game->btn->big->newsave_b->size.x * x, \
    game->btn->big->newsave_b->size.y * y});
    sfRectangleShape_setSize(game->btn->big->load_b->shape, \
    (sfVector2f){game->btn->big->load_b->size.x * x, \
    game->btn->big->load_b->size.y * y});
    sfRectangleShape_setSize(game->btn->big->exit_b->shape, \
    (sfVector2f){game->btn->big->exit_b->size.x * x, \
    game->btn->big->exit_b->size.y * y});
    sfRectangleShape_setSize(game->btn->big->settings_b->shape, \
    (sfVector2f){game->btn->big->settings_b->size.x * x, \
    game->btn->big->settings_b->size.y * y});
    sfRectangleShape_setSize(game->btn->big->play_b->shape, \
    (sfVector2f){game->btn->big->play_b->size.x * x, \
    game->btn->big->play_b->size.y * y});
    return EXIT_SUCCESS;
}

int set_big_buttons_sprite_pos(main_game_t *game)
{
    sfSprite_setPosition(game->btn->big->return_b->sprite, \
    game->btn->big->return_b->position);
    sfSprite_setPosition(game->btn->big->newsave_b->sprite, \
    game->btn->big->newsave_b->position);
    sfSprite_setPosition(game->btn->big->load_b->sprite, \
    game->btn->big->load_b->position);
    sfSprite_setPosition(game->btn->big->exit_b->sprite, \
    game->btn->big->exit_b->position);
    sfSprite_setPosition(game->btn->big->settings_b->sprite, \
    game->btn->big->settings_b->position);
    sfSprite_setPosition(game->btn->big->play_b->sprite, \
    game->btn->big->play_b->position);
    return EXIT_SUCCESS;
}
