/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_life_bar_player
*/

#include "rpg.h"

int init_life_bar_player(player_t *player)
{
    if (!player)
        return EPITECH_ERROR;
    player->life_bar = sfRectangleShape_create();
    if (!player->life_bar)
        return EPITECH_ERROR;
    sfRectangleShape_setSize(player->life_bar, LIFE_BAR_SIZE);
    sfRectangleShape_setPosition(player->life_bar, LIFE_BAR_POS);
    sfRectangleShape_setFillColor(player->life_bar, sfColor_fromRGB(RED));
    return EXIT_SUCCESS;
}
