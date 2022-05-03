/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

int starting_keybind_scene(main_game_t *game)
{
    game->player->current_scene = KEYBIND_SCENE;
    if (game->menu_depth == 4)
        game->menu_depth = 5;
    else
        game->menu_depth = 1;
    return 0;
}
