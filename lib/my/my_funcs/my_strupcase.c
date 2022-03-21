/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** my_strupcase
*/

#include "lib.h"

char *my_strupcase(char *str)
{
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (IS_LOWER_CHAR(str[i]) == 1)
            str[i] = str[i] - 32;
    }
    return str;
}
