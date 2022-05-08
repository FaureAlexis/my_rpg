/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_tree_hitbox
*/

#include "rpg.h"

int set_big_tree_hitbox(obstacle_t *tmp)
{
    if (!tmp)
        return EPITECH_ERROR;
    if ((tmp->object->rect.left == 0 || tmp->object->rect.left == 48)
    && (tmp->object->rect.top == 80 || tmp->object->rect.top == 144)
    && tmp->object->rect.width == 48 && tmp->object->rect.height == 64) {
        sfRectangleShape_setSize(tmp->hitbox_shape,
        (sfVector2f){tmp->hitbox.width / 1.5, tmp->hitbox.height / 4});
        sfRectangleShape_setPosition(tmp->hitbox_shape,
        (sfVector2f){tmp->object->position.x - 80, tmp->object->position.y
        + 65});
    }
    return EXIT_SUCCESS;
}

int set_small_tree_hitbox(obstacle_t *tmp)
{
    if (!tmp)
        return EPITECH_ERROR;
    if (tmp->object->rect.left == 96 && tmp->object->rect.top == 112
    && tmp->object->rect.width == 32 && tmp->object->rect.height == 32) {
        sfRectangleShape_setSize(tmp->hitbox_shape,
        (sfVector2f){tmp->hitbox.width / 1.1, tmp->hitbox.height / 2.7});
        sfRectangleShape_setPosition(tmp->hitbox_shape,
        (sfVector2f){tmp->object->position.x - 75, tmp->object->position.y
        + 10});
    }
    return EXIT_SUCCESS;
}

int set_long_tree_hitbox(obstacle_t *tmp)
{
    if (!tmp)
        return EPITECH_ERROR;
    if (tmp->object->rect.left == 128 && tmp->object->rect.top == 96
    && tmp->object->rect.width == 32 && tmp->object->rect.height == 48) {
        sfRectangleShape_setSize(tmp->hitbox_shape,
        (sfVector2f){tmp->hitbox.width / 1.5, tmp->hitbox.height / 4});
        sfRectangleShape_setPosition(tmp->hitbox_shape,
        (sfVector2f){tmp->object->position.x - 55, tmp->object->position.y
        + 60});
    }
    return EXIT_SUCCESS;
}

int set_log_hitbox(obstacle_t *tmp)
{
    if (!tmp)
        return EPITECH_ERROR;
    if (tmp->object->rect.left == 96 && tmp->object->rect.top == 80
    && tmp->object->rect.width == 32 && tmp->object->rect.height == 16) {
        sfRectangleShape_setSize(tmp->hitbox_shape,
        (sfVector2f){tmp->hitbox.width / 1.1, tmp->hitbox.height / 1.35});
        sfRectangleShape_setPosition(tmp->hitbox_shape,
        (sfVector2f){tmp->object->position.x - 80, tmp->object->position.y
        - 25});
    }
    return EXIT_SUCCESS;
}
