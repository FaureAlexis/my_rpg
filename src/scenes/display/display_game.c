/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_main_menu
*/

#include "rpg.h"

void add_atrific(map_t *map, main_game_t *game)
{
    particles_t *tmp = NULL;

    map->artificlock->time = sfClock_getElapsedTime(map->artificlock->clock);
    map->artificlock->seconds = map->artificlock->time.microseconds / 1000000.0;
    if (map->artificlock->seconds >= 0.1) {
        tmp = gen_artific(game->w);
        sfClock_restart(map->artificlock->clock);
    }
    map->artific = add_particle_to_list(map->artific, tmp, (sfVector2f){0, 0});
    anim_artific(map->artific, game->w);
}

int display_game(main_game_t *game)
{
    pos_button_game(game);
    sfRenderWindow_drawSprite(game->w, game->map->back->sprite, NULL);
    sfSprite_setPosition(game->map->map->sprite, game->map->map->position);
    sfRenderWindow_drawSprite(game->w, game->map->map->sprite, NULL);
    game->player->dust = anim_dust(game->player->dust, game->w);
    sfRenderWindow_drawSprite(game->w, game->player->object->sprite, NULL);
    display_mob(game);
    display_obstacle(game);
    sfRenderWindow_drawRectangleShape(game->w, game->player->hitbox_shape, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->pause_b->sprite, NULL);
    return EXIT_SUCCESS;
}
