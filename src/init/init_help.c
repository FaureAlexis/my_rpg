/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_help
*/

#include "rpg.h"

int init_help(main_game_t *game)
{
    sfFont *gravity = sfFont_createFromFile("./assets/font/fs-gravity.ttf");

    if (!game)
        return EPITECH_ERROR;
    game->help = malloc(sizeof(help_t));
    if (!game->help)
        return EPITECH_ERROR;
    game->help->goal_text = sfText_create();
    game->help->help_text = sfText_create();
    if (!gravity || !game->help->goal_text || !game->help->help_text)
        return EPITECH_ERROR;
    sfText_setFont(game->help->goal_text, gravity);
    sfText_setFont(game->help->help_text, gravity);
    sfText_setColor(game->help->goal_text, sfWhite);
    sfText_setColor(game->help->help_text, sfWhite);
    sfText_setCharacterSize(game->help->goal_text, 54);
    sfText_setCharacterSize(game->help->help_text, 34);
    sfText_setPosition(game->help->goal_text, GOAL_TXT_POS);
    sfText_setPosition(game->help->help_text, HELP_TXT_POS);
    return EXIT_SUCCESS;
}
