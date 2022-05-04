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
    sfRectangleShape_setSize(node->shape, (sfVector2f){node->size + 2,
    node->size + 2});
    node->pixels = malloc(((node->size + 2) * (node->size + 2)) * 4);
    draw_circle(node, (node->size / 2));
    node->texture = sfTexture_create(node->size + 2, node->size + 2);
    sfTexture_updateFromPixels(node->texture, node->pixels, node->size + 2,
    node->size + 2, 0, 0);
    sfRectangleShape_setTexture(node->shape, node->texture, false);
    return node;
}

particles_t *create_artific(sfVector2f cord, int size, sfVector2f direction)
{
    particles_t *node = malloc(sizeof(particles_t));

    node->next = NULL;
    node->size = size;
    node->timer = malloc(sizeof(my_clock_t));
    node->timer->clock = sfClock_create();
    node->direction.x = direction.x;
    node->direction.y = direction.y;
    node->texture = sfTexture_create(2, node->size + 1);
    node->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(node->shape, (sfVector2f){2, node->size + 1});
    node->pixels = malloc(((2 * (node->size + 1)) * 4));
    node->cord.x = cord.x;
    node->cord.y = cord.y;
    node->end = 0;
    srand(rand());
    if (rand() % 3 == 0)
        node->color = sfYellow;
    else
        node->color = sfWhite;
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

void gen_artific(speobstacle_t *chest)
{
    particles_t *node = NULL;
    sfVector2f lane = chest->object->position;

    if (chest->type == 2 && chest->artific == NULL) {
        for (int i = 0; i < chest->object->rect.width; i += 1) {
            lane.x += 1;
            node = creat_particles(1, lane, 19,
            (sfVector2f){0, 20});
            chest->artific = add_particle_to_list(chest->artific, node,
            (sfVector2f){0, 0});
        }
    }
}
