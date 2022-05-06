/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

int starting_help_scene(main_game_t *game)
{
    game->player->current_scene = HELP_SCENE;
    if (game->menu_depth == 0)
        game->menu_depth = 1;
    else if (game->menu_depth == 1)
        game->menu_depth = 2;
    else
        game->menu_depth = 7;
    sfMusic_pause(game->mnu->gameplay->theme);
    sfMusic_play(game->btn->mid->help_b->sound);
    return EXIT_SUCCESS;
}
