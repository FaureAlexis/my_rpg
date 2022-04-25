/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_main_menu
*/

#include "rpg.h"

void shape_red_clicked(main_game_t *game)
{
    game->btn->sml->right_b->sprite_pos = (sfVector2f){1250, 375};
    game->btn->sml->left_b->sprite_pos = (sfVector2f){760, 375};
    sfSprite_setPosition(game->btn->sml->right_b->sprite,
    (sfVector2f){1250, 375});
    sfRectangleShape_setPosition(game->btn->sml->right_b->shape,
    (sfVector2f){1250, 375});
    sfSprite_setPosition(game->btn->sml->left_b->sprite,
    (sfVector2f){760, 375});
    sfRectangleShape_setPosition(game->btn->sml->left_b->shape,
    (sfVector2f){760, 375});
}

void shape_green_clicked(main_game_t *game)
{
    game->btn->sml->right_b->sprite_pos = (sfVector2f){1250, 435};
    game->btn->sml->left_b->sprite_pos = (sfVector2f){760, 435};
    sfSprite_setPosition(game->btn->sml->right_b->sprite,
    (sfVector2f){1250, 435});
    sfRectangleShape_setPosition(game->btn->sml->right_b->shape,
    (sfVector2f){1250, 435});
    sfSprite_setPosition(game->btn->sml->left_b->sprite,
    (sfVector2f){760, 435});
    sfRectangleShape_setPosition(game->btn->sml->left_b->shape,
    (sfVector2f){760, 435});
}

void shape_blue_clicked(main_game_t *game)
{
    game->btn->sml->right_b->sprite_pos = (sfVector2f){1250, 495};
    game->btn->sml->left_b->sprite_pos = (sfVector2f){760, 495};
    sfSprite_setPosition(game->btn->sml->right_b->sprite,
    (sfVector2f){1250, 495});
    sfRectangleShape_setPosition(game->btn->sml->right_b->shape,
    (sfVector2f){1250, 495});
    sfSprite_setPosition(game->btn->sml->left_b->sprite,
    (sfVector2f){760, 495});
    sfRectangleShape_setPosition(game->btn->sml->left_b->shape,
    (sfVector2f){760, 495});
}

int display_skin_cus(main_game_t *g)
{
    pos_button_skin_cus(g);
    sfRenderWindow_drawSprite(g->w, g->mnu->settings->bg_object->sprite, NULL);
    sfSprite_setScale(g->mnu->skin_m->object->sprite,
    (sfVector2f){0.28, 0.28});
    sfSprite_setPosition(g->mnu->skin_m->object->sprite,
    (sfVector2f){100, -10});
    sfRenderWindow_drawSprite(g->w, g->mnu->skin_m->object->sprite, NULL);
    sfRenderWindow_drawRectangleShape(g->w, g->skin->red, NULL);
    sfRenderWindow_drawRectangleShape(g->w, g->skin->blue, NULL);
    sfRenderWindow_drawRectangleShape(g->w, g->skin->green, NULL);
    sfSprite_setPosition(g->player->object->sprite, (sfVector2f){600, 435});
    sfRenderWindow_drawSprite(g->w, g->player->object->sprite, NULL);
    sfRenderWindow_drawSprite(g->w, g->btn->big->return_b->sprite, NULL);
    sfRenderWindow_drawSprite(g->w, g->btn->big->play_b->sprite, NULL);
    sfRenderWindow_drawSprite(g->w, g->btn->mid->exit_b->sprite, NULL);
    sfRenderWindow_drawSprite(g->w, g->btn->sml->left_b->sprite, NULL);
    sfRenderWindow_drawSprite(g->w, g->btn->sml->right_b->sprite, NULL);
    return EXIT_SUCCESS;
}
