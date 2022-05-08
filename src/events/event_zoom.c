/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_zoom
*/

#include "rpg.h"

int zoom_event(main_game_t *game)
{
    if (game->event.key.code == game->keys->zoom &&
    game->event.type == sfEvtKeyPressed && game->view_zoom >= MAX_ZOOM) {
        sfView_zoom(game->game_view, ZOOM);
        game->view_zoom -= ZOOM_OFFSET;
        return game->player->current_scene;
    }
    if (game->event.key.code == game->keys->unzoom &&
    game->event.type == sfEvtKeyPressed && game->view_zoom <= MIN_ZOOM) {
        sfView_zoom(game->game_view, UNZOOM);
        game->view_zoom += ZOOM_OFFSET;
        return game->player->current_scene;
    }
    return game->player->current_scene;
}
