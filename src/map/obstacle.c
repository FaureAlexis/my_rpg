/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "lib.h"
#include "rpg.h"
#include <SFML/Graphics.h>

void display_obstacle(main_game_t *game)
{
    obstacle_t *tmp = game->map->obstacle;

    while (tmp) {
        sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
        sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
        sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
        tmp = tmp->next;
    }
}

void init_obstacle(map_t *map, char ***tab, int i)
{
    obstacle_t *node = malloc(sizeof(obstacle_t));
    sfIntRect rec = {my_atoi(tab[i][3]), my_atoi(tab[i][4]),
    my_atoi(tab[i][5]), my_atoi(tab[i][6])};

    node->object = malloc(sizeof(game_object_t));
    node->object->scale = (sfVector2f){5, 5};
    node->object->rect = rec;
    node->object->position.x = my_atoi(tab[i][1]);
    node->object->position.y = my_atoi(tab[i][2]);
    node->object->texture = sfTexture_createFromFile(tab[i][0], NULL);
    node->object->sprite = sfSprite_create();
    node->next = NULL;
    sfSprite_setScale(node->object->sprite, node->object->scale);
    sfSprite_setOrigin(node->object->sprite,
    (sfVector2f){my_atoi(tab[i][5]) / 2, my_atoi(tab[i][6]) / 2});
    sfSprite_setTexture(node->object->sprite, node->object->texture, sfFalse);
    sfSprite_setTextureRect(node->object->sprite, node->object->rect);
    map->obstacle = add_node_to_obstacle(map->obstacle, node);
}
