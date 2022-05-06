/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free_a_particle
*/

#include "rpg.h"

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
