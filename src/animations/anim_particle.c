/*
** EPITECH PROJECT, 2022
** anim_particule
** File description:
** anim_particule
*/

#include "rpg.h"

void my_put_pixel(particles_t *particle, unsigned int x, unsigned int y)
{
    int open = 0;
    int idx = 1;

    open = (particle->size * x + y) * 4;
    particle->pixels[open + 0] = 255;
    particle->pixels[open + 1] = 255;
    particle->pixels[open + 2] = 255;
    particle->pixels[open + 3] = 255;
}

int draw_circle(particles_t *particle, int radius)
{
    int start_x = ((particle->size / 2 + 1) - radius);
    int start_y = ((particle->size / 2 + 1) - radius);
    int end_x = ((particle->size / 2 + 1) + radius);
    int end_y = ((particle->size / 2 + 1) + radius);

    while (start_x <= end_x) {
        while (start_y <= end_y) {
            if ((((start_x - ((particle->size / 2 + 1))) * (start_x -
            ((particle->size / 2 + 1)))) +
            ((start_y - ((particle->size / 2 + 1))) *
            (start_y - ((particle->size / 2 + 1))))) <= (radius * radius))
                my_put_pixel(particle, start_y, start_x);
            start_y += 1;
        }
        start_x += 1;
        start_y = (((particle->size / 2 + 1)) - radius);
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
        sfSprite_destroy(head->sprite);
        sfTexture_destroy(head->texture);
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
        sfSprite_setPosition(part->sprite, part->cord);
        sfRenderWindow_drawSprite(w, part->sprite, NULL);
        part = part->next;
    }
    head = free_a_particule(head);
    return head;
}
