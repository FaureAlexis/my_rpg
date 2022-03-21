/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** my_strlowcase
*/

#include "lib.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (IS_LOWER_CHAR(str[i]) == 1)
            str[i] = str[i] + 32;
    }
    return str;
}
