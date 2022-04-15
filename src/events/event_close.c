/*
** EPITECH PROJECT, 2022
** event_close
** File description:
** event_close
*/

#include "rpg.h"

int close_window(main_game_t *game)
{
    sfRenderWindow_close(game->w);
    game->player->next_scene = UNKNOWN_SCENE;
    return game->player->next_scene;
}
