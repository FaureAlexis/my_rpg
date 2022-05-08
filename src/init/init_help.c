/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_help
*/

#include "rpg.h"

static int set_help_pos(help_t *help, sfFont *gravity)
{
    if (!help)
        return EPITECH_ERROR;
    sfText_setPosition(help->up, HELP_UP);
    sfText_setPosition(help->down, HELP_DOWN);
    sfText_setPosition(help->right, HELP_RIGHT);
    sfText_setPosition(help->left, HELP_LEFT);
    sfText_setPosition(help->inventory, HELP_INVENTORY);
    sfText_setPosition(help->attack, HELP_ATTACK);
    return init_help_keys(help, gravity);
}

static int set_help_text(help_t *help, sfFont *gravity)
{
    if (!help)
        return EPITECH_ERROR;
    sfText_setCharacterSize(help->up, 50);
    sfText_setCharacterSize(help->down, 50);
    sfText_setCharacterSize(help->right, 50);
    sfText_setCharacterSize(help->left, 50);
    sfText_setCharacterSize(help->inventory, 50);
    sfText_setCharacterSize(help->attack, 50);
    sfText_setString(help->up, "Up : ");
    sfText_setString(help->down, "Down : ");
    sfText_setString(help->right, "Right : ");
    sfText_setString(help->left, "Left : ");
    sfText_setString(help->inventory, "Inventory : ");
    sfText_setString(help->attack, "Attack : ");
    return set_help_pos(help, gravity);
}

static int init_help_text(help_t *help, sfFont *gravity)
{
    if (!help || !gravity)
        return EPITECH_ERROR;
    help->up = sfText_create();
    help->down = sfText_create();
    help->left = sfText_create();
    help->right = sfText_create();
    help->inventory = sfText_create();
    help->attack = sfText_create();
    sfText_setFont(help->up, gravity);
    sfText_setFont(help->down, gravity);
    sfText_setFont(help->left, gravity);
    sfText_setFont(help->right, gravity);
    sfText_setFont(help->inventory, gravity);
    sfText_setFont(help->attack, gravity);
    if (!help->up || !help->down || !help->right || !help->left ||
    !help->inventory || !help->attack)
        return EPITECH_ERROR;
    return set_help_text(help, gravity);
}

int init_help(main_game_t *game)
{
    sfFont *gravity = sfFont_createFromFile("./assets/font/fs-gravity.ttf");

    if (!game)
        return EPITECH_ERROR;
    game->help = malloc(sizeof(help_t));
    game->help->h_touch = malloc(sizeof(help_touch_t));
    if (!game->help || !game->help->h_touch)
        return EPITECH_ERROR;
    game->help->goal_text = sfText_create();
    game->help->help_text = sfText_create();
    if (!gravity || !game->help->goal_text || !game->help->help_text)
        return EPITECH_ERROR;
    sfText_setFont(game->help->goal_text, gravity);
    sfText_setFont(game->help->help_text, gravity);
    sfText_setCharacterSize(game->help->goal_text, 54);
    sfText_setCharacterSize(game->help->help_text, 34);
    sfText_setPosition(game->help->goal_text, GOAL_TXT_POS);
    sfText_setPosition(game->help->help_text, HELP_TXT_POS);
    return init_help_text(game->help, gravity);
}
