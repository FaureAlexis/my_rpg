/*
** EPITECH PROJECT, 2022
** mode
** File description:
** rpg
*/

#include "rpg.h"

void display_mob(main_game_t *game)
{
    mobe_t *tmp = game->map->mobe;

    while (tmp) {
        if (tmp->type == 0)
            display_slime(tmp, game);
        if (tmp->type == 1)
            display_skeleton(tmp, game);
        if (tmp->type == 10)
            display_hasbulla(tmp, game);
        tmp = tmp->next;
    }
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
    sfSprite_setOrigin(node->object->sprite,
    (sfVector2f){my_atoi(tab[i][REC_WIDTH]) / 2,
    my_atoi(tab[i][REC_HEIGHT]) / 2});
    sfSprite_setTexture(node->object->sprite, node->object->texture, sfFalse);
    sfSprite_setTextureRect(node->object->sprite, node->object->rect);
    node->hitbox = sfSprite_getGlobalBounds(node->object->sprite);
    node->hitbox_shape = sfRectangleShape_create();
    if (!node->hitbox_shape)
        return NULL;
    sfRectangleShape_setSize(node->hitbox_shape,
    (sfVector2f){node->hitbox.width / 2.2, node->hitbox.height / 2.4});
    sfRectangleShape_setPosition(node->hitbox_shape,
    (sfVector2f){node->object->position.x - 30,
    node->object->position.y - 20});
    sfRectangleShape_setFillColor(node->hitbox_shape,
    sfColor_fromRGBA(255, 0, 0, 100));
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
    nde->my_clock->clock = sfClock_create();
    nde->attack_clock->clock = sfClock_create();
    nde->object->rect = rec;
    nde->attack = false;
    nde->object->texture = sfTexture_createFromFile(tab[i][ASSET], NULL);
    nde->object->sprite = sfSprite_create();
    if (!nde->my_clock->clock || !nde->attack_clock->clock
        || !nde->object->texture || !nde->object->sprite)
        return EPITECH_ERROR;
    nde->dead = 0;
    nde->next = NULL;
    nde = set_info_mob(nde, tab, i);
    map->mobe = add_node_to_mobe(map->mobe, nde);
    return EXIT_SUCCESS;
}
