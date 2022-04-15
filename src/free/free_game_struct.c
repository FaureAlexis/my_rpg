/*
** EPITECH PROJECT, 2022
** free_game_struct
** File description:
** free_game_struct
*/

#include "rpg.h"

void free_game_struct(main_game_t *game)
{
    sfMusic_destroy(game->mnu->main->theme);
    sfMusic_destroy(game->mnu->gameplay->theme);
    free(game->player);
    free(game);
}
