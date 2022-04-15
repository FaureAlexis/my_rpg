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
    map->tab = make_tab(MAP_TXT);
    if (!map->tab)
        return NULL;
    for (int i = 0; map->tab[i] != NULL; i += 1)
        parse_tab(map, map->tab, i);
    return map;
}
