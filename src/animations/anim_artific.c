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

    if (head && head->end > 1) {
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

particles_t *anim_artific(particles_t *head, sfRenderWindow *w)
{
    particles_t *part = head;
    sfVector2i pos = sfMouse_getPositionRenderWindow(w);

    while (part) {
        part->cord.x = pos.x;
        part->cord.y = pos.y;
        part->timer->time = sfClock_getElapsedTime(part->timer->clock);
        part->timer->seconds = part->timer->time.microseconds / 1000000.0;
        if (part->timer->seconds > 0.01) {
            part->end += 0.01;
            my_put_pixel(part, part->direction.x / 2, part->direction.y / 2);
            sfTexture_updateFromPixels(part->texture, part->pixels, part->size,
            part->size, 0, 0);
            sfSprite_setTexture(part->sprite, part->texture, sfFalse);
        }
        sfSprite_setPosition(part->sprite, part->cord);
        sfRenderWindow_drawSprite(w, part->sprite, NULL);
        part = part->next;
    }
    head = free_a_artific(head);
    return head;
}
