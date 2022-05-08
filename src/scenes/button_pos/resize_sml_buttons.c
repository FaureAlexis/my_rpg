/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** resize_buttons
*/

#include "rpg.h"

int resize_pos_sml_buttons2(main_game_t *game, float x, float y)
{
    sfRectangleShape_setPosition(game->btn->sml->right_b->shape, \
    (sfVector2f){game->btn->sml->right_b->position.x * x, \
    game->btn->sml->right_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->sml->plus_r_b->shape, \
    (sfVector2f){game->btn->sml->plus_r_b->position.x * x, \
    game->btn->sml->plus_r_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->sml->minus_r_b->shape, \
    (sfVector2f){game->btn->sml->minus_r_b->position.x * x, \
    game->btn->sml->minus_r_b->position.y * y});
    return EXIT_SUCCESS;
}

int resize_pos_sml_buttons(main_game_t *game, float x, float y)
{
    sfRectangleShape_setPosition(game->btn->sml->plus_b->shape, \
    (sfVector2f){game->btn->sml->plus_b->position.x * x, \
    game->btn->sml->plus_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->sml->minus_b->shape, \
    (sfVector2f){game->btn->sml->minus_b->position.x * x, \
    game->btn->sml->minus_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->sml->talk_b->shape, \
    (sfVector2f){game->btn->sml->talk_b->position.x * x, \
    game->btn->sml->talk_b->position.y * y});
    sfRectangleShape_setPosition(game->btn->sml->left_b->shape, \
    (sfVector2f){game->btn->sml->left_b->position.x * x, \
    game->btn->sml->left_b->position.y * y});
    return resize_pos_sml_buttons2(game, x, y);
}

static int resize_sml_buttons2(main_game_t *game, float x, float y)
{
    sfRectangleShape_setSize(game->btn->sml->right_b->shape, \
    (sfVector2f){game->btn->sml->right_b->size.x * x, \
    game->btn->sml->right_b->size.y * y});
    sfRectangleShape_setSize(game->btn->sml->plus_r_b->shape, \
    (sfVector2f){game->btn->sml->plus_r_b->size.x * x, \
    game->btn->sml->plus_r_b->size.y * y});
    sfRectangleShape_setSize(game->btn->sml->minus_r_b->shape, \
    (sfVector2f){game->btn->sml->minus_r_b->size.x * x, \
    game->btn->sml->minus_r_b->size.y * y});
    return EXIT_SUCCESS;
}

int resize_sml_buttons(main_game_t *game, float x, float y)
{
    sfRectangleShape_setSize(game->btn->sml->plus_b->shape, \
    (sfVector2f){game->btn->sml->plus_b->size.x * x, \
    game->btn->sml->plus_b->size.y * y});
    sfRectangleShape_setSize(game->btn->sml->minus_b->shape, \
    (sfVector2f){game->btn->sml->minus_b->size.x * x, \
    game->btn->sml->minus_b->size.y * y});
    sfRectangleShape_setSize(game->btn->sml->talk_b->shape, \
    (sfVector2f){game->btn->sml->talk_b->size.x * x, \
    game->btn->sml->talk_b->size.y * y});
    sfRectangleShape_setSize(game->btn->sml->left_b->shape, \
    (sfVector2f){game->btn->sml->left_b->size.x * x, \
    game->btn->sml->left_b->size.y * y});
    return resize_sml_buttons2(game, x, y);
}

int set_sml_buttons_sprite_pos(main_game_t *game)
{
    sfSprite_setPosition(game->btn->sml->plus_b->sprite, \
    game->btn->sml->plus_b->position);
    sfSprite_setPosition(game->btn->sml->minus_b->sprite, \
    game->btn->sml->minus_b->position);
    sfSprite_setPosition(game->btn->sml->talk_b->sprite, \
    game->btn->sml->talk_b->position);
    sfSprite_setPosition(game->btn->sml->left_b->sprite, \
    game->btn->sml->left_b->position);
    sfSprite_setPosition(game->btn->sml->right_b->sprite, \
    game->btn->sml->right_b->position);
    sfSprite_setPosition(game->btn->sml->plus_r_b->sprite, \
    game->btn->sml->plus_r_b->position);
    sfSprite_setPosition(game->btn->sml->minus_r_b->sprite, \
    game->btn->sml->minus_r_b->position);
    return EXIT_SUCCESS;
}
