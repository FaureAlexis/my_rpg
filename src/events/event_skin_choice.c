/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_skin_choice
*/

#include "rpg.h"

static int event_red_clicked(main_game_t *game, sfVector2i mouse_pos)
{
    if (shape_is_clicked(game->w, game->skin->red, mouse_pos) == true) {
        shape_red_clicked(game);
        game->skin->click_red = true;
        game->skin->click_green = false;
        game->skin->click_blue = false;
        return game->player->current_scene;
    }
    return -2;
}

int event_skin_choice(main_game_t *game, sfVector2i mouse_pos)
{
    if (event_red_clicked(game, mouse_pos) != -2)
        return game->player->current_scene;
    if (shape_is_clicked(game->w, game->skin->green, mouse_pos) == true) {
        shape_green_clicked(game);
        game->skin->click_red = false;
        game->skin->click_green = true;
        game->skin->click_blue = false;
        return game->player->current_scene;
    }
    if (shape_is_clicked(game->w, game->skin->blue, mouse_pos) == true) {
        shape_blue_clicked(game);
        game->skin->click_red = false;
        game->skin->click_green = false;
        game->skin->click_blue = true;
        return game->player->current_scene;
    }
    return game->player->current_scene;
}
