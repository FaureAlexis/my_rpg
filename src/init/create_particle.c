/*
** EPITECH PROJECT, 2022
** creat_particule
** File description:
** creat_particule
*/

#include "rpg.h"

particles_t *create_artific(sfVector2f cord, int size, sfVector2f direction)
{
    particles_t *node = malloc(sizeof(particles_t));

    node->next = NULL;
    node->size = size;
    node->timer = malloc(sizeof(my_clock_t));
    node->timer->clock = sfClock_create();
    node->end = 0;
    node->cord.x = cord.x - (size / 2) - 1;
    node->cord.y = cord.y - 20;
    node->direction.x = direction.x;
    node->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(node->shape, (sfVector2f){node->size + 2,
    node->size + 2});
    node->pixels = malloc(((node->size + 2) * (node->size + 2)) * 4);
    draw_circle(node, (node->size / 2), sfYellow);
    node->texture = sfTexture_create(node->size + 2, node->size + 2);
    sfTexture_updateFromPixels(node->texture, node->pixels, node->size + 2,
    node->size + 2, 0, 0);
    sfRectangleShape_setTexture(node->shape, node->texture, false);
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

    if (chest->type == 2 && chest->artific == NULL) {
        node = creat_particles(1, chest->object->position, 20,
        (sfVector2f){0, 20});
        chest->artific = add_particle_to_list(chest->artific, node,
        (sfVector2f){0, 0});
    }
}
