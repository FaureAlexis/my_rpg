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

    player->dust =
        add_particle_to_list(player->dust, dust, (sfVector2f){0, 20});
    map->map->position.y += 10;
    move_obstacle(map, (sfVector2f){0, 10});
    move_speobstacle(map, (sfVector2f){0, 10});
    move_mob(map, (sfVector2f){0, 10});
    sfSprite_setPosition(map->map->sprite, map->map->position);
    return EXIT_SUCCESS;
}

int move_down(map_t *map, player_t *player)
{
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){6, -10});

    player->dust =
        add_particle_to_list(player->dust, dust, (sfVector2f){0, -20});
    map->map->position.y -= 10;
    move_obstacle(map, (sfVector2f){0, -10});
    move_speobstacle(map, (sfVector2f){0, -10});
    move_mob(map, (sfVector2f){0, -10});
    sfSprite_setPosition(map->map->sprite, map->map->position);
    return EXIT_SUCCESS;
}

int move_right(map_t *map, player_t *player)
{
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){0, -10});

    player->dust =
        add_particle_to_list(player->dust, dust, (sfVector2f){-20, 0});
    map->map->position.x -= 10;
    move_obstacle(map, (sfVector2f){-10, 0});
    move_speobstacle(map, (sfVector2f){-10, 0});
    move_mob(map, (sfVector2f){-10, 0});
    sfSprite_setPosition(map->map->sprite, map->map->position);
    return EXIT_SUCCESS;
}

int move_left(map_t *map, player_t *player)
{
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){0, -10});

    player->dust =
        add_particle_to_list(player->dust, dust, (sfVector2f){20, 0});
    map->map->position.x += 10;
    move_obstacle(map, (sfVector2f){10, 0});
    move_speobstacle(map, (sfVector2f){10, 0});
    move_mob(map, (sfVector2f){10, 0});
    sfSprite_setPosition(map->map->sprite, map->map->position);
    return EXIT_SUCCESS;
}

int move_player(main_game_t *game, const movements_t *movements)
{
    if (movements->key == game->keys->up
    && game->map->map->position.y <= 597 &&
    player_obstacle_collision(game, (sfVector2f){0, 10}) == false) {
        move_up(game->map, game->player);
    }
    if (movements->key == game->keys->down
    && game->map->map->position.y >= -3393 &&
    player_obstacle_collision(game, (sfVector2f){0, -10}) == false) {
        move_down(game->map, game->player);
    }
    if (movements->key == game->keys->right
    && game->map->map->position.x >= -3088 &&
    player_obstacle_collision(game, (sfVector2f){-10, 0}) == false) {
        move_right(game->map, game->player);
    }
    if (movements->key == game->keys->left
    && game->map->map->position.x <= 912 &&
    player_obstacle_collision(game, (sfVector2f){10, 0}) == false) {
        move_left(game->map, game->player);
    }
    return EXIT_SUCCESS;
}
