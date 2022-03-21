/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_strdup
*/

#include "lib.h"

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int length_src = 0;

    if (src == NULL)
        return NULL;
    length_src = my_strlen(src);
    dest = malloc(sizeof(char) * (length_src + 1));
    my_strcpy(dest, src);
    return dest;
}
