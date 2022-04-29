/*
** EPITECH PROJECT, 2022
** creat_particule
** File description:
** creat_particule
*/

#include "rpg.h"

particles_t *creat_dust(sfVector2f *cord, int size,
sfVector2f direction)
{
}

particles_t *creat_particles(int enum_type, sfVector2f *cord, int size,
sfVector2f *direction)
{
    particles_t *node = NULL;

    if (enum_type == 0)
        node = creat_dust(cord, size, (*direction));
    if (enum_type == 1)
        node = creat_artifice(cord, size);
    return node;
}
