/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** resize_all_buttons
*/

#include "rpg.h"

int resize_all_big_buttons(main_game_t *game, float x, float y)
{
    set_big_buttons_sprite_pos(game);
    resize_big_buttons(game, x, y);
    resize_pos_big_buttons(game, x, y);
    return EXIT_SUCCESS;
}

int resize_all_mid_buttons(main_game_t *game, float x, float y)
{
    set_mid_buttons_sprite_pos(game);
    resize_mid_buttons(game, x, y);
    resize_pos_mid_buttons(game, x, y);
    return EXIT_SUCCESS;
}

int resize_all_sml_buttons(main_game_t *game, float x, float y)
{
    set_sml_buttons_sprite_pos(game);
    resize_sml_buttons(game, x, y);
    resize_pos_sml_buttons(game, x, y);
    return EXIT_SUCCESS;
}

int resize_all_buttons(main_game_t *game, float x, float y)
{
    resize_all_big_buttons(game, x, y);
    resize_all_mid_buttons(game, x, y);
    resize_all_sml_buttons(game, x, y);
    return EXIT_SUCCESS;
}
