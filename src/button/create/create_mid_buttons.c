/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_mid_buttons
*/

#include "rpg.h"

static int create_medium_buttons(main_game_t *game)
{
    char **tab = init_button_rsc2(BUTTON_SOUND, BUTTON_SS);

    if (init_button(&(game->btn->mid->main_b), INIT_BTN_POS, \
    MEDIUM, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->mid->pause_b), INIT_BTN_POS, \
    MEDIUM, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

static int create_medium_buttons2(main_game_t *game)
{
    char **tab = init_button_rsc2(BUTTON_SOUND, BUTTON_SS);

    if (init_button(&(game->btn->mid->mute_b), INIT_BTN_POS, \
    MEDIUM, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->mid->help_b), INIT_BTN_POS, \
    MEDIUM, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->mid->exit_b), INIT_BTN_POS, \
    MEDIUM, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

static int create_medium_buttons3(main_game_t *game)
{
    char **tab = init_button_rsc2(BUTTON_SOUND, BUTTON_SS);

    if (init_button(&(game->btn->mid->unmute_b), INIT_BTN_POS, \
    MEDIUM, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->mid->keybind_b), INIT_BTN_POS, \
    MEDIUM, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int create_all_medium_buttons(main_game_t *game)
{
    if (create_medium_buttons(game) == EPITECH_ERROR \
    || create_medium_buttons2(game) == EPITECH_ERROR \
    || create_medium_buttons3(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
