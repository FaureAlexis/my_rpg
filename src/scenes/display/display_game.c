/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_main_menu
*/

#include "rpg.h"

int display_game(main_game_t *game)
{
    pos_button_game(game);
    sfRenderWindow_drawSprite(game->w, game->map->back->sprite, NULL);
    sfSprite_setPosition(game->map->map->sprite, game->map->map->position);
    sfRenderWindow_drawSprite(game->w, game->map->map->sprite, NULL);
    game->player->dust = anim_poussière(game->player->dust, game->w);
    sfRenderWindow_drawSprite(game->w, game->player->object->sprite, NULL);
    display_mobe(game);
    display_obstacle(game);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->pause_b->sprite, NULL);
    return EXIT_SUCCESS;
}
