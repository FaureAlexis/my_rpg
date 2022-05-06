/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_zoom
*/

#include "rpg.h"

int zoom_event(main_game_t *game)
{
    if (game->event.key.code == game->keys->zoom
    && game->event.type == sfEvtKeyPressed && game->view_zoom >= 0.5) {
        sfView_zoom(game->game_view, 0.9);
        game->view_zoom -= 0.1;
        return game->player->current_scene;
    }
    if (game->event.key.code == game->keys->unzoom
    && game->event.type == sfEvtKeyPressed && game->view_zoom <= 1.2) {
        sfView_zoom(game->game_view, 1.1);
        game->view_zoom += 0.1;
        return game->player->current_scene;
    }
    return game->player->current_scene;
}
