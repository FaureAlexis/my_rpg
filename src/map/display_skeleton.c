/*
** EPITECH PROJECT, 2022
** display_skeleton
** File description:
** rpg
*/

#include "rpg.h"

static void skeleton_attack_animation(mobe_t *tmp, main_game_t *game)
{
    tmp->attack_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->attack_clock->seconds = tmp->my_clock->time.microseconds / SECONDS;
    if ((tmp->attack && tmp->attack_clock->seconds >= CLOCK_LIMIT_ATK)
        || (!tmp->attack && tmp->attack_clock->seconds >= 0.1)) {
        attack_skeleton(tmp, game->player);
        sfClock_restart(tmp->attack_clock->clock);
    }
}

static void dead_skeleton_animation(mobe_t *tmp)
{
    tmp->my_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->my_clock->seconds = tmp->my_clock->time.microseconds / SECONDS;
    if ((tmp->dead && tmp->object->rect.left != 272
        && tmp->my_clock->seconds >= 0.1)
        || (!tmp->dead && tmp->my_clock->seconds >= 0.1)) {
        tmp->object->rect.left += 64;
        sfClock_restart(tmp->my_clock->clock);
    }
}

void display_skeleton(mobe_t *tmp, main_game_t *game)
{
    if (!tmp->dead && sqrt(pow(game->player->object->position.x -
    tmp->object->position.x, 2) + pow(game->player->object->position.y -
    tmp->object->position.y, 2)) < 80 * 5) {
        tmp->object->rect.top = 80;
        tmp->attack = true;
    }
    skeleton_attack_animation(tmp, game);
    dead_skeleton_animation(tmp);
    sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
    sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
    sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
}
