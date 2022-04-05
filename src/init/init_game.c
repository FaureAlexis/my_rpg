/*
** EPITECH PROJECT, 2022
** init_game
** File description:
** init_game
*/

#include "rpg.h"

main_game_t *init_game(void)
{
    main_game_t *game = malloc(sizeof(main_game_t));

    game->window = init_window();
    game->player = init_player();
    return game;
}
