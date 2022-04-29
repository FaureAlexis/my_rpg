/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** save file
*/

#include "rpg.h"

void free_settings(char *fps, char *x, char *y)
{
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
    if (write_data("FPS", fps, file) == 84)
        return EPITECH_ERROR;
    if (write_data("resolutionX", x, file) == 84)
        return EPITECH_ERROR;
    if (write_data("resoltionY", y, file) == 84)
        return EPITECH_ERROR;
    free_settings(fps, x, y);
    return EXIT_SUCCESS;
}

int save_settings(main_game_t *game)
{
    char *fps = my_int_to_str(game->settings->fps);
    char *res_x = my_int_to_str(game->settings->res_x);
    char *res_y = my_int_to_str(game->settings->res_y);
    FILE *file = open_save(".settings.rpg");

    if (!file)
        return EPITECH_ERROR;
    if (write_settings(file, fps, res_x, res_y) == 84 || fclose(file) == EOF)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
