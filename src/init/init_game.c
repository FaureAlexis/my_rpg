/*
** EPITECH PROJECT, 2022
** init_game
** File description:
** init_game
*/

#include "rpg.h"

int init_all(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    if (create_menus(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_all_buttons(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_volume(&game->vol) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_settings(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_help(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_skin_custom(&game->skin) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

main_game_t *init_game(void)
{
    main_game_t *game = malloc(sizeof(main_game_t));

    if (!game)
        return NULL;
    game->map = init_map();
    if (!game->map)
        return NULL;
    game->btn = malloc(sizeof(btn_t));
    game->mnu = malloc(sizeof(mnu_t));
    game->vol = malloc(sizeof(vol_t));
    if (!game->btn || !game->mnu || !game->vol)
        return NULL;
    game->btn->big = malloc(sizeof(big_btn_t));
    game->btn->mid = malloc(sizeof(mid_btn_t));
    game->btn->sml = malloc(sizeof(sml_btn_t));
    if (!game->btn->big || !game->btn->mid || !game->btn->sml)
        return NULL;
    game->view_zoom = 1;
    game->view_pos = (sfVector2f){960, 600};
    game->player = init_player();
    return game;
}
