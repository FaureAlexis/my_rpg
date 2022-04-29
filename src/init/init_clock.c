/*
** EPITECH PROJECT, 2022
** init_clock
** File description:
** init_clock
*/

#include "rpg.h"

my_clock_t *init_clock(void)
{
    my_clock_t *my_clock = malloc(sizeof(my_clock_t));

    if (!my_clock)
        return NULL;
    my_clock->clock = sfClock_create();
    if (!my_clock->clock)
        return NULL;
    my_clock->seconds = 0;
    return my_clock;
}
