/*
** EPITECH PROJECT, 2022
** mode
** File description:
** rpg
*/

#include "lib.h"
#include "rpg.h"
#include <SFML/Graphics.h>

void display_mobe(main_game_t *game)
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

void init_mobe(map_t *map, char ***tab, int i)
{
    mobe_t *node = malloc(sizeof(mobe_t));
    sfIntRect rec = {my_atoi(tab[i][3]), my_atoi(tab[i][4]),
    my_atoi(tab[i][5]), my_atoi(tab[i][6])};

    node->object = malloc(sizeof(game_object_t));
    node->my_clock = malloc(sizeof(my_clock_t));
    node->my_clock->clock = sfClock_create();
    node->object->scale = (sfVector2f){5, 5};
    node->object->rect = rec;
    node->object->position.x = my_atoi(tab[i][0]);
    node->object->position.y = my_atoi(tab[i][1]);
    node->object->texture = sfTexture_createFromFile(tab[i][2], NULL);
    node->object->sprite = sfSprite_create();
    node->hp = my_atoi(tab[i][7]);
    node->power = my_atoi(tab[i][8]);
    node->next = NULL;
    sfSprite_setScale(node->object->sprite, node->object->scale);
    sfSprite_setOrigin(node->object->sprite, (sfVector2f){my_atoi(tab[i][5]) \
    / 2, my_atoi(tab[i][6]) / 2});
    sfSprite_setTexture(node->object->sprite, node->object->texture, sfFalse);
    sfSprite_setTextureRect(node->object->sprite, node->object->rect);
    map->mobe = add_node_to_mobe(map->mobe, node);
}
