/*
** EPITECH PROJECT, 2022
** display_hasbulla
** File description:
** hasbulla
*/

#include "rpg.h"

static void hasbulla_attack_animation(mobe_t *tmp, main_game_t *game)
{
    tmp->attack_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->attack_clock->seconds = tmp->my_clock->time.microseconds / SECONDS;
    if ((tmp->attack && tmp->attack_clock->seconds >= CLOCK_LIMIT_ATK)
        || (!tmp->attack && tmp->attack_clock->seconds >= 0.1)) {
        hasbulla_attack(tmp, game->player);
        sfClock_restart(tmp->attack_clock->clock);
    }
}

static void dead_hasbulla_animation(mobe_t *tmp)
{
    tmp->my_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->my_clock->seconds = tmp->my_clock->time.microseconds / SECONDS;
    if ((tmp->dead && tmp->object->rect.left <= 1600 && tmp->my_clock->seconds
    >= 0.1) || (!tmp->dead && tmp->my_clock->seconds >= 0.1)) {
        tmp->object->rect.left += 160;
        sfClock_restart(tmp->my_clock->clock);
    }
}

void display_hasbulla(mobe_t *mob, main_game_t *game)
{
    float rng = sqrt(pow(game->player->object->position.x -
    mob->object->position.x, 2) + pow(game->player->object->position.y -
    mob->object->position.y, 2));

    if (!mob->dead && rng < 80 * 3.5) {
        mob->object->rect.top = 106;
        mob->attack = true;
    }
    if (!mob->dead && rng < 10) {
        mob->object->rect.top = 212;
        mob->attack = true;
    }
    hasbulla_attack_animation(mob, game);
    dead_hasbulla_animation(mob);
    sfSprite_setTextureRect(mob->object->sprite, mob->object->rect);
    sfSprite_setPosition(mob->object->sprite, mob->object->position);
    sfRenderWindow_drawSprite(game->w, mob->object->sprite, NULL);
}
