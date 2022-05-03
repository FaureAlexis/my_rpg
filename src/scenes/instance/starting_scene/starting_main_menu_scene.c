/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

int starting_main_menu_scene(main_game_t *game)
{
    game->player->current_scene = MENU_SCENE;
    game->menu_depth = 0;
    sfMusic_stop(game->btn->big->return_b->sound);
    sfMusic_stop(game->btn->mid->main_b->sound);
    game->skin->red_c = 255;
    game->skin->green_c = 255;
    game->skin->blue_c = 255;
    return 0;
}
