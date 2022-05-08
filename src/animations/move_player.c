/*
** EPITECH PROJECT, 2022
** env_mouve
** File description:
** env_mouve
*/

#include "rpg.h"

int move_up(map_t *map, player_t *player)
{
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){6, 10});

    player->dust = add_particle_to_list(player->dust, dust,
    (sfVector2f){0, 20});
    map->map->position.y += 10;
    move_obstacle(map, MV_UP);
    move_speobstacle(map, MV_UP);
    move_mob(map, MV_UP);
    sfSprite_setPosition(map->map->sprite, map->map->position);
    return EXIT_SUCCESS;
}

int move_down(map_t *map, player_t *player)
{
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){6, -10});

    player->dust = add_particle_to_list(player->dust, dust,
    (sfVector2f){0, -20});
    map->map->position.y -= 10;
    move_obstacle(map, MV_DOWN);
    move_speobstacle(map, MV_DOWN);
    move_mob(map, MV_DOWN);
    sfSprite_setPosition(map->map->sprite, map->map->position);
    return EXIT_SUCCESS;
}

int move_right(map_t *map, player_t *player)
{
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){0, -10});

    player->dust = add_particle_to_list(player->dust, dust,
    (sfVector2f){-20, 0});
    map->map->position.x -= 10;
    move_obstacle(map, MV_RIGHT);
    move_speobstacle(map, MV_RIGHT);
    move_mob(map, MV_RIGHT);
    sfSprite_setPosition(map->map->sprite, map->map->position);
    return EXIT_SUCCESS;
}

int move_left(map_t *map, player_t *player)
{
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){0, -10});

    player->dust = add_particle_to_list(player->dust, dust,
    (sfVector2f){20, 0});
    map->map->position.x += 10;
    move_obstacle(map, MV_LEFT);
    move_speobstacle(map, MV_LEFT);
    move_mob(map, MV_LEFT);
    sfSprite_setPosition(map->map->sprite, map->map->position);
    return EXIT_SUCCESS;
}

int move_player(main_game_t *game, const movements_t *movements)
{
    if (movements->key == game->keys->up && game->map->map->position.y <=
    Y_MAX && player_obstacle_collision(game, (sfVector2f){0, 10}) == false) {
        move_up(game->map, game->player);
    }
    if (movements->key == game->keys->down && game->map->map->position.y >=
    Y_MIN && player_obstacle_collision(game, (sfVector2f){0, -10}) == false) {
        move_down(game->map, game->player);
    }
    if (movements->key == game->keys->right && game->map->map->position.x >=
    X_MIN && player_obstacle_collision(game, (sfVector2f){-10, 0}) == false) {
        move_right(game->map, game->player);
    }
    if (movements->key == game->keys->left && game->map->map->position.x <=
    X_MAX && player_obstacle_collision(game, (sfVector2f){10, 0}) == false) {
        move_left(game->map, game->player);
    }
    return EXIT_SUCCESS;
}
