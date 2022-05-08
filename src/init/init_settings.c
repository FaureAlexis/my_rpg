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
    sfText_setPosition(game->settings->res_text, RES_TXT);
    sfText_setCharacterSize(game->settings->res_text, 34);
    sfText_setColor(game->settings->res_text, sfWhite);
    sfText_setFont(game->settings->res_text, gravity);
    sfText_setPosition(game->settings->fps_text, FPS_TXT);
    sfText_setCharacterSize(game->settings->fps_text, 58);
    sfText_setColor(game->settings->fps_text, sfWhite);
    sfText_setFont(game->settings->fps_text, gravity);
    return EXIT_SUCCESS;
}

int set_sound_effect(player_t *player)
{
    if (!player)
        return EPITECH_ERROR;
    player->walk = sfMusic_createFromFile(WALK_SOUND);
    player->death = sfMusic_createFromFile(DEATH_SOUND);
    player->sword = sfMusic_createFromFile(SWORD_USING_SOUND);
    if (player->walk == NULL || player->death == NULL || player->sword == NULL)
        return EPITECH_ERROR;
    sfMusic_setLoop(player->walk, true);
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
    if (load_settings(game) == EPITECH_ERROR) {
        game->settings->res_x = MAX_W_X;
        game->settings->res_y = MAX_W_Y;
        game->settings->fps = 60;
    }
    game->settings->res_text = sfText_create();
    game->settings->fps_text = sfText_create();
    gravity = sfFont_createFromFile(TEXT_FONT);
    if (!game->settings->res_text || !game->settings->fps_text || !gravity)
        return EPITECH_ERROR;
    if (set_text_settings(game, gravity) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
