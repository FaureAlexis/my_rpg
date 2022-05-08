/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** init_menu
*/

#include "rpg.h"

static int create_menu2(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->settings, MAIN_THEME, SETTINGS_SS, \
    INIT_RECT_MENU) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->help_play, MAIN_THEME, SETTINGS_BG, \
    INIT_RECT_MENU) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->pause_m, MAIN_THEME, SETTINGS_BG, \
    INIT_RECT_MENU) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->skin_m, MAIN_THEME, SKIN_CUS_SS, \
    INIT_RECT_MENU) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->keybind_m, MAIN_THEME, KEYBINDING_SS, \
    INIT_RECT_MENU) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int create_menus(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->main, MAIN_THEME, MENU_BG, \
    INIT_RECT_MENU2) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->gameplay, GAME_THEME, INV_SS, \
    INIT_RECT_MENU2) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->save_m, MAIN_THEME, MENU_BG, \
    INIT_RECT_MENU) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->lose_m, DEATH_THEME, DEATH_MENU, \
    INIT_RECT_MENU) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->win_m, WIN_THEME, WIN_MENU, \
    INIT_RECT_MENU) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (create_menu2(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
