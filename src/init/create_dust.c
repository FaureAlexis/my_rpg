/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** creat_dust
*/

#include "rpg.h"

static particles_t *set_info_dust(particles_t *node, sfVector2f cord, int size,
sfVector2f direction)
{
    node->next = NULL;
    node->size = size;
    node->end = 0;
    node->cord.x = cord.x;
    node->cord.y = node->y = cord.y + 50;
    node->direction.x = direction.x;
    node->direction.y = direction.y;
    return node;
}

particles_t *create_dust(sfVector2f cord, int size, sfVector2f direction)
{
    particles_t *node = malloc(sizeof(particles_t));

    node = set_info_dust(node, cord, size, direction);
    node->timer = malloc(sizeof(my_clock_t));
    node->timer->clock = sfClock_create();
    node->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(node->shape, (sfVector2f){node->size + 2,
    node->size + 2});
    node->pixels = malloc(((node->size + 2) * (node->size + 2)) * 4);
    draw_circle(node, (node->size / 2), DUST_COLOR);
    node->texture = sfTexture_create(node->size + 2, node->size + 2);
    sfTexture_updateFromPixels(node->texture, node->pixels, node->size + 2,
    node->size + 2, 0, 0);
    sfRectangleShape_setTexture(node->shape, node->texture, false);
    return node;
}
