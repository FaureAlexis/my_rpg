/*
** EPITECH PROJECT, 2022
** free_game_struct
** File description:
** free_game_struct
*/

#include "rpg.h"

void free_game_struct(main_game_t *game)
{
    free(game->player);
    free(game);
}
