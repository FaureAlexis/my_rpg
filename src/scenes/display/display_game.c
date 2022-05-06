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
    display_mob(game);
    game->player->dust = anim_dust(game->player->dust, game->w);
    sfRenderWindow_drawSprite(game->w, game->player->object->sprite, NULL);
    display_obstacle(game);
    display_speobstacle(game);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->pause_b->sprite, NULL);
    if (game->inv_open == true) {
        sfSprite_setScale(game->mnu->gameplay->object->sprite, INV_SIZE);
        sfSprite_setPosition(game->mnu->gameplay->object->sprite, INV_POS);
        sfRenderWindow_drawSprite(game->w, game->mnu->gameplay->object->sprite,
        NULL);
    }
    return EXIT_SUCCESS;
}
