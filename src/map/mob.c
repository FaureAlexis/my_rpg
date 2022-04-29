/*
** EPITECH PROJECT, 2022
** mode
** File description:
** rpg
*/

#include "lib.h"
#include "rpg.h"
#include <SFML/Graphics.h>

void display_mob(main_game_t *game)
{
    mobe_t *tmp = game->map->mobe;

    while (tmp) {
        tmp->my_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
        tmp->my_clock->seconds = tmp->my_clock->time.microseconds / 1000000.0;
        if (tmp->my_clock->seconds >= 0.1) {
            tmp->object->rect.left += 32;
            sfClock_restart(tmp->my_clock->clock);
        } else if (tmp->object->rect.left >= 96) {
            tmp->object->rect.left = 0;
        }
        sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
        sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
        sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
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
    nde->object->texture = sfTexture_createFromFile(tab[i][0], NULL);
    nde->object->sprite = sfSprite_create();
    if (!nde->my_clock->clock || !nde->object->texture || !nde->object->sprite)
        return EPITECH_ERROR;
    nde->next = NULL;
    nde = set_info_mob(nde, tab, i);
    map->mobe = add_node_to_mobe(map->mobe, nde);
    return EXIT_SUCCESS;
}
