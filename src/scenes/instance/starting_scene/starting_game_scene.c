/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

int starting_game_scene(main_game_t *game)
{
    game->player->current_scene = GAME_SCENE;
    game->menu_depth = 4;
    sfMusic_pause(game->mnu->main->theme);
    sfMusic_play(game->mnu->gameplay->theme);
    sfMusic_play(game->btn->big->play_b->sound);
    sfSprite_setScale(game->player->object->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(game->player->object->sprite,
    game->player->object->position);
    sfView_reset(game->game_view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(game->w, game->game_view);
    return 0;
}
