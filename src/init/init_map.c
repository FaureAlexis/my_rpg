/*
** EPITECH PROJECT, 2022
** init_map
** File description:
** init_map
*/

#include "rpg.h"

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    map->artificlock = malloc(sizeof(my_clock_t));
    map->tab = make_tab(MAP_TXT);
    if (!map->tab || !map->artificlock)
        return NULL;
    map->artificlock->clock = sfClock_create();
    for (int i = 0; map->tab[i] != NULL; i += 1)
        if (parse_tab(map, map->tab, i) == EPITECH_ERROR)
            return NULL;
    return map;
}
