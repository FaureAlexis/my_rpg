/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_slime
*/

#include "rpg.h"

static void slime_attack_animation(mobe_t *tmp, main_game_t *game)
{
    tmp->attack_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->attack_clock->seconds = tmp->my_clock->time.microseconds / SECONDS;
    if ((tmp->attack && tmp->attack_clock->seconds >= CLOCK_LIMIT_ATK)
        || (!tmp->attack && tmp->attack_clock->seconds >= 0.1)) {
        attack_slime(tmp, game->player);
        sfClock_restart(tmp->attack_clock->clock);
    }
}

static void dead_slime_animation(mobe_t *tmp)
{
    tmp->my_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->my_clock->seconds = tmp->my_clock->time.microseconds / SECONDS;
    if ((tmp->dead && tmp->object->rect.left != 128 && tmp->my_clock->seconds \
    >= 0.1) || (!tmp->dead && tmp->my_clock->seconds >= 0.1)) {
        tmp->object->rect.left += 32;
        sfClock_restart(tmp->my_clock->clock);
    }
}

void display_slime(mobe_t *tmp, main_game_t *game)
{
    if (!tmp->dead && sqrt(pow(game->player->object->position.x -
    tmp->object->position.x, 2) + pow(game->player->object->position.y -
    tmp->object->position.y, 2)) < 80 * 5) {
        tmp->object->rect.top = 64;
        tmp->attack = true;
    }
    slime_attack_animation(tmp, game);
    dead_slime_animation(tmp);
    sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
    sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
    sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
}
