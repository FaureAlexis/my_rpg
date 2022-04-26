/*
** EPITECH PROJECT, 2022
** init_game
** File description:
** init_game
*/

#include "rpg.h"

int init_volume(vol_t **vol)
{
    (*vol) = malloc(sizeof(vol_t));
    if (!(*vol))
        return EPITECH_ERROR;
    (*vol)->pos = (sfVector2f){575, 320};
    (*vol)->volume = 10;
    (*vol)->size = (sfVector2f){(700 / (*vol)->volume), 30};
    (*vol)->volume_rect = sfRectangleShape_create();
    if ((*vol)->volume_rect == NULL)
        return EPITECH_ERROR;
    sfRectangleShape_setFillColor((*vol)->volume_rect, sfGreen);
    sfRectangleShape_setSize((*vol)->volume_rect, (*vol)->size);
    sfRectangleShape_setPosition((*vol)->volume_rect, (*vol)->pos);
    return EXIT_SUCCESS;
}

int init_settings(main_game_t *game)
{
    game->settings = malloc(sizeof(settings_t));
    if (!game->settings)
        return EPITECH_ERROR;
    
    game->settings->res_x = 1920;
    game->settings->res_y = 1080;
    game->settings->res_text = sfText_create();
    sfText_setPosition(game->settings->res_text, (sfVector2f){940, 600});
    sfText_setCharacterSize(game->settings->res_text, 24);
    sfText_setColor(game->settings->res_text, sfWhite);
    
    game->settings->fps = 60;
    game->settings->fps_text = sfText_create();
    sfText_setPosition(game->settings->fps_text, (sfVector2f){1040, 600});
    sfText_setCharacterSize(game->settings->fps_text, 24);
    sfText_setColor(game->settings->fps_text, sfWhite);
    return EXIT_SUCCESS;
}

int init_all(main_game_t *game)
{
    if (create_menus(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_all_buttons(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_volume(&game->vol) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_settings(game) == EPITECH_ERROR)
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
    game->btn->big = malloc(sizeof(big_btn_t));
    game->btn->mid = malloc(sizeof(mid_btn_t));
    game->btn->sml = malloc(sizeof(sml_btn_t));
    game->mnu = malloc(sizeof(mnu_t));
    game->vol = malloc(sizeof(vol_t));
    if (!game->btn || !game->mnu || !game->vol)
        return NULL;
    game->w = init_window();
    game->view = init_view(game->w);
    game->view_zoom = 1;
    game->view_pos = (sfVector2f){960, 600};
    game->player = init_player();
    return game;
}
