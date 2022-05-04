/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_main_menu
*/

#include "rpg.h"

int display_save(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    pos_button_save(game);
    sfRenderWindow_drawSprite(game->w, game->mnu->save_m->object->sprite,
    NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->load_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w,
    game->btn->big->newsave_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->return_b->sprite, NULL);
    return EXIT_SUCCESS;
}
