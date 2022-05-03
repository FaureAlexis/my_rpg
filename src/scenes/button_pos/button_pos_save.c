/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

static void pos_fullscreen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){750, 700});
    sfRectangleShape_setPosition(game->btn->big->newsave_b->shape,
    (sfVector2f){540, 450});
    sfRectangleShape_setPosition(game->btn->big->load_b->shape,
    (sfVector2f){960, 450});
}

static void pos_screen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    (sfVector2f){562.5, 525});
    sfRectangleShape_setPosition(game->btn->big->newsave_b->shape,
    (sfVector2f){405, 337.5});
    sfRectangleShape_setPosition(game->btn->big->load_b->shape,
    (sfVector2f){720, 337.5});
}

void pos_button_save(main_game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->w);

    sfSprite_setPosition(game->btn->big->return_b->sprite,
    (sfVector2f){750, 700});
    sfSprite_setPosition(game->btn->big->newsave_b->sprite,
    (sfVector2f){540, 450});
    sfSprite_setPosition(game->btn->big->load_b->sprite,
    (sfVector2f){960, 450});
    if (size.x == 1920)
        pos_fullscreen(game);
    else
        pos_screen(game);
}
