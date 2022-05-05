/*
** EPITECH PROJECT, 2022
** anim_artific
** File description:
** anim_artific
*/

#include "rpg.h"

void free_a_artific(speobstacle_t *spe)
{
    particles_t *tmp = NULL;

    if (spe->artific && spe->object->rect.left == 0) {
        tmp = spe->artific->next;
        free(spe->artific->timer);
        free(spe->artific->pixels);
        free(spe->artific);
        spe->artific = tmp;
    }
}

particles_t *anim_artific(particles_t *head, sfRenderWindow *w,
speobstacle_t *spe)
{
    particles_t *part = head;

    while (part && spe->object->rect.left != 0) {
        part->timer->time = sfClock_getElapsedTime(part->timer->clock);
        part->timer->seconds = part->timer->time.microseconds / 1000000.0;
        if (part->timer->seconds > 0.1 && part->end <= 10) {
            part->cord.y -= 1;
            part->end += 1;
            sfClock_restart(part->timer->clock);
        }
        sfRectangleShape_setPosition(part->shape, part->cord);
        sfRenderWindow_drawRectangleShape(w, part->shape, NULL);
        part = part->next;
    }
    free_a_artific(spe);
    return head;
}
