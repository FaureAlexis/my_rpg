/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "rpg.h"

int init_back_window(map_t *map, char ***tab, int i)
{
    if (!map || !tab)
        return EPITECH_ERROR;
    map->back = malloc(sizeof(game_object_t));
    if (map->back == NULL)
        return EPITECH_ERROR;
    map->back->texture = sfTexture_createFromFile(tab[i][ASSET], NULL);
    map->back->sprite = sfSprite_create();
    if (map->back->texture == NULL || map->back->sprite == NULL)
        return EPITECH_ERROR;
    sfSprite_setTexture(map->back->sprite, map->back->texture, sfFalse);
    return EXIT_SUCCESS;
}

int init_map_window(map_t *map, char ***tab, int i)
{
    if (!map || !tab)
        return EPITECH_ERROR;
    map->map = malloc(sizeof(game_object_t));
    if (map->map == NULL)
        return EPITECH_ERROR;
    map->map->texture = sfTexture_createFromFile(tab[i][ASSET], NULL);
    map->map->sprite = sfSprite_create();
    if (map->map->texture == NULL || map->map->sprite == NULL)
        return EPITECH_ERROR;
    map->map->position.x = (my_atoi(tab[i][CORD_X]) * -1);
    map->map->position.y = (my_atoi(tab[i][CORD_Y]) * -1);
    sfSprite_setTexture(map->map->sprite, map->map->texture, sfFalse);
    return EXIT_SUCCESS;
}

int parse_tab_suit(map_t *map, char ***tab, int i)
{
    if (my_arraylen(tab[i]) == 9) {
        if (init_speobstacle(map, tab, i) == EPITECH_ERROR)
            return EPITECH_ERROR;
    }
    if (my_arraylen(tab[i]) == 10) {
        if (init_mob(map, tab, i) == EPITECH_ERROR)
            return EPITECH_ERROR;
    }
    return EXIT_SUCCESS;
}

int parse_tab(map_t *map, char ***tab, int i)
{
    if (!map || !tab)
        return EPITECH_ERROR;
    if (my_arraylen(tab[i]) == -1)
        return EPITECH_ERROR;
    if (my_arraylen(tab[i]) == 1) {
        if (init_back_window(map, tab, i) == EPITECH_ERROR)
            return EPITECH_ERROR;
    }
    if (my_arraylen(tab[i]) == 3) {
        if (init_map_window(map, tab, i) == EPITECH_ERROR)
            return EPITECH_ERROR;
    }
    if (my_arraylen(tab[i]) == 7) {
        if (init_obstacle(map, tab, i) == EPITECH_ERROR)
            return EPITECH_ERROR;
    }
    return parse_tab_suit(map, tab, i);
}
