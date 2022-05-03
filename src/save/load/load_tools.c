/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_tools.c
*/

#include "rpg.h"

char *get_key(char *line)
{
    char *key = NULL;
    int idx = 0;

    if (!line)
        return NULL;
    key = malloc(my_strlen(line));
    if (!key)
        return NULL;
    while (line[idx] != '=') {
        key[idx] = line[idx];
        idx += 1;
    }
    key[idx] = 0;
    return key;
}

char *get_value(char *line)
{
    char *value = malloc(my_strlen(line));
    int idx = 0;
    int idx_line = 0;

    if (!value || !line)
        return NULL;
    while (line[idx_line] != '=')
        idx_line += 1;
    idx_line += 1;
    while (line[idx_line] != '\0') {
        value[idx] = line[idx_line];
        idx_line += 1;
        idx += 1;
    }
    value[idx] = 0;
    return value;
}

char **buffer_to_array(char *buffer)
{
    char **array = malloc(sizeof(char *) * my_strlen(buffer));
    int x = 0;

    if (!array)
        return NULL;
    for (int i = 0; buffer[i]; i += 1, x += 1) {
        array[x] = malloc(my_strlen(buffer));
        for (int j = 0; buffer[i] != '\n' && buffer[i] != 0; j += 1, i += 1) {
            array[x][j] = buffer[i];
        }
    }
    return array;
}
