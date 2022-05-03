/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free_menu
*/

#include "rpg.h"

static void destroy_music_menu(main_game_t *game)
{
    sfMusic_stop(game->mnu->main->theme);
    sfMusic_stop(game->mnu->scoreboard->theme);
    sfMusic_stop(game->mnu->gameplay->theme);
    sfMusic_stop(game->mnu->settings->theme);
    sfMusic_stop(game->mnu->help_play->theme);
    sfMusic_stop(game->mnu->pause_m->theme);
    sfMusic_stop(game->mnu->skin_m->theme);
    sfMusic_stop(game->mnu->save_m->theme);
    sfMusic_stop(game->mnu->keybind_m->theme);
    sfMusic_destroy(game->mnu->main->theme);
    sfMusic_destroy(game->mnu->scoreboard->theme);
    sfMusic_destroy(game->mnu->gameplay->theme);
    sfMusic_destroy(game->mnu->settings->theme);
    sfMusic_destroy(game->mnu->help_play->theme);
    sfMusic_destroy(game->mnu->pause_m->theme);
    sfMusic_destroy(game->mnu->skin_m->theme);
    sfMusic_destroy(game->mnu->save_m->theme);
    sfMusic_destroy(game->mnu->keybind_m->theme);
}

static void destroy_menu(menu_t *menu)
{
    sfSprite_destroy(menu->object->sprite);
    sfTexture_destroy(menu->object->texture);
    sfSprite_destroy(menu->bg_object->sprite);
    sfTexture_destroy(menu->bg_object->texture);
}

void destroy_all_menu(main_game_t *game)
{
    destroy_music_menu(game);
    destroy_menu(game->mnu->main);
    destroy_menu(game->mnu->scoreboard);
    destroy_menu(game->mnu->gameplay);
    destroy_menu(game->mnu->settings);
    destroy_menu(game->mnu->help_play);
    destroy_menu(game->mnu->pause_m);
    destroy_menu(game->mnu->skin_m);
}
