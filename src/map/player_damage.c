/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_damage
*/

#include "rpg.h"

int player_lose_health(player_t *player, int amount)
{
    char *life_str = NULL;
    sfVector2f size = sfRectangleShape_getSize(player->life_bar);
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / SECONDS;

    if (seconds < 0.001 && player->life > 0) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / SECONDS;
        sfMusic_play(player->sword);
        player->life -= amount;
        sfRectangleShape_setSize(player->life_bar,
        (sfVector2f){size.x - 3, size.y});
    }
    if (player->life < 0)
        player->life = 0;
    life_str = my_int_to_str(player->life);
    sfText_setString(player->life_txt, life_str);
    sfMusic_stop(player->sword);
    sfClock_destroy(clock);
    return EXIT_SUCCESS;
}
