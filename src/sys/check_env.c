/*
** EPITECH PROJECT, 2022
** check_env.c
** File description:
** C source file for my_rpg
*/

#include "rpg.h"

static int check_line(char * str)
{
    int i = 0;
    char *keyword = NULL;

    if (!str)
        return EPITECH_ERROR;
    keyword = malloc(sizeof(char) * my_strlen(str) + 1);
    for (; str[i] != '='; i += 1)
        keyword[i] = str[i];
    keyword[i] = '\0';
    if (my_strcmp(keyword, "DISPLAY") != 0)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int check_env(char **env)
{
    if (!env)
        return EPITECH_ERROR;
    for (int i = 0; env[i] != NULL; i += 1) {
        if (check_line(env[i]) == 0)
            return EXIT_SUCCESS;
    }
    return EPITECH_ERROR;
}
