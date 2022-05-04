/*
** EPITECH PROJECT, 2022
** anim_artific
** File description:
** anim_artific
*/

#include "rpg.h"

particles_t *free_a_artific(particles_t *head)
{
    particles_t *tmp = NULL;

    if (head && head->end > 20) {
        tmp = head->next;
        free(head->timer);
        free(head->pixels);
        sfTexture_destroy(head->texture);
        free(head);
        head = tmp;
    }
    return head;
}

particles_t *anim_artific(particles_t *head, sfRenderWindow *w)
{
    particles_t *part = head;

    while (part) {
        part->timer->time = sfClock_getElapsedTime(part->timer->clock);
        part->timer->seconds = part->timer->time.microseconds / 1000000.0;
        if (part->timer->seconds > 0.01) {
            if (part->size > part->end) {
                my_put_pixel(part, 1, part->size - part->end, part->color);
                sfTexture_updateFromPixels(part->texture, part->pixels, 2,
                part->size + 1, 0, 0);
                sfRectangleShape_setTexture(part->shape, part->texture, false);
            }
            part->end += 1;
            sfClock_restart(part->timer->clock);
        }
        sfRectangleShape_setPosition(part->shape, part->cord);
        sfRenderWindow_drawRectangleShape(w, part->shape, NULL);
        part = part->next;
    }
    head = free_a_artific(head);
    return head;
}
