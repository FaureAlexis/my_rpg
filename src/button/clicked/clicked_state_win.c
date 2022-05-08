/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** clicked_state
*/

#include "rpg.h"

void clicked_state_win(main_game_t *game, sfRectangleShape *shape,
sfVector2f position)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / SECONDS;

    while (seconds < CLOCK_LIMIT) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / SECONDS;
        sfMusic_play(game->btn->big->exit_b->sound);
        display_win(game);
        sfRectangleShape_setPosition(shape, position);
        sfRenderWindow_drawRectangleShape(game->w, shape, NULL);
        sfRenderWindow_display(game->w);
    }
    sfMusic_stop(game->btn->big->exit_b->sound);
    sfClock_destroy(clock);
}
