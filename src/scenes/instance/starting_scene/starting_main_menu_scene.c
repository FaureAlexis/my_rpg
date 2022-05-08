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
    game->player->boss_defeated = false;
    game->player->life = 200;
    sfMusic_play(game->mnu->main->theme);
    sfMusic_stop(game->mnu->lose_m->theme);
    sfMusic_stop(game->mnu->win_m->theme);
    if (sfMusic_getStatus(game->mnu->gameplay->theme) == sfPaused) {
        sfMusic_pause(game->mnu->gameplay->theme);
        sfMusic_play(game->mnu->main->theme);
    }
    sfMusic_play(game->btn->mid->main_b->sound);
    game->skin->red_c = 255;
    game->skin->green_c = 255;
    game->skin->blue_c = 255;
    return EXIT_SUCCESS;
}
