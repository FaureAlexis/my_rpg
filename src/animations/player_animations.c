/*
** EPITECH PROJECT, 2022
** player_animations
** File description:
** player_animations
*/

#include "rpg.h"

int set_player_movements(main_game_t *game, player_t *player, sfEvent *event)
{
    movements_t movements_array[] = {
        {.key = game->keys->up, .height_ss = 48, .flip = 0},
        {.key = game->keys->left, .height_ss = 48, .flip = -4},
        {.key = game->keys->down, .height_ss = 48, .flip = 0},
        {.key = game->keys->right, .height_ss = 48, .flip = 4},
        {.key = game->keys->attack, .height_ss = 96, .flip = 0},
        {.key = sfKeyUnknown, .height_ss = 0, .flip = 0}
    };
    bool pressed = detect_animations(movements_array);

    if (pressed)
        modify_animations(game, player, *event, movements_array);
    else
        player->object->rect.top = 0;
    return player->current_scene;
}

static int fight_enemy(player_t *player, mobe_t *mob)
{
    mobe_t *tmp = NULL;
    sfVector2f player_pos;
    sfVector2f mob_pos;
    int offset = 0;

    if (!player || !mob)
        return EPITECH_ERROR;
    tmp = mob;
    player_pos = sfSprite_getPosition(player->object->sprite);
    while (tmp) {
        if (tmp->hp > 0) {
            mob_pos = sfSprite_getPosition(tmp->object->sprite);
            offset = sqrt(pow(player_pos.x - mob_pos.x, 2)
            + pow(player_pos.y - mob_pos.y, 2));
            if (offset <= 80)
                tmp->hp -= player->attack;
        }
        tmp = tmp->next;
    }
    return EXIT_SUCCESS;
}

static int player_attack_animations(player_t *player, mobe_t *mob)
{
    if (!player || !mob)
        return EPITECH_ERROR;
    player->object->rect.top = 96;
    if (player->object->rect.left >= 144) {
        player->attack_action = 0;
        player->object->rect.left = 0;
        sfSprite_setTextureRect(player->object->sprite, player->object->rect);
        player->object->rect.top = 0;
    } else if (player->p_clock->seconds >= 0.15) {
        fight_enemy(player, mob);
        player->object->rect.left += 48;
        sfSprite_setTextureRect(player->object->sprite, player->object->rect);
        sfClock_restart(player->p_clock->clock);
    }
    return EXIT_SUCCESS;
}

int detect_interactions(player_t *player, mobe_t *mob)
{
    mobe_t *tmp = NULL;
    sfVector2f player_pos = sfSprite_getPosition(player->object->sprite);
    sfVector2f mob_pos;
    int offset = 0;

    if (!player || !mob)
        return EPITECH_ERROR;
    tmp = mob;
    while (tmp) {
        if (tmp->hp > 0 && tmp->type == 2) {
            mob_pos = sfSprite_getPosition(tmp->object->sprite);
            offset = sqrt(pow(player_pos.x - mob_pos.x, 2)
            + pow(player_pos.y - mob_pos.y, 2));
            if (offset <= 100)
                return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int player_animations(player_t *player, mobe_t *mob)
{
    if (!player || !mob)
        return EPITECH_ERROR;
    player->p_clock->time = sfClock_getElapsedTime(player->p_clock->clock);
    player->p_clock->seconds =
        player->p_clock->time.microseconds / SECONDS;
    if (detect_interactions(player, mob) == 1)
        player->interaction = 1;
    else
        player->interaction = 0;
    if (player->attack_action)
        return player_attack_animations(player, mob);
    if (player->p_clock->seconds >= 0.15) {
        player->object->rect.left += 48;
        sfMusic_play(player->sword);
        sfSprite_setTextureRect(player->object->sprite, player->object->rect);
        sfClock_restart(player->p_clock->clock);
    } else if (player->object->rect.left >= 240) {
        player->object->rect.left = 0;
        sfMusic_stop(player->sword);
        sfSprite_setTextureRect(player->object->sprite, player->object->rect);
    }
    return EXIT_SUCCESS;
}
