/*
** EPITECH PROJECT, 2022
** check_game_assets
** File description:
** check_game_assets
*/

#include "rpg.h"

int check_game_assets(main_game_t *game)
{
    map_t *map = NULL;

    if (!game)
        return EPITECH_ERROR;
    map = game->map;
    if (!map->obstacle || !map->speobstacle || !map->mobe || !map->back
        || !map->map)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
