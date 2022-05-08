/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** check_ressources
*/

#include "rpg.h"

static bool error_ressources(void)
{
    if (open(BUTTON_SS, O_RDONLY) == -1
        || open(MENU_BG, O_RDONLY) == -1
        || open(DEATH_MENU, O_RDONLY) == -1
        || open(SETTINGS_BG, O_RDONLY) == -1
        || open(SETTINGS_SS, O_RDONLY) == -1
        || open(KEYBINDING_SS, O_RDONLY) == -1
        || open(SKIN_CUS_SS, O_RDONLY) == -1
        || open(PLAYER_SS, O_RDONLY) == -1
        || open(WIN_MENU, O_RDONLY) == -1
        || open(TEXT_FONT, O_RDONLY) == -1)
        return true;
    return false;
}

static bool error_ressources2(void)
{
    if (open(INV_SS, O_RDONLY) == -1
        || open(BUTTON_SOUND, O_RDONLY) == -1
        || open(WALK_SOUND, O_RDONLY) == -1
        || open(DEATH_SOUND, O_RDONLY) == -1
        || open(SWORD_USING_SOUND, O_RDONLY) == -1
        || open(GAME_THEME, O_RDONLY) == -1
        || open(MAIN_THEME, O_RDONLY) == -1
        || open(BOSS_THEME, O_RDONLY) == -1
        || open(DEATH_THEME, O_RDONLY) == -1
        || open(WIN_THEME, O_RDONLY) == -1
        || open(MAP_TXT, O_RDONLY) == -1)
        return true;
    return false;
}

int manage_errors(const int argc, char **env)
{
    if (argc != 1)
        return EPITECH_ERROR;
    if (error_ressources() == true || error_ressources2() == true) {
        my_printf("my_rpg: Cannot open file.\n");
        return EPITECH_ERROR;
    }
    if (check_env(env) == EPITECH_ERROR) {
        my_printf("my_rpg: Bad environnement.\n");
        return EPITECH_ERROR;
    }
    return EXIT_SUCCESS;
}
