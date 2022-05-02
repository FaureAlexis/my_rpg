/*
** EPITECH PROJECT, 2022
** mode
** File description:
** rpg
*/

#include "rpg.h"

void attack_slime(mobe_t *mob, player_t *player)
{
    if (mob->attack == true) {
        if(mob->object->rect.left >= 160 && mob->object->rect.top == 64) {
            mob->object->rect.left = 0;
            mob->object->rect.top -= 32;
        }
        if(mob->object->rect.left >= 128 && mob->object->rect.top == 32) {
            mob->object->rect.left = 0;
            mob->object->rect.top -= 32;
        }
        mob->object->position.x += (player->object->position.x -
        mob->object->position.x) / (sqrt(pow(player->object->position.x -
        mob->object->position.x, 2) + pow(player->object->position.y -
        mob->object->position.y, 2)));
        mob->object->position.y += (player->object->position.y -
        mob->object->position.y) / (sqrt(pow(player->object->position.x -
        mob->object->position.x, 2) + pow(player->object->position.y -
        mob->object->position.y, 2)));
        sfRectangleShape_setPosition(mob->hitbox_shape,
        (sfVector2f){mob->object->position.x - 30,
        mob->object->position.y - 20});
    } else {
        if (mob->object->rect.left >= 96)
            mob->object->rect.left = 0;
    }
    if (mob->object->rect.top == 0)
        mob->attack = false;
}

void display_mob(main_game_t *game)
{
    mobe_t *tmp = game->map->mobe;

    while (tmp) {
        if (sqrt(pow(game->player->object->position.x - tmp->object->position.x,
        2) + pow(game->player->object->position.y - tmp->object->position.y, 2))
        < 80 * 5) {
            tmp->object->rect.top = 64;
            tmp->attack = true;
        }
        tmp->my_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
        tmp->my_clock->seconds = tmp->my_clock->time.microseconds / 1000000.0;
        if (tmp->my_clock->seconds >= 0.1) {
            tmp->object->rect.left += 32;
            sfClock_restart(tmp->my_clock->clock);
        }
        attack_slime(tmp, game->player);
        sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
        sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
        sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
        sfRenderWindow_drawRectangleShape(game->w, tmp->hitbox_shape, NULL);
        tmp = tmp->next;
    }
}

static mobe_t *set_info_mob(mobe_t *node, char ***tab, int i)
{
    node->object->scale = (sfVector2f){4, 4};
    node->object->position.x = my_atoi(tab[i][1]);
    node->object->position.y = my_atoi(tab[i][2]);
    node->hp = my_atoi(tab[i][7]);
    node->power = my_atoi(tab[i][8]);
    sfSprite_setScale(node->object->sprite, node->object->scale);
    sfSprite_setOrigin(node->object->sprite, (sfVector2f){my_atoi(tab[i][5]) \
    / 2, my_atoi(tab[i][6]) / 2});
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
    sfIntRect rec = {my_atoi(tab[i][3]), my_atoi(tab[i][4]),
    my_atoi(tab[i][5]), my_atoi(tab[i][6])};

    if (!nde)
        return EPITECH_ERROR;
    nde->object = malloc(sizeof(game_object_t));
    nde->my_clock = malloc(sizeof(my_clock_t));
    if (!nde->object || !nde->my_clock)
        return EPITECH_ERROR;
    nde->my_clock->clock = sfClock_create();
    nde->object->rect = rec;
    nde->attack = false;
    nde->object->texture = sfTexture_createFromFile(tab[i][0], NULL);
    nde->object->sprite = sfSprite_create();
    if (!nde->my_clock->clock || !nde->object->texture || !nde->object->sprite)
        return EPITECH_ERROR;
    nde->next = NULL;
    nde = set_info_mob(nde, tab, i);
    map->mobe = add_node_to_mobe(map->mobe, nde);
    return EXIT_SUCCESS;
}
