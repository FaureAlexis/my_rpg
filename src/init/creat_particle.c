/*
** EPITECH PROJECT, 2022
** creat_particule
** File description:
** creat_particule
*/

#include "rpg.h"

particles_t *create_dust(sfVector2f cord, int size, sfVector2f direction)
{
    particles_t *node = malloc(sizeof(particles_t));

    node->next = NULL;
    node->size = size;
    node->timer = malloc(sizeof(my_clock_t));
    node->timer->clock = sfClock_create();
    node->end = 0;
    node->cord.x = cord.x;
    node->cord.y = node->y = cord.y + 50;
    node->direction.x = direction.x;
    node->direction.y = direction.y;
    node->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(node->shape, (sfVector2f){node->size + 2, node->size + 2});
    node->pixels = malloc(((node->size + 2) * (node->size + 2)) * 4);
    sfRectangleShape_setFillColor(node->shape, sfColor_fromRGB(153, 150, 146));
    draw_circle(node, (node->size / 2));
    return node;
}

particles_t *create_artific(sfVector2f cord, int size, sfVector2f direction)
{
    particles_t *node = malloc(sizeof(particles_t));

    node->next = NULL;
    node->size = size;
    node->timer = malloc(sizeof(my_clock_t));
    node->timer->clock = sfClock_create();
    node->cord.x = cord.x;
    node->cord.y = cord.y;
    node->end = 0;
    node->direction.x = direction.x;
    node->direction.y = direction.y;
    return node;
}

particles_t *creat_particles(int enuma, sfVector2f cord, int size,
sfVector2f direction)
{
    particles_t *node = NULL;

    srand(rand());
    if (enuma == 0 && (rand() % 4 == 0))
        node = create_dust(cord, size, direction);
    if (enuma == 1)
        node = create_artific(cord, size, direction);
    return node;
}

particles_t *gen_artific(sfRenderWindow *w)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(w);
    sfVector2f cord = {tmp.x, tmp.y};
    int size = 30;
    sfVector2f direction = {size / 2 - 1, size / 2 - 1};

    srand(rand());
    if (rand() % 2 == 0) {
        srand(rand());
        direction.x = rand() % (size / 2 - 1);
    } else {
        srand(rand());
        direction.y = rand() % (size / 2 - 1);
    }
    srand(rand());
    if (rand() % 2 == 0)
        direction.x = direction.x * -1;
    srand(rand());
    if (rand() % 2 == 0)
        direction.y = direction.y * -1;
    return creat_particles(1, cord, size, direction);
}
