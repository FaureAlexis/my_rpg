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
    if (sfMusic_getStatus(game->mnu->gameplay->theme) == sfPaused) {
        sfMusic_pause(game->mnu->gameplay->theme);
        sfMusic_play(game->mnu->main->theme);
    }
    sfMusic_play(game->btn->mid->main_b->sound);
    game->skin->red_c = 255;
    game->skin->green_c = 255;
    game->skin->blue_c = 255;
    sfView_reset(game->basic_view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(game->w, game->basic_view);
    return 0;
}
