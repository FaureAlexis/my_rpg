/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

int starting_settings_scene(main_game_t *game)
{
    game->player->current_scene = SETTINGS_SCENE;
    if (game->menu_depth == 0 || game->menu_depth == 2)
        game->menu_depth = 1;
    else if (game->menu_depth == 7)
        game->menu_depth = 6;
    sfMusic_pause(game->mnu->gameplay->theme);
    sfMusic_play(game->btn->big->settings_b->sound);
    return 0;
}
