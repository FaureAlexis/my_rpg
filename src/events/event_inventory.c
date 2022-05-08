/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_inventory
*/

#include "rpg.h"

int trigger_inventory(main_game_t *game)
{
    if (game->event.key.code == game->keys->inventory &&
    game->event.type == sfEvtKeyPressed && game->inv_open == false) {
        game->inv_open = true;
        return game->player->current_scene;
    }
    if (game->event.key.code == game->keys->inventory &&
    game->event.type == sfEvtKeyPressed && game->inv_open == true) {
        game->inv_open = false;
        return game->player->current_scene;
    }
    return game->player->current_scene;
}
