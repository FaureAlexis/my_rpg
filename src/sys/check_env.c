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
        return 84;
    keyword = malloc(sizeof(char) * my_strlen(str) + 1);
    for (; str[i] != '='; i += 1)
        keyword[i] = str[i];
    keyword[i] = '\0';
    if (my_strcmp(keyword, "DISPLAY") != 0)
        return 84;
    return 0;
}

int check_env(char **env)
{
    if (!env)
        return 84;
    for (int i = 0; env[i] != NULL; i += 1) {
        if (check_line(env[i]) == 0)
            return 0;
    }
    return 84;
}
