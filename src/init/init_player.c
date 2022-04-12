/*
** EPITECH PROJECT, 2022
** init_player
** File description:
** init_player
*/

#include "rpg.h"

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->life = 20;
    player->attack = 5;
    return player;
}
