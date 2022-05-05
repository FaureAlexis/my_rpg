/*
** EPITECH PROJECT, 2022
** anim_particule
** File description:
** anim_particule
*/

#include "rpg.h"

void my_put_pixel(particles_t *particle, unsigned int x, unsigned int y,
sfColor color)
{
    int open = 0;

    open = ((particle->size + 2) * y + x) * 4;
    particle->pixels[open + 0] = color.r;
    particle->pixels[open + 1] = color.g;
    particle->pixels[open + 2] = color.b;
    particle->pixels[open + 3] = color.a;
}

int draw_circle(particles_t *particle, int radius, sfColor color)
{
    int end_x = particle->size;
    int end_y = particle->size;

    for (int start_x = 0; start_x <= end_x; start_x += 1) {
        for (int start_y = 0; start_y <= end_y; start_y += 1) {
            if ((pow(start_x - (particle->size / 2), 2) + pow(start_y -
            (particle->size / 2), 2)) <= pow(radius, 2))
                my_put_pixel(particle, start_y, start_x, color);
            else
                my_put_pixel(particle, start_y, start_x,
                (sfColor){0, 0, 0, 0});
        }
    }
    return 0;
}

particles_t *free_a_particule(particles_t *head)
{
    particles_t *tmp = NULL;

    if (head && head->end > 0.75) {
        tmp = head->next;
        free(head->timer);
        free(head->pixels);
        sfRectangleShape_destroy(head->shape);
        free(head);
        head = tmp;
    }
    return head;
}

particles_t *add_particle_to_list(particles_t *head, particles_t *node,
sfVector2f move)
{
    particles_t *tmp = head;

    if (node == NULL)
        return head;
    if (head == NULL) {
        head = node;
    } else {
        while (tmp->next != NULL){
            tmp->cord.x += move.x;
            tmp->cord.y += move.y;
            tmp = tmp->next;
        }
        tmp->cord.x += move.x;
        tmp->cord.y += move.y;
        tmp->next = node;
    }
    return head;
}

particles_t *anim_dust(particles_t *head, sfRenderWindow *w)
{
    particles_t *part = head;

    while (part) {
        part->timer->time = sfClock_getElapsedTime(part->timer->clock);
        part->timer->seconds = part->timer->time.microseconds / 1000000.0;
        if (part->direction.x == 6)
            part->y = part->cord.y;
        if (part->timer->seconds > 0.01) {
            part->end += 0.01;
            part->cord.y = part->y + (part->direction.y /
            sqrt(pow(part->direction.y, 2))) * ((8 - part->direction.x)
            * sqrt(pow(cos((part->direction.y) * part->end), 2)));
            sfClock_restart(part->timer->clock);
        }
        sfRectangleShape_setPosition(part->shape, part->cord);
        sfRenderWindow_drawRectangleShape(w, part->shape, NULL);
        part = part->next;
    }
    head = free_a_particule(head);
    return head;
}
