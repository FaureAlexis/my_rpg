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
    sfMusic_pause(game->mnu->gameplay->theme);
    sfMusic_play(game->btn->mid->keybind_b->sound);
    sfView_reset(game->basic_view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(game->w, game->basic_view);
    return 0;
}
