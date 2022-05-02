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
    node->texture = sfTexture_create(node->size + 2, node->size + 2);
    node->sprite = sfSprite_create();
    node->pixels = malloc(((node->size + 2) * (node->size + 2)) * 4);
    draw_circle(node, (node->size / 2));
    sfTexture_updateFromPixels(node->texture, node->pixels, node->size,
    node->size, 0, 0);
    sfSprite_setTexture(node->sprite, node->texture, sfFalse);
    sfSprite_setTextureRect(node->sprite, (sfIntRect){0, 0, node->size, \
    node->size});
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
    node->texture = sfTexture_create(node->size + 2, node->size + 2);
    node->sprite = sfSprite_create();
    node->pixels = malloc(((node->size + 2) * (node->size + 2)) * 4);
    sfTexture_updateFromPixels(node->texture, node->pixels, node->size,
    node->size, 0, 0);
    sfSprite_setOrigin(node->sprite, (sfVector2f){node->size / 2 + 1,
    node->size / 2 + 1});
    sfSprite_setTexture(node->sprite, node->texture, sfFalse);
    sfSprite_setTextureRect(node->sprite, (sfIntRect){0, 0, node->size, \
    node->size});
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
    particles_t *part = NULL;
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
