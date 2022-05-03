/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_settings
*/

#include "rpg.h"

static int set_text_settings(main_game_t *game, sfFont *gravity)
{
    if (!game || !gravity)
        return EPITECH_ERROR;
    sfText_setPosition(game->settings->res_text, (sfVector2f){1060, 450});
    sfText_setCharacterSize(game->settings->res_text, 34);
    sfText_setColor(game->settings->res_text, sfWhite);
    sfText_setFont(game->settings->res_text, gravity);
    sfText_setPosition(game->settings->fps_text, (sfVector2f){1100, 600});
    sfText_setCharacterSize(game->settings->fps_text, 58);
    sfText_setColor(game->settings->fps_text, sfWhite);
    sfText_setFont(game->settings->fps_text, gravity);
    return EXIT_SUCCESS;
}

int init_settings(main_game_t *game)
{
    sfFont *gravity = NULL;

    if (!game)
        return EPITECH_ERROR;
    game->settings = malloc(sizeof(settings_t));
    if (!game->settings)
        return EPITECH_ERROR;
    game->settings->prev_is_main = true;
    if (load_settings(game) == EPITECH_ERROR) {
        game->settings->res_x = 1920;
        game->settings->res_y = 1080;
        game->settings->fps = 60;
    }
    game->settings->res_text = sfText_create();
    game->settings->fps_text = sfText_create();
    gravity = sfFont_createFromFile("./assets/font/fs-gravity.ttf");
    if (!game->settings->res_text || !game->settings->fps_text || !gravity)
        return EPITECH_ERROR;
    if (set_text_settings(game, gravity) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
