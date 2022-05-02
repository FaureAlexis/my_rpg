/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_help
*/

#include "rpg.h"

static int display_help_text(main_game_t *game)
{
    if (!game || !game->help)
        return EPITECH_ERROR;
    sfText_setString(game->help->goal_text, GAME_GOAL);
    sfText_setString(game->help->help_text, GAME_HELP);
    sfRenderWindow_drawText(game->w, game->help->goal_text, NULL);
    sfRenderWindow_drawText(game->w, game->help->help_text, NULL);
    return EXIT_SUCCESS;
}

int display_help(main_game_t *game)
{
    if (!game || !game->help)
        return EPITECH_ERROR;
    pos_button_help(game);
    sfRenderWindow_drawSprite(game->w, game->mnu->help_play->bg_object->sprite,
    NULL);
    sfRenderWindow_drawSprite(game->w, game->mnu->help_play->object->sprite,
    NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->return_b->sprite,
    NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->exit_b->sprite, NULL);
    return display_help_text(game);
}
