/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "lib.h"
#include "rpg.h"
#include <SFML/Graphics.h>

void init_back_window(map_t *map, char ***tab, int i)
{
    map->back = malloc(sizeof(game_object_t));
    map->back->texture = sfTexture_createFromFile(tab[i][0], NULL);
    map->back->sprite = sfSprite_create();
    sfSprite_setTexture(map->back->sprite, map->back->texture, sfFalse);
}

void init_map_window(map_t *map, char ***tab, int i)
{
    map->map = malloc(sizeof(game_object_t));
    map->map->texture = sfTexture_createFromFile(tab[i][0], NULL);
    map->map->sprite = sfSprite_create();
    map->map->position.x = (my_atoi(tab[i][1]) * -1);
    map->map->position.y = (my_atoi(tab[i][2]) * -1);
    sfSprite_setTexture(map->map->sprite, map->map->texture, sfFalse);
}

void parse_tab(map_t *map, char ***tab, int i)
{
    if (my_arraylen(tab[i]) == 1) {
        init_back_window(map, tab, i);
    }
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
