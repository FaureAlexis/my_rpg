/*
** EPITECH PROJECT, 2022
** free_game_struct
** File description:
** free_game_struct
*/

#include "rpg.h"

int free_game_struct(main_game_t *game)
{
    if (free_player(game->player) == EPITECH_ERROR)
        return EPITECH_ERROR;
    destroy_all_menu(game);
    destroy_all_button(game);
    destroy_all_texts(game);
    return EXIT_SUCCESS;
}
