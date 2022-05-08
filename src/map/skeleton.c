/*
** EPITECH PROJECT, 2022
** skeleton
** File description:
** rpg
*/

#include "rpg.h"

void limit_skeleton(mobe_t *mob, player_t *player)
{
    if (!mob || !player)
        return;
    if (mob->object->rect.left >= 336) {
        mob->object->rect.left = 16;
        mob->object->rect.top = 16;
    }
}

static mobe_t *dead_skeleton_animation(mobe_t *mob)
{
    if (!mob->dead) {
        mob->dead = 1;
        mob->object->rect.top = 272;
        mob->object->rect.left = 0;
    } else if (mob->dead && mob->object->rect.left >= 208) {
        mob->object->rect.top = 272;
        mob->object->rect.left = 272;
    } else {
        mob->object->rect.left += 64;
    }
    return mob;
}

void attack_skeleton(mobe_t *mob, player_t *player)
{
    if (sqrt(pow(player->object->position.x - mob->object->position.x, \
    2) + pow(player->object->position.y - mob->object->position.y, 2)) < 10)
        mob->object->rect.top += 64;
    sfSprite_setOrigin(mob->object->sprite, \
    (sfVector2f){mob->object->rect.width / 3, mob->object->rect.height / 2});
    limit_skeleton(mob, player);
    if (mob->hp > 0 && mob->attack == true) {
        mob_action_move(mob, player);
        sfRectangleShape_setPosition(mob->hitbox_shape, \
        (sfVector2f){mob->object->position.x - 30, \
        mob->object->position.y - 20});
    } else {
        if (mob->hp <= 0) {
            mob->attack = 0;
            dead_skeleton_animation(mob);
        }
    }
    if (mob->object->rect.top == 16)
        mob->attack = false;
}
