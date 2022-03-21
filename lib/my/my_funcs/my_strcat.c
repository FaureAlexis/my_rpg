/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat
*/

#include "lib.h"

char *my_strcat(char *dest, char const *str)
{
    int end_line = my_strlen(dest);

    if (dest == NULL || str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        dest[end_line + i] = str[i];
    end_line = my_strlen(dest);
    dest[end_line] = '\0';
    return dest;
}
