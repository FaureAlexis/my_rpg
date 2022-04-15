/*
** EPITECH PROJECT, 2022
** player_animations
** File description:
** player_animations
*/

#include "rpg.h"

static const movements_t movements_array[] = {
    {.key = sfKeyUp, .height_ss = 48, .flip = 0},
    {.key = sfKeyLeft, .height_ss = 48, .flip = -4},
    {.key = sfKeyDown, .height_ss = 48, .flip = 0},
    {.key = sfKeyRight, .height_ss = 48, .flip = 4},
    {.key = sfKeyA, .height_ss = 96, .flip = 0},
    {.key = sfKeyUnknown, .height_ss = 0, .flip = 0}
};

int set_player_movements(player_t *player, sfEvent event)
{
    const movements_t *movements = NULL;
    sfKeyCode key = event.key.code;

    if (event.type != sfEvtKeyPressed) {
        player->rect.top = 0;
        return player->current_scene;
    }
    for (int i = 0; movements_array[i].key != sfKeyUnknown; i++) {
        if (movements_array[i].key == key)
            movements = &movements_array[i];
    }
    if (!movements) {
        player->rect.top = 0;
        return player->current_scene;
    }
    if (movements->flip != 0)
        player->scale.x = movements->flip;
    player->rect.top = movements->height_ss;
    sfSprite_setScale(player->sprite, player->scale);
    return player->current_scene;
}

int player_animations(player_t *player)
{
    player->p_clock->time = sfClock_getElapsedTime(player->p_clock->clock);
    player->p_clock->seconds =
        player->p_clock->time.microseconds / 1000000.0;
    if (player->p_clock->seconds >= 0.1) {
        player->rect.left += 48;
        sfSprite_setTextureRect(player->sprite, player->rect);
        sfClock_restart(player->p_clock->clock);
    } else if (player->rect.left >= 240) {
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
    return 0;
}
