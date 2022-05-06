/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free_player
*/

#include "rpg.h"

int free_player(player_t *player)
{
    if (!player)
        return EPITECH_ERROR;
    sfRectangleShape_destroy(player->hitbox_shape);
    sfMusic_stop(player->walk);
    sfMusic_stop(player->death);
    sfMusic_stop(player->sword);
    sfMusic_destroy(player->walk);
    sfMusic_destroy(player->death);
    sfMusic_destroy(player->sword);
    return EXIT_SUCCESS;
}
