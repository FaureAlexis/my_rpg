/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** play_button
*/

#include "rpg.h"

char **init_button_rsc2(char *sound, char *texture)
{
    char **tab = malloc(sizeof(char *) * 2);

    tab[0] = sound;
    tab[1] = texture;
    return tab;
}

static int create_big_buttons(main_game_t *game)
{
    char **tab = init_button_rsc2(BUTTON_SOUND, BUTTON_SS);

    if (init_button(&(game->btn->big->score_b), (sfVector2f){750, 700},
    LARGE, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->big->resume_b), (sfVector2f){750, 700},
    LARGE, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->big->help_b), (sfVector2f){750, 700},
    LARGE, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->big->settings_b), (sfVector2f){750, 700},
    LARGE, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->big->return_b), (sfVector2f){750, 700},
    LARGE, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

static int create_big_buttons2(main_game_t *game)
{
    char **tab = init_button_rsc2(BUTTON_SOUND, BUTTON_SS);

    if (init_button(&(game->btn->big->play_b), (sfVector2f){750, 700},
    LARGE, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->big->exit_b), (sfVector2f){750, 700},
    LARGE, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->big->newsave_b), (sfVector2f){750, 700},
    LARGE, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->big->load_b), (sfVector2f){750, 700},
    LARGE, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int create_all_big_buttons(main_game_t *game)
{
    if (create_big_buttons(game) == EPITECH_ERROR
    || create_big_buttons2(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
