/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** rpg
*/

#include "rpg.h"

int rpg(int argc, const char * const *argv, char ** env)
{
    main_game_t *game = init_game();
    scenes_name change_scene = MENU_SCENE;
    const scenes_t *scene = NULL;

    if (!game || game == NULL)
        return EPITECH_ERROR;
    if (init_all(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    while (change_scene != -1 && change_scene != 84) {
        scene = manage_scenes(0, change_scene);
        if (scene)
            change_scene = scene->go_scene(game);
    }
    free_game_struct(game);
    if (change_scene == 84)
        return change_scene;
    return 0;
}
