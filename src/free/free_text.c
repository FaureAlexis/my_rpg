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
    destroy_text(game->help->up);
    destroy_text(game->help->down);
    destroy_text(game->help->right);
    destroy_text(game->help->left);
    destroy_text(game->help->inventory);
    destroy_text(game->help->attack);
    destroy_text(game->help->h_touch->up);
    destroy_text(game->help->h_touch->down);
    destroy_text(game->help->h_touch->right);
    destroy_text(game->help->h_touch->left);
    destroy_text(game->help->h_touch->inventory);
    destroy_text(game->help->h_touch->attack);
}

static void destroy_settings_text(main_game_t *game)
{
    destroy_text(game->settings->res_text);
    destroy_text(game->settings->fps_text);
}

void destroy_all_texts(main_game_t *game)
{
    destroy_help_text(game);
    destroy_settings_text(game);
}
