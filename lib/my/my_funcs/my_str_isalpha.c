/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** my_str_isalpha
*/

#include "lib.h"

int my_str_isalpha(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (IS_LOWER_CHAR(str[i]) == 0)
            return 0;
    }
    return 1;
}
