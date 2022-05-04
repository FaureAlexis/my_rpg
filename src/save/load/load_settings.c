/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load settings
*/

#include "rpg.h"

static void apply_settings(main_game_t *game, char *key, char *value)
{
    int value_nb = 0;
    if (!game || !key || !value)
        return;
    value_nb = my_atoi(value);
    if (value_nb < 30)
        return;
    if (my_strcmp(key, "FPS") == 0 && value_nb <= 120)
        game->settings->fps = value_nb;
    if (my_strcmp(key, "resolutionX" ) == 0 && value_nb <= 2440)
        game->settings->res_x = value_nb;
    if (my_strcmp(key, "resolutionY") == 0 && value_nb <= 1540)
        game->settings->res_y = value_nb;
}

static int parse_settings(main_game_t * game, char buffer[41])
{
    char **lines = buffer_to_array(buffer);
    char *key = NULL;
    char *value = NULL;
    if (!lines)
        return EPITECH_ERROR;
    for (int i = 0; i < 3; i += 1) {
        key = get_key(lines[i]);
        if (!key)
            break;
        value = get_value(lines[i]);
        apply_settings(game, key, value);
    }
    return EXIT_SUCCESS;
}

int load_settings(main_game_t *game)
{
    char *buffer = malloc(41);
    FILE *file = fopen(".settings.rpg", "r");
    if (!file)
        return EPITECH_ERROR;
    if (fread(buffer, 41, 1, file) == -1)
        return EPITECH_ERROR;
    buffer[41 + 1] = 0;
    if (fclose(file) == EOF)
        return EPITECH_ERROR;
    if (parse_settings(game, buffer) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
