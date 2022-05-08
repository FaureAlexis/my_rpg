/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "rpg.h"

void display_obstacle(main_game_t *game)
{
    obstacle_t *tmp = game->map->obstacle;

    while (tmp) {
        sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
        sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
        tmp->hitbox = sfSprite_getGlobalBounds(tmp->object->sprite);
        sfRectangleShape_setPosition(tmp->hitbox_shape,
        (sfVector2f){tmp->object->position.x - 40, tmp->object->position.y +
        5});
        set_small_tree_hitbox(tmp);
        set_long_tree_hitbox(tmp);
        set_big_tree_hitbox(tmp);
        set_log_hitbox(tmp);
        tmp->hitbox = sfRectangleShape_getGlobalBounds(tmp->hitbox_shape);
        sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
        tmp = tmp->next;
    }
}
