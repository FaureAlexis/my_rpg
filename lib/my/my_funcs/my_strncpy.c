/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** my_strncpy
*/

#include "lib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    if (src == NULL || n == 0)
        return NULL;
    for (int i = 0; i < n; i++) {
        if (n > my_strlen(src) && i >= my_strlen(src))
            dest[i] = '\0';
        else
            dest[i] = src[i];
    }
    dest[n] = '\0';
    return dest;
}
