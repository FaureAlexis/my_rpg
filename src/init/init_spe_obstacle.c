/*
** EPITECH PROJECT, 2022
** spe_obstacle
** File description:
** spe_obstacle
*/

#include "rpg.h"

static int set_texture_speobstacle(speobstacle_t *node, char ***tab, int i)
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
    node->artific = NULL;
    sfRectangleShape_setSize(node->hitbox_shape,
    (sfVector2f){node->hitbox.width, node->hitbox.height / 2});
    sfRectangleShape_setPosition(node->hitbox_shape,
    (sfVector2f){node->object->position.x - 40, node->object->position.y + 5});
    sfRectangleShape_setFillColor(node->hitbox_shape,
    sfColor_fromRGBA(SPEOBS_COLOR));
    return EXIT_SUCCESS;
}

static speobstacle_t *set_info_speobstacle(speobstacle_t *node, char ***tab,
int i, sfIntRect rec)
{
    node->object->scale = (sfVector2f){5, 5};
    node->object->rect = rec;
    node->object->position.x = my_atoi(tab[i][CORD_X]);
    node->object->position.y = my_atoi(tab[i][CORD_Y]);
    node->hp = my_atoi(tab[i][HP]);
    node->type = my_atoi(tab[i][POWER]);
    return node;
}

int init_speobstacle(map_t *map, char ***tab, int i)
{
    speobstacle_t *node = malloc(sizeof(speobstacle_t));
    sfIntRect rec = {my_atoi(tab[i][REC_LEFT]), my_atoi(tab[i][REC_TOP]),
    my_atoi(tab[i][REC_WIDTH]), my_atoi(tab[i][REC_HEIGHT])};

    if (!node)
        return EPITECH_ERROR;
    node->object = malloc(sizeof(game_object_t));
    node = set_info_speobstacle(node, tab, i, rec);
    node->object->texture = sfTexture_createFromFile(tab[i][ASSET], NULL);
    node->object->sprite = sfSprite_create();
    node->next = NULL;
    if (set_texture_speobstacle(node, tab, i) == EPITECH_ERROR ||
    !node->object->sprite || !node->object->texture || !node->object)
        return EPITECH_ERROR;
    map->speobstacle = add_node_to_speobstacle(map->speobstacle, node);
    return EXIT_SUCCESS;
}
