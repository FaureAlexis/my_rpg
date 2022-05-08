/*
** EPITECH PROJECT, 2022
** slime
** File description:
** slime
*/

#include "rpg.h"

void mob_action_move(mobe_t *mob, player_t *player)
{
    float x = (player->object->position.x -
    mob->object->position.x) / (sqrt(pow(player->object->position.x -
    mob->object->position.x, 2) + pow(player->object->position.y -
    mob->object->position.y, 2)));
    float y = (player->object->position.y -
    mob->object->position.y) / (sqrt(pow(player->object->position.x -
    mob->object->position.x, 2) + pow(player->object->position.y -
    mob->object->position.y, 2)));
    mob->object->position.x += x;
    mob->object->position.y += y;
    mob->object->scale = (sfVector2f){4 * (x / sqrt(pow(x, 2))), 4};
    sfSprite_setScale(mob->object->sprite, mob->object->scale);
    mob->life_str = my_int_to_str(mob->hp);
    sfText_setString(mob->life_txt, mob->life_str);
    sfText_setPosition(mob->life_txt, (sfVector2f){mob->object->position.x
    - 50, mob->object->position.y - 30});
}

static void limit_slime(mobe_t *mob, player_t *player)
{
    if (!mob || !player)
        return;
    if (mob->object->rect.left >= 192 && mob->object->rect.top == 64) {
        mob->object->rect.left = 0;
        mob->object->rect.top = 0;
    }
    if (mob->object->rect.left >= 128 && mob->object->rect.top == 32) {
        mob->object->rect.left = 0;
        mob->object->rect.top = 0;
    }
    if (mob->object->rect.left >= 96 && mob->object->rect.top == 0) {
        mob->object->rect.left = 0;
    }
}

static mobe_t *dead_slime_animation(mobe_t *mob)
{
    if (!mob->dead) {
        mob->dead = 1;
        mob->object->rect.top = 128;
        mob->object->rect.left = 0;
    } else if (mob->dead && mob->object->rect.left >= 96) {
        mob->object->rect.top = 128;
        mob->object->rect.left = 128;
    } else {
        mob->object->rect.left += 32;
    }
    return mob;
}

void attack_slime(mobe_t *mob, player_t *player)
{
    if (sqrt(pow(player->object->position.x - mob->object->position.x,
    2) + pow(player->object->position.y - mob->object->position.y, 2)) < 10) {
        player_lose_health(player, 1);
    }
    limit_slime(mob, player);
    if (mob->hp > 0 && mob->attack == true) {
        mob_action_move(mob, player);
        sfRectangleShape_setPosition(mob->hitbox_shape,
        (sfVector2f){mob->object->position.x - 30,
        mob->object->position.y - 20});
    } else {
        if (mob->hp <= 0) {
            mob->attack = 0;
            mob = dead_slime_animation(mob);
        }
    }
    if (mob->object->rect.top >= 0)
        mob->attack = false;
}
