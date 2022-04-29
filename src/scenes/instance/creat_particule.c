/*
** EPITECH PROJECT, 2022
** creat_particule
** File description:
** creat_particule
*/

#include "rpg.h"

particles_t *creat_poussiere(sfVector2f *cord, int size,
sfVector2f direction)
{
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
}

particles_t *creat_particles(int enum, sfVector2f *cord, int size,
sfVector2f *direction)
{
    particles_t *node = NULL;

    if (enum == 0)
        node = creat_poussiere(cord, size);
    if (enum == 1)
        node = creat_artifice(cord, size);
    return node;
}
