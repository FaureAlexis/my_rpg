/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

int starting_win_scene(main_game_t *game)
{
    game->player->current_scene = WIN_SCENE;
    game->menu_depth = 0;
    if (sfMusic_getStatus(game->mnu->gameplay->theme) == sfPaused) {
        sfMusic_pause(game->mnu->gameplay->theme);
        sfMusic_play(game->mnu->main->theme);
    }
    sfMusic_play(game->btn->mid->main_b->sound);
    return EXIT_SUCCESS;
}
