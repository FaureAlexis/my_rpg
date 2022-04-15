/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** init_menu
*/

#include "rpg.h"

static int create_menu2(main_game_t *game)
{
    if (init_menu(&game->mnu->settings, BUTTON_SOUND, SETTINGS_SS,
    (sfIntRect){200, 200}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->help_play, BUTTON_SOUND, SETTINGS_BG,
    (sfIntRect){200, 200}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->pause_m, BUTTON_SOUND, SETTINGS_BG,
    (sfIntRect){200, 200}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int create_menus(main_game_t *game)
{
    if (init_menu(&game->mnu->main, BUTTON_SOUND, MENU_BG,
    (sfIntRect){0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->scoreboard, BUTTON_SOUND, MENU_BG,
    (sfIntRect){0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->gameplay, BUTTON_SOUND, GAME_EX,
    (sfIntRect){0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (create_menu2(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
