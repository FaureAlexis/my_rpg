/*
** EPITECH PROJECT, 2022
** init_player
** File description:
** init_player
*/

#include "rpg.h"

static player_t *set_player_stats(player_t *player)
{
    player->life = 20;
    player->attack = 5;
    player->dust = NULL;
    player->object->position = (sfVector2f){960, 600};
    player->object->scale = (sfVector2f){4, 4};
    player->object->rect = (sfIntRect){0, 0, 48, 48};
    return player;
}
static int set_sprite(player_t *player)
{
    sfSprite_setOrigin(player->object->sprite, (sfVector2f){24, 24});
    sfSprite_setTexture(player->object->sprite, player->object->texture,
    sfTrue);
    sfSprite_setTextureRect(player->object->sprite, player->object->rect);
    sfSprite_setScale(player->object->sprite, player->object->scale);
    sfSprite_setPosition(player->object->sprite, player->object->position);
    return 0;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->object = malloc(sizeof(game_object_t));
    if (!player->object)
        return NULL;
    player = set_player_stats(player);
    player->p_clock = init_clock();
    if (!player->p_clock)
        return NULL;
    player->object->texture = sfTexture_createFromFile(PLAYER_SS, NULL);
    if (!player->object->texture)
        return NULL;
    player->object->sprite = sfSprite_create();
    if (!player->object->sprite)
        return NULL;
    set_sprite(player);
    return player;
}
