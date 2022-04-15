/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "lib.h"
#include "rpg.h"

int len_tab(char *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '\n' && str[i + 1] != '\n') {
            result += 1;
        }
    }
    return result;
}

int get_next_array(char *tmp, int idx)
{
    while (tmp[idx] != '\n') {
        idx += 1;
    }
    idx += 1;
    return idx;
}

int my_arraylen(char *const *array)
{
    int result = 0;

    while (array[result] != NULL) {
        result += 1;
    }
    return result;
}

char ***make_tab(char *filepath)
{
    char *tmp = open_file(filepath);
    char ***result = malloc(sizeof(char **) * (len_tab(tmp) + 1));
    int idx = 0;

    for (int tab = 0; tab < len_tab(tmp); tab += 1) {
        result[tab] = my_str_to_word_array_pos(tmp, ' ', idx);
        idx = get_next_array(tmp, idx);
    }
    return result;
}
