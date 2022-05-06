/*
** EPITECH PROJECT, 2022
** mode
** File description:
** rpg
*/

#include "rpg.h"

void display_mob(main_game_t *game)
{
    mobe_t *tmp = game->map->mobe;

    while (tmp) {
        if (tmp->type == 0)
            display_slime(tmp, game);
        if (tmp->type == 1)
            display_skeleton(tmp, game);
        if (tmp->type == 10)
            display_hasbulla(tmp, game);
        tmp = tmp->next;
    }
}
