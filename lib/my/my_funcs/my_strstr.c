/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** my_strstr
*/

#include "lib.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int return_nb = 0;
    int lfind = my_strlen(to_find);

    if (to_find[0] == '\0' || str == NULL)
        return NULL;
    while (str[i] != '\0') {
        if (str[i] == to_find[0] && my_strncmp(&str[i], to_find, lfind) == 0)
            return (&str[i]);
        i += 1;
    }
    return NULL;
}
