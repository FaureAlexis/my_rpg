/*
** EPITECH PROJECT, 2022
** manage_scenes
** File description:
** manage_scenes
*/

#include "rpg.h"

static const scenes_t scenes_array[] = {
    {.key = sfKeyNum0, .name = PAUSE_SCENE, .go_scene = &pause_scene},
    {.key = sfKeyNum1, .name = MENU_SCENE, .go_scene = &main_menu_scene},
    {.key = sfKeyNum2, .name = SETTINGS_SCENE, .go_scene = &settings_scene},
    {.key = sfKeyNum3, .name = HELP_SCENE, .go_scene = &help_scene},
    {.key = sfKeyNum4, .name = GAME_SCENE, .go_scene = &game_scene},
    {.key = sfKeyNum5, .name = SKIN_SCENE, .go_scene = &skin_scene},
    {.key = sfKeyNum6, .name = SAVE_SCENE, .go_scene = &save_scene},
    {.key = sfKeyNum7, .name = KEYBIND_SCENE, .go_scene = &keybind_scene},
    {.key = sfKeyNum8, .name = LOSE_SCENE, .go_scene = &lose_scene},
    {.key = sfKeyNum9, .name = WIN_SCENE, .go_scene = &win_scene},
    {.key = sfKeyUnknown, .name = UNKNOWN_SCENE, .go_scene = NULL}
};

const scenes_t *manage_scenes(sfKeyCode key, scenes_name name)
{
    for (int i = 0; scenes_array[i].key != sfKeyUnknown; i++) {
        if ((key != 0 && scenes_array[i].key == key) \
        || (name != -1 && scenes_array[i].name == name)) {
            return &scenes_array[i];
        }
    }
    return NULL;
}
