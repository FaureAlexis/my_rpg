/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_collision
*/

#include "rpg.h"

bool obstacle_collision(main_game_t *game, sfVector2f next)
{
    obstacle_t *tmp = game->map->obstacle;
    sfFloatRect hitbox = {0, 0, 0, 0};

    while (tmp->next != NULL) {
        hitbox = tmp->hitbox;
        hitbox.left = tmp->hitbox.left + next.x;
        hitbox.top = tmp->hitbox.top + next.y;
        if (sfFloatRect_intersects(&hitbox, &game->player->hitbox, NULL))
            return (true);
        tmp = tmp->next;
    }
    return (false);
}

bool mob_collision(main_game_t *game, sfVector2f next)
{
    mobe_t *tmp = game->map->mobe;
    sfFloatRect hitbox = {0, 0, 0, 0};

    while (tmp->next != NULL) {
        hitbox = tmp->hitbox;
        hitbox.left = tmp->hitbox.left + next.x;
        hitbox.top = tmp->hitbox.top + next.y;
        if (sfFloatRect_intersects(&hitbox, &game->player->hitbox, NULL)) {
            printf("hitbox\n");
            return (true);
        }
        tmp = tmp->next;
    }
    return (false);
}
