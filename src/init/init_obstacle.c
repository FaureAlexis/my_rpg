/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_obstacle
*/

#include "rpg.h"

static int set_texture_obstacle(obstacle_t *node, char ***tab, int i)
{
    sfSprite_setScale(node->object->sprite, node->object->scale);
    sfSprite_setOrigin(node->object->sprite,
    (sfVector2f){my_atoi(tab[i][REC_WIDTH]) / 2, my_atoi(tab[i][REC_HEIGHT])
    / 2});
    sfSprite_setTexture(node->object->sprite, node->object->texture, sfFalse);
    sfSprite_setTextureRect(node->object->sprite, node->object->rect);
    node->hitbox = sfSprite_getGlobalBounds(node->object->sprite);
    node->hitbox_shape = sfRectangleShape_create();
    if (!node->hitbox_shape)
        return EPITECH_ERROR;
    sfRectangleShape_setSize(node->hitbox_shape,
    (sfVector2f){node->hitbox.width, node->hitbox.height / 2});
    sfRectangleShape_setPosition(node->hitbox_shape,
    (sfVector2f){node->object->position.x - 40, node->object->position.y + 5});
    sfRectangleShape_setFillColor(node->hitbox_shape,
    sfColor_fromRGBA(0, 255, 0, 100));
    return EXIT_SUCCESS;
}

int init_obstacle(map_t *map, char ***tab, int i)
{
    obstacle_t *node = malloc(sizeof(obstacle_t));
    sfIntRect rec = {my_atoi(tab[i][REC_LEFT]), my_atoi(tab[i][REC_TOP]),
    my_atoi(tab[i][REC_WIDTH]), my_atoi(tab[i][REC_HEIGHT])};

    if (!node)
        return EPITECH_ERROR;
    node->object = malloc(sizeof(game_object_t));
    if (!node->object)
        return EPITECH_ERROR;
    node->object->scale = (sfVector2f){5, 5};
    node->object->rect = rec;
    node->object->position.x = my_atoi(tab[i][CORD_X]);
    node->object->position.y = my_atoi(tab[i][CORD_Y]);
    node->object->texture = sfTexture_createFromFile(tab[i][ASSET], NULL);
    node->object->sprite = sfSprite_create();
    if (!node->object->texture || !node->object->sprite)
        return EPITECH_ERROR;
    node->next = NULL;
    if (set_texture_obstacle(node, tab, i) == EPITECH_ERROR)
        return EPITECH_ERROR;
    map->obstacle = add_node_to_obstacle(map->obstacle, node);
    return EXIT_SUCCESS;
}
