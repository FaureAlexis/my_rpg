/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** rpg
*/

#include "rpg.h"

static int launch_win(main_game_t *game)
{
    game->w = init_window();
    if (game->w == NULL)
        return EPITECH_ERROR;
    game->game_view = init_view(game->w, VIEW_SIZE);
    game->basic_view = init_view(game->w, VIEW_SIZE);
    if (game->basic_view == NULL || game->game_view == NULL)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int rpg(void)
{
    main_game_t *game = init_game();
    scenes_name change_scene = MENU_SCENE;
    const scenes_t *scene = NULL;

    if (game == NULL)
        return EPITECH_ERROR;
    if (init_all(game) == EPITECH_ERROR || launch_win(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    change_volume(game);
    sfMusic_play(game->mnu->main->theme);
    while (change_scene != -1 && change_scene != EPITECH_ERROR) {
        scene = manage_scenes(0, change_scene);
        if (scene)
            change_scene = scene->go_scene(game);
    }
    if (save_settings(game) == EPITECH_ERROR
    || free_game_struct(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (change_scene == EPITECH_ERROR)
        return change_scene;
    return EXIT_SUCCESS;
}
