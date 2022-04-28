/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** clicked_state
*/

#include "rpg.h"

void clicked_state_main(main_game_t *game, sfRectangleShape *shape,
sfVector2f position)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    while (seconds < 0.2) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        sfMusic_play(game->btn->big->exit_b->sound);
        display_menu(game);
        sfRectangleShape_setPosition(shape, position);
        sfRenderWindow_drawRectangleShape(game->w, shape, NULL);
        sfRenderWindow_display(game->w);
    }
    sfMusic_stop(game->btn->big->exit_b->sound);
    sfClock_destroy(clock);
}
