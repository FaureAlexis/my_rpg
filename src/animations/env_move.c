/*
** EPITECH PROJECT, 2022
** env_mouve
** File description:
** env_mouve
*/

#include "rpg.h"

void move_up(map_t *map)
{
    obstacle_t *obstacle = map->obstacle;
    mobe_t *mobe = map->mobe;

    map->map->position.y += 10;
    while (obstacle != NULL) {
        obstacle->object->position.y += 10;
        sfSprite_setPosition(obstacle->object->sprite,
        obstacle->object->position);
        obstacle = obstacle->next;
    }
    while (mobe != NULL) {
        mobe->object->position.y += 10;
        sfSprite_setPosition(map->mobe->object->sprite,
        mobe->object->position);
        mobe = mobe->next;
    }
    sfSprite_setPosition(map->map->sprite, map->map->position);
}

void move_down(map_t *map)
{
    obstacle_t *obstacle = map->obstacle;
    mobe_t *mobe = map->mobe;

    map->map->position.y -= 10;
    while (obstacle != NULL) {
        obstacle->object->position.y -= 10;
        sfSprite_setPosition(obstacle->object->sprite,
        obstacle->object->position);
        obstacle = obstacle->next;
    }
    while (mobe != NULL) {
        mobe->object->position.y -= 10;
        sfSprite_setPosition(map->mobe->object->sprite,
        mobe->object->position);
        mobe = mobe->next;
    }
    sfSprite_setPosition(map->map->sprite, map->map->position);
}

void move_right(map_t *map)
{
    obstacle_t *obstacle = map->obstacle;
    mobe_t *mobe = map->mobe;

    map->map->position.x -= 10;
    while (obstacle != NULL) {
        obstacle->object->position.x -= 10;
        sfSprite_setPosition(obstacle->object->sprite, \
        obstacle->object->position);
        obstacle = obstacle->next;
    }
    while (mobe != NULL) {
        mobe->object->position.x -= 10;
        sfSprite_setPosition(mobe->object->sprite,
        mobe->object->position);
        mobe = mobe->next;
    }
    sfSprite_setPosition(map->map->sprite, map->map->position);
}

void move_left(map_t *map)
{
    obstacle_t *obstacle = map->obstacle;
    mobe_t *mobe = map->mobe;

    map->map->position.x += 10;
    while (obstacle != NULL) {
        obstacle->object->position.x += 10;
        sfSprite_setPosition(obstacle->object->sprite, \
        obstacle->object->position);
        obstacle = obstacle->next;
    }
    while (mobe != NULL) {
        mobe->object->position.x += 10;
        sfSprite_setPosition(mobe->object->sprite,
        mobe->object->position);
        mobe = mobe->next;
    }
    sfSprite_setPosition(map->map->sprite, map->map->position);
}
