/*
** EPITECH PROJECT, 2022
** skeleton
** File description:
** rpg
*/

#include "rpg.h"

void limit_skeleton(mobe_t *mob, player_t *player)
{
    if (sqrt(pow(player->object->position.x - mob->object->position.x,
    2) + pow(player->object->position.y - mob->object->position.y, 2)) < 10)
        mob->object->rect.top += 64;
    if (mob->object->rect.left >= 336 && mob->object->rect.top == 80 + 64) {
        mob->object->rect.left = 16;
        mob->object->rect.top -= 64;
    }
    if (mob->object->rect.left >= 368 && mob->object->rect.top == 80) {
        mob->object->rect.left = 16;
        mob->object->rect.top -= 64;
    }
}

void limit_slime(mobe_t *mob, player_t *player)
{
    if (mob->object->rect.left >= 160 && mob->object->rect.top == 64) {
        mob->object->rect.left = 0;
        mob->object->rect.top -= 32;
    }
    if (mob->object->rect.left >= 128 && mob->object->rect.top == 32) {
        mob->object->rect.left = 0;
        mob->object->rect.top -= 32;
    }
}

void attack_skeleton(mobe_t *mob, player_t *player)
{
    if (mob->attack == true) {
        limit_skeleton(mob, player);
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
    } else {
        if (mob->object->rect.left >= 368)
            mob->object->rect.left = 16;
    }
    if (mob->object->rect.top == 16)
        mob->attack = false;
}

void display_skeleton(mobe_t *tmp, main_game_t *game)
{
    if (sqrt(pow(game->player->object->position.x - tmp->object->position.x,
    2) + pow(game->player->object->position.y - tmp->object->position.y, 2))
    < 80 * 5) {
        tmp->object->rect.top = 80;
        tmp->attack = true;
    }
    tmp->my_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->my_clock->seconds = tmp->my_clock->time.microseconds / 1000000.0;
    if (tmp->my_clock->seconds >= 0.1) {
        tmp->object->rect.left += 64;
        sfClock_restart(tmp->my_clock->clock);
    }
    attack_skeleton(tmp, game->player);
    sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
    sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
    sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
}
