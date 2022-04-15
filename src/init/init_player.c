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

    if (!player)
        return NULL;
    player->life = 20;
    player->attack = 5;
    player->position = (sfVector2f){500, 500};
    player->scale = (sfVector2f){4, 4};
    player->rect = (sfIntRect){0, 0, 48, 48};
    player->p_clock = init_clock();
    player->texture = sfTexture_createFromFile(PLAYER_SS, NULL);
    if (!player->texture)
        return NULL;
    player->sprite = sfSprite_create();
    if (!player->sprite)
        return NULL;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setScale(player->sprite, player->scale);
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setOrigin(player->sprite, (sfVector2f){24, 24});
    return player;
}
