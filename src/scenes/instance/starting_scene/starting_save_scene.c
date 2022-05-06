/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

int starting_save_scene(main_game_t *game)
{
    game->player->current_scene = SAVE_SCENE;
    game->menu_depth = 2;
    sfMusic_pause(game->mnu->gameplay->theme);
    sfMusic_play(game->btn->big->play_b->sound);
    return EXIT_SUCCESS;
}
