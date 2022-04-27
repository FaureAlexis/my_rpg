/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free_button
*/

#include "rpg.h"

static void destroy_text(sfText *text)
{
    sfText_destroy(text);
}

static void destroy_help_text(main_game_t *game)
{
    destroy_text(game->help->goal_text);
    destroy_text(game->help->help_text);
}

static void destroy_settings_text(main_game_t *game)
{
    destroy_text(game->settings->res_text);
    destroy_text(game->settings->fps_text);
}

void destroy_all_texts(main_game_t *game)
{
    destroy_settings_text(game);
}