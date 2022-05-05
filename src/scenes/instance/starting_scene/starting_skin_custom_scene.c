/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

int starting_skin_scene(main_game_t *game)
{
    game->player->current_scene = SKIN_SCENE;
    game->menu_depth = 3;
    sfMusic_pause(game->mnu->gameplay->theme);
    sfMusic_play(game->btn->big->play_b->sound);
    shape_red_clicked(game);
    set_rgb_shape(&game->skin);
    sfSprite_setScale(game->player->object->sprite, (sfVector2f){8, 8});
    sfView_reset(game->basic_view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(game->w, game->basic_view);
    return 0;
}
