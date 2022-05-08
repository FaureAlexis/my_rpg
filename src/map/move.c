/*
** EPITECH PROJECT, 2022
** move
** File description:
** move
*/

#include "rpg.h"

void move_obstacle(map_t *map, sfVector2f move)
{
    obstacle_t *obstacle = map->obstacle;

    while (obstacle != NULL) {
        if (map->map->position.x >= MAP_X_MIN && map->map->position.x <=
        MAP_X_MAX && map->map->position.y >= MAP_Y_MIN && map->map->position.y
        <= MAP_Y_MAX) {
            obstacle->object->position.x += move.x;
            obstacle->object->position.y += move.y;
            sfSprite_setPosition(obstacle->object->sprite, \
            obstacle->object->position);
            sfRectangleShape_setPosition(obstacle->hitbox_shape, \
            (sfVector2f){obstacle->object->position.x - 30, \
            obstacle->object->position.y - 20});
        }
        obstacle = obstacle->next;
    }
}

void move_speobstacle(map_t *map, sfVector2f move)
{
    speobstacle_t *speobstacle = map->speobstacle;

    while (speobstacle != NULL) {
        if (map->map->position.x >= MAP_X_MIN && map->map->position.x <=
        MAP_X_MAX && map->map->position.y >= MAP_Y_MIN && map->map->position.y
        <= MAP_Y_MAX) {
            if (speobstacle->artific) {
                speobstacle->artific->cord.x += move.x;
                speobstacle->artific->cord.y += move.y;
            }
            speobstacle->object->position.x += move.x;
            speobstacle->object->position.y += move.y;
            sfSprite_setPosition(speobstacle->object->sprite,
            speobstacle->object->position);
            sfRectangleShape_setPosition(speobstacle->hitbox_shape, \
            (sfVector2f){speobstacle->object->position.x - 30, \
            speobstacle->object->position.y - 20});
        }
        speobstacle = speobstacle->next;
    }
}

void move_mob(map_t *map, sfVector2f move)
{
    mobe_t *mobe = map->mobe;

    while (mobe != NULL) {
        if (map->map->position.x >= MAP_X_MIN && map->map->position.x <=
        MAP_X_MAX && map->map->position.y >= MAP_Y_MIN && map->map->position.y
        <= MAP_Y_MAX) {
            mobe->object->position.x += move.x;
            mobe->object->position.y += move.y;
            sfSprite_setPosition(mobe->object->sprite,
            mobe->object->position);
            sfRectangleShape_setPosition(mobe->hitbox_shape, \
            (sfVector2f){mobe->object->position.x - 30, \
            mobe->object->position.y - 20});
        }
        mobe = mobe->next;
    }
}
