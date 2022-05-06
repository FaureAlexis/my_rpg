/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_and_set_buttons
*/

#include "rpg.h"

void set_rect_all_buttons(main_game_t *game)
{
    set_rect_big_buttons(game);
    set_rect_mid_buttons(game);
    set_rect_small_buttons(game);
}

int create_all_buttons(main_game_t *game)
{
    if (create_all_big_buttons(game) == EPITECH_ERROR
    || create_all_medium_buttons(game) == EPITECH_ERROR
    || create_all_small_buttons(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int init_all_buttons(main_game_t *game)
{
    if (create_all_buttons(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    set_rect_all_buttons(game);
    return EXIT_SUCCESS;
}
