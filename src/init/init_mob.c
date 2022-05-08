/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_mob
*/

#include "rpg.h"

static mobe_t *texture_sprite_mob(mobe_t *node)
{
    sfSprite_setTexture(node->object->sprite, node->object->texture, sfFalse);
    sfSprite_setTextureRect(node->object->sprite, node->object->rect);
    node->hitbox = sfSprite_getGlobalBounds(node->object->sprite);
    node->hitbox_shape = sfRectangleShape_create();
    if (!node->hitbox_shape)
        return NULL;
    sfRectangleShape_setSize(node->hitbox_shape,
    (sfVector2f){node->hitbox.width / 2.2, node->hitbox.height / 2.4});
    sfRectangleShape_setPosition(node->hitbox_shape, \
    (sfVector2f){node->object->position.x - 30, \
    node->object->position.y - 20});
    node->my_clock->clock = sfClock_create();
    node->attack_clock->clock = sfClock_create();
    node->next = NULL;
    return node;
}

static mobe_t *set_info_mob(mobe_t *node, char ***tab, int i)
{
    node->object->position.x = my_atoi(tab[i][CORD_X]);
    node->object->position.y = my_atoi(tab[i][CORD_Y]);
    node->hp = my_atoi(tab[i][HP]);
    node->power = my_atoi(tab[i][POWER]);
    node->type = my_atoi(tab[i][TYPE]);
    node->object->scale = (sfVector2f){-4, 4};
    sfSprite_setScale(node->object->sprite, node->object->scale);
    sfSprite_setOrigin(node->object->sprite, \
    (sfVector2f){my_atoi(tab[i][REC_WIDTH]) / 2, \
    my_atoi(tab[i][REC_HEIGHT]) / 2});
    node = texture_sprite_mob(node);
    sfRectangleShape_setFillColor(node->hitbox_shape, \
    sfColor_fromRGBA(RED_HITBOX));
    node->attack = false;
    node->dead = 0;
    return node;
}

int init_mob(map_t *map, char ***tab, int i)
{
    mobe_t *nde = malloc(sizeof(mobe_t));
    sfIntRect rec = {my_atoi(tab[i][REC_LEFT]), my_atoi(tab[i][REC_TOP]),
    my_atoi(tab[i][REC_WIDTH]), my_atoi(tab[i][REC_HEIGHT])};

    if (!nde)
        return EPITECH_ERROR;
    nde->object = malloc(sizeof(game_object_t));
    nde->my_clock = malloc(sizeof(my_clock_t));
    nde->attack_clock = malloc(sizeof(my_clock_t));
    if (!nde->object || !nde->my_clock || !nde->attack_clock)
        return EPITECH_ERROR;
    nde->object->rect = rec;
    nde->object->texture = sfTexture_createFromFile(tab[i][ASSET], NULL);
    nde->object->sprite = sfSprite_create();
    if (!nde->my_clock->clock || !nde->attack_clock->clock
        || !nde->object->texture || !nde->object->sprite)
        return EPITECH_ERROR;
    nde = set_info_mob(nde, tab, i);
    map->mobe = add_node_to_mobe(map->mobe, nde);
    return EXIT_SUCCESS;
}
