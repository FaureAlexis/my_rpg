/*
** EPITECH PROJECT, 2022
** slime
** File description:
** slime
*/

#include "rpg.h"

static void limit_slime(mobe_t *mob, player_t *player)
{
    if (!mob || !player)
        return;
    if (mob->object->rect.left >= 160 && mob->object->rect.top == 64) {
        mob->object->rect.left = 0;
        mob->object->rect.top -= 32;
    }
    if (mob->object->rect.left >= 128 && mob->object->rect.top == 32) {
        mob->object->rect.left = 0;
        mob->object->rect.top -= 32;
    }
}

void attack_slime(mobe_t *mob, player_t *player)
{
    if (mob->hp > 0 && mob->attack == true) {
        limit_slime(mob, player);
        mob->object->position.x += (player->object->position.x -
        mob->object->position.x) / (sqrt(pow(player->object->position.x -
        mob->object->position.x, 2) + pow(player->object->position.y -
        mob->object->position.y, 2)));
        mob->object->position.y += (player->object->position.y -
        mob->object->position.y) / (sqrt(pow(player->object->position.x -
        mob->object->position.x, 2) + pow(player->object->position.y -
        mob->object->position.y, 2)));
        sfRectangleShape_setPosition(mob->hitbox_shape,
        (sfVector2f){mob->object->position.x - 30,
        mob->object->position.y - 20});
    } else if (mob->hp > 0 && mob->object->rect.left >= 96) {
        mob->object->rect.left = 0;
    } else {
        if (mob->hp <= 0) {
            if (!mob->dead) {
                mob->dead = 1;
                mob->attack = false;
                mob->object->rect.top = 128;
                mob->object->rect.left = 0;
            } else if (mob->dead && mob->object->rect.left >= 96) {
                mob->object->rect.top = 128;
                mob->object->rect.left = 128;
            } else {
                mob->object->rect.left += 32;
            }
        }
    }
}

void display_slime(mobe_t *tmp, main_game_t *game)
{
    if (!tmp->dead && sqrt(pow(game->player->object->position.x -
    tmp->object->position.x,
    2) + pow(game->player->object->position.y - tmp->object->position.y, 2))
    < 80 * 5) {
        tmp->object->rect.top = 64;
        tmp->attack = true;
    }
    tmp->attack_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->attack_clock->seconds = tmp->my_clock->time.microseconds / 1000000.0;
    if (tmp->attack_clock->seconds >= 0.08) {
        attack_slime(tmp, game->player);
        sfClock_restart(tmp->attack_clock->clock);
    }
    tmp->my_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->my_clock->seconds = tmp->my_clock->time.microseconds / 1000000.0;
    if ((tmp->dead && tmp->object->rect.left != 128 &&
    tmp->my_clock->seconds >= 0.1)
        || !tmp->dead && tmp->my_clock->seconds >= 0.1) {
        tmp->object->rect.left += 32;
        sfClock_restart(tmp->my_clock->clock);
    }
    sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
    sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
    sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
}
