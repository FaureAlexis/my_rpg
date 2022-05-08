/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

int starting_lose_scene(main_game_t *game)
{
    game->player->current_scene = LOSE_SCENE;
    game->menu_depth = 0;
    sfMusic_pause(game->mnu->gameplay->theme);
    sfMusic_play(game->btn->mid->main_b->sound);
    sfMusic_play(game->mnu->lose_m->theme);
    return EXIT_SUCCESS;
}
