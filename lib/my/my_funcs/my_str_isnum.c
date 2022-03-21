/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** my_str_isnum
*/

#include "lib.h"

int my_str_isnum(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (IS_NUM(str[i]) == 0)
            return 0;
    }
    return 1;
}
