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

static const movements_t *get_animations(player_t *player, sfEvent event)
{
    for (int i = 0; movements_array[i].key != sfKeyUnknown; i++) {
        if (movements_array[i].key == event.key.code)
            return &movements_array[i];
    }
    player->object->rect.top = 0;
    return NULL;
}

int set_player_movements(main_game_t *game, player_t *player, sfEvent event)
{
    const movements_t *movements = NULL;

    if (event.type != sfEvtKeyPressed) {
        player->object->rect.top = 0;
        return player->current_scene;
    }
    movements = get_animations(player, event);
    if (!movements)
        return player->current_scene;
    if (movements->flip != 0)
        player->object->scale.x = movements->flip;
    if (movements->height_ss == 96 && !player->attack_action) {
        player->attack_action = 1;
        player->object->rect.left = 0;
    }
    player->hitbox = sfRectangleShape_getGlobalBounds(player->hitbox_shape);
    move_player(game, movements);
    player->object->rect.top = movements->height_ss;
    sfSprite_setScale(player->object->sprite, player->object->scale);
    return player->current_scene;
}

static int fight_enemy(player_t *player, mobe_t *mob)
{
    mobe_t *tmp = NULL;
    sfVector2f player_pos = sfSprite_getPosition(player->object->sprite);
    sfVector2f mob_pos;
    int offset = 0;

    if (!player || !mob)
        return 84;
    tmp = mob;
    while (tmp) {
        if (tmp->hp > 0) {
            mob_pos = sfSprite_getPosition(tmp->object->sprite);
            offset = sqrt(pow(player_pos.x - mob_pos.x, 2)
            + pow(player_pos.y - mob_pos.y, 2));
            if (offset <= 80)
                tmp->hp -= player->attack;
        }
        tmp = tmp->next;
    }
    return 0;
}

static int player_attack_animations(player_t *player, mobe_t *mob)
{
    if (!player || !mob)
        return 84;
    player->object->rect.top = 96;
    if (player->object->rect.left >= 144) {
        player->attack_action = 0;
        player->object->rect.left = 0;
        sfSprite_setTextureRect(player->object->sprite, player->object->rect);
        player->object->rect.top = 0;
    } else if (player->p_clock->seconds >= 0.15) {
        fight_enemy(player, mob);
        player->object->rect.left += 48;
        sfSprite_setTextureRect(player->object->sprite, player->object->rect);
        sfClock_restart(player->p_clock->clock);
    }
    return 0;
}

int player_animations(player_t *player, mobe_t *mob)
{
    if (!player || !mob)
        return 84;
    player->p_clock->time = sfClock_getElapsedTime(player->p_clock->clock);
    player->p_clock->seconds =
        player->p_clock->time.microseconds / 1000000.0;
    if (player->attack_action)
        return player_attack_animations(player, mob);
    if (player->p_clock->seconds >= 0.15) {
        player->object->rect.left += 48;
        sfMusic_play(player->sword);
        sfSprite_setTextureRect(player->object->sprite, player->object->rect);
        sfClock_restart(player->p_clock->clock);
    } else if (player->object->rect.left >= 240) {
        player->object->rect.left = 0;
        sfMusic_stop(player->sword);
        sfSprite_setTextureRect(player->object->sprite, player->object->rect);
    }
    return 0;
}
