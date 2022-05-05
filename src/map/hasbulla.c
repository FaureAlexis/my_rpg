/*
** EPITECH PROJECT, 2022
** hasbulla
** File description:
** hasbulla
*/

#include "rpg.h"

void limit_hasbulla(mobe_t *mob, player_t *player)
{
    if (mob->object->rect.left >= 1920) {
        mob->object->rect.left = 30;
    }
}

void display_hasbulla(mobe_t *mob, main_game_t *game)
{
    limit_hasbulla(mob, game->player);
    mob->attack_clock->time = sfClock_getElapsedTime(mob->my_clock->clock);
    mob->attack_clock->seconds = mob->my_clock->time.microseconds / 1000000.0;
    mob->my_clock->time = sfClock_getElapsedTime(mob->my_clock->clock);
    mob->my_clock->seconds = mob->my_clock->time.microseconds / 1000000.0;
    if (mob->attack == true && mob->attack_clock->seconds >= 0.08) {
        mob_action_move(mob, game->player);
        sfRectangleShape_setPosition(mob->hitbox_shape,
        (sfVector2f){mob->object->position.x - 30,
        mob->object->position.y - 20});
        sfClock_restart(mob->attack_clock->clock);
    }
    if (mob->my_clock->seconds >= 0.1){
        mob->object->rect.left += 105;
        sfClock_restart(mob->my_clock->clock);
    }
    sfSprite_setTextureRect(mob->object->sprite, mob->object->rect);
    sfSprite_setPosition(mob->object->sprite, mob->object->position);
    sfRenderWindow_drawSprite(game->w, mob->object->sprite, NULL);
}
