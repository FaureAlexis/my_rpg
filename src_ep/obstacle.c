/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "lib.h"
#include "rpg.h"
#include <SFML/Graphics.h>

void display_obstacle(game_scene_t *src)
{
    obstacle_t *tmp = src->obstacle;

    while (tmp) {
        sfSprite_setTextureRect(tmp->src->sprite, tmp->src->frame);
        sfSprite_setPosition(tmp->src->sprite, tmp->src->cord);
        sfRenderWindow_drawSprite(src->window->window, tmp->src->sprite, NULL);
        tmp = tmp->next;
    }
}

void init_obstacle(game_scene_t *src, char ***tab, int i)
{
    obstacle_t *node = malloc(sizeof(obstacle_t));
    sfVector2f tall = {5, 5};
    sfIntRect rec = {my_atoi(tab[i][3]), my_atoi(tab[i][4]), \
    my_atoi(tab[i][5]), my_atoi(tab[i][6])};

    node->src = malloc(sizeof(game_object_s));
    node->src->frame = rec;
    node->src->cord.x = my_atoi(tab[i][0]);
    node->src->cord.y = my_atoi(tab[i][1]);
    node->src->texture = sfTexture_createFromFile(tab[i][2], NULL);
    node->src->sprite = sfSprite_create();
    node->next = NULL;
    sfSprite_setScale(node->src->sprite, tall);
    sfSprite_setOrigin(node->src->sprite, (sfVector2f){my_atoi(tab[i][5]) / 2, \
    my_atoi(tab[i][6]) / 2});
    sfSprite_setTexture(node->src->sprite, node->src->texture, sfFalse);
    sfSprite_setTextureRect(node->src->sprite, node->src->frame);
    src->obstacle = add_node_to_obstacle(src->obstacle, node);
}
