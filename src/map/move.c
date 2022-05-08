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
        MAP_X_MAX && map->map->position.y >= MAP_Y_MIN &&
        map->map->position.y <= MAP_Y_MAX) {
            obstacle->object->position.x += move.x;
            obstacle->object->position.y += move.y;
            sfSprite_setPosition(obstacle->object->sprite,
            obstacle->object->position);
            sfRectangleShape_setPosition(obstacle->hitbox_shape,
            (sfVector2f){obstacle->object->position.x - 30,
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
            sfRectangleShape_setPosition(speobstacle->hitbox_shape,
            (sfVector2f){speobstacle->object->position.x - 30,
            speobstacle->object->position.y - 20});
        }
        speobstacle = speobstacle->next;
    }
}

void move_mob(map_t *map, sfVector2f move)
{
    mobe_t *mob = map->mobe;

    while (mob != NULL) {
        if (map->map->position.x >= MAP_X_MIN && map->map->position.x <=
        MAP_X_MAX && map->map->position.y >= MAP_Y_MIN && map->map->position.y
        <= MAP_Y_MAX) {
            mob->object->position.x += move.x;
            mob->object->position.y += move.y;
            sfSprite_setPosition(mob->object->sprite,
            mob->object->position);
            sfRectangleShape_setPosition(mob->hitbox_shape,
            (sfVector2f){mob->object->position.x - 30,
            mob->object->position.y - 20});
            sfText_setString(mob->life_txt, mob->life_str);
            sfText_setPosition(mob->life_txt,
            (sfVector2f){mob->object->position.x - 50,
            mob->object->position.y - 30});
        }
        mob = mob->next;
    }
}
