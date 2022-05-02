/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** save file
*/

#include "rpg.h"

int free_settings(char *fps, char *x, char *y)
{
    if (!fps || !x || !y)
        return EPITECH_ERROR;
    free(fps);
    free(x);
    free(y);
}

int write_data(char *key, char *value, FILE *file)
{
    size_t block = 1;

    if (fwrite(key, my_strlen(key), block, file) != block)
        return EPITECH_ERROR;
    if (fwrite("=", 1, block, file) != block)
        return EPITECH_ERROR;
    if (fwrite(value, my_strlen(value), block, file) != block)
        return EPITECH_ERROR;
    if (fwrite("\n", 1, block, file) != block)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int write_settings(FILE *file, char *fps, char *x, char *y)
{
    if (!file || !fps || !x || !y)
        return EPITECH_ERROR;
    if (write_data("FPS", fps, file) == 84)
        return EPITECH_ERROR;
    if (write_data("resolutionX", x, file) == 84)
        return EPITECH_ERROR;
    if (write_data("resoltionY", y, file) == 84)
        return EPITECH_ERROR;
    if (free_settings(fps, x, y) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int save_settings(main_game_t *game)
{
    char *fps = NULL;
    char *res_x = NULL;
    char *res_y = NULL;
    FILE *file = NULL;

    if (!game)
        return EPITECH_ERROR;
    fps = my_int_to_str(game->settings->fps);
    res_x = my_int_to_str(game->settings->res_x);
    res_y = my_int_to_str(game->settings->res_y);
    file = open_save(".settings.rpg");
    if (fps == NULL || res_x == NULL || res_y == NULL || !file)
        return EPITECH_ERROR;
    if (write_settings(file, fps, res_x, res_y) == 84 || fclose(file) == EOF)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
