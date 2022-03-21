/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** my_str_isprintable
*/

#include "lib.h"

int my_str_isprintable(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (IS_PRINTABLE(str[i]) != 1)
            return 0;
    }
    return 1;
}
