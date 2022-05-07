/*
** EPITECH PROJECT, 2022
** mode
** File description:
** rpg
*/

#include "rpg.h"

static void limit_npc_animation(mobe_t *tmp)
{
    if (tmp->hp <= 0 && !tmp->dead) {
        tmp->dead = 1;
        tmp->object->rect.top = 48;
        tmp->object->rect.left = 0;
    }
    if (tmp->dead && tmp->object->rect.left >= 96) {
        tmp->object->rect.top = 48;
        tmp->object->rect.left = 144;
    }
}

static void dead_npc_animation(mobe_t *tmp)
{
    tmp->my_clock->time = sfClock_getElapsedTime(tmp->my_clock->clock);
    tmp->my_clock->seconds = tmp->my_clock->time.microseconds / SECONDS;
    if ((tmp->dead && tmp->object->rect.left <= 144 && tmp->my_clock->seconds
    >= 0.1) || (!tmp->dead && tmp->my_clock->seconds >= 0.1)) {
        tmp->object->rect.left += 48;
        sfClock_restart(tmp->my_clock->clock);
    }
    if (!tmp->dead && tmp->object->rect.left >= 144)
        tmp->object->rect.left = 0;
    limit_npc_animation(tmp);
}

void display_npc(mobe_t *tmp, main_game_t *game)
{
    sfSprite_setScale(tmp->object->sprite, (sfVector2f){3, 3});
    if (!tmp->dead && sqrt(pow(game->player->object->position.x -
    tmp->object->position.x, 2) + pow(game->player->object->position.y -
    tmp->object->position.y, 2)) < 80 * 3) {
        tmp->attack = true;
    } else {
        tmp->attack = false;
    }
    dead_npc_animation(tmp);
    sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
    sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
    sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
}

void display_mob(main_game_t *game)
{
    mobe_t *tmp = game->map->mobe;

    while (tmp) {
        if (tmp->type == 0)
            display_slime(tmp, game);
        if (tmp->type == 1)
            display_skeleton(tmp, game);
        if (tmp->type == 2)
            display_npc(tmp, game);
        if (tmp->type == 10)
            display_hasbulla(tmp, game);
        tmp = tmp->next;
    }
}
