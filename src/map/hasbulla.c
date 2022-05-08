/*
** EPITECH PROJECT, 2022
** hasbulla
** File description:
** hasbulla
*/

#include "rpg.h"

static void limit_hasbulla(mobe_t *mob, player_t *player)
{
    if (!mob || !player)
        return;
    if ((mob->object->rect.left >= 1760 && mob->object->rect.top != 106 && \
    mob->object->rect.top != 318) || mob->object->rect.left >= 2720) {
        mob->object->rect.left = 0;
        mob->object->rect.top = 0;
    }
}

static mobe_t *dead_hasbulla_animation(mobe_t *mob)
{
    if (!mob->dead) {
        mob->dead = 1;
        mob->object->rect.top = 318;
        mob->object->rect.left = 0;
    } else if (mob->dead && mob->object->rect.left >= 1600) {
        mob->object->rect.top = 318;
        mob->object->rect.left = 1760;
    } else {
        mob->object->rect.left += 160;
    }
    return mob;
}

void hasbulla_attack(mobe_t *mob, player_t *player)
{
    limit_hasbulla(mob, player);
    if (mob->hp > 0 && mob->attack == true) {
        mob_action_move(mob, player);
        sfRectangleShape_setPosition(mob->hitbox_shape, \
        (sfVector2f){mob->object->position.x - 30,
        mob->object->position.y - 20});
    } else {
        if (mob->hp <= 0) {
            mob->attack = 0;
            mob = dead_hasbulla_animation(mob);
        }
    }
    if (mob->object->rect.top >= 0)
        mob->attack = false;
}
