/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "lib.h"
#include "rpg.h"
#include <SFML/Graphics.h>

void init_map_window(map_t *map, char ***tab, int i)
{
    map->object = malloc(sizeof(game_object_t));
    map->object->texture = sfTexture_createFromFile(tab[i][0], NULL);
    map->object->sprite = sfSprite_create();
    sfSprite_setTexture(map->object->sprite, map->object->texture, sfFalse);
}

void parse_tab(map_t *map, char ***tab, int i)
{
    if (my_arraylen(tab[i]) == 3) {
        init_map_window(map, tab, i);
    }
    if (my_arraylen(tab[i]) == 7) {
        init_obstacle(map, tab, i);
    }
    if (my_arraylen(tab[i]) == 9) {
        init_mobe(map, tab, i);
    }
}
