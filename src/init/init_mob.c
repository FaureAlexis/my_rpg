/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_mob
*/

#include "rpg.h"

static mobe_t *set_info_mob(mobe_t *node, char ***tab, int i)
{
    sfFont *font = NULL;

    node->object->position.x = my_atoi(tab[i][CORD_X]);
    node->object->position.y = my_atoi(tab[i][CORD_Y]);
    node->hp = my_atoi(tab[i][HP]);
    node->life_txt = sfText_create();
    font = sfFont_createFromFile(TEXT_FONT);
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
    if (!node->hitbox_shape || !node->life_txt || !font)
        return NULL;
    sfText_setFont(node->life_txt, font);
    sfText_setPosition(node->life_txt, (sfVector2f){500, 500});
    node->life_str = my_int_to_str(node->hp);
    sfText_setString(node->life_txt, node->life_str);
    sfText_setScale(node->life_txt, (sfVector2f){0.6, 0.6});
    sfRectangleShape_setSize(node->hitbox_shape,
    (sfVector2f){node->hitbox.width / 2.2, node->hitbox.height / 2.4});
    sfRectangleShape_setPosition(node->hitbox_shape,
    (sfVector2f){node->object->position.x - 30,
    node->object->position.y - 20});
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
