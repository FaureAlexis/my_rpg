/*
** EPITECH PROJECT, 2022
** pause_scene
** File description:
** pause_scene
*/

#include "rpg.h"

int starting_pause_scene(main_game_t *game)
{
    sfMusic_stop(game->btn->mid->pause_b->sound);
    game->player->current_scene = PAUSE_SCENE;
    game->menu_depth = 5;
    sfMusic_pause(game->mnu->gameplay->theme);
    sfMusic_play(game->btn->mid->pause_b->sound);
    sfView_reset(game->basic_view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(game->w, game->basic_view);
    return 0;
}
