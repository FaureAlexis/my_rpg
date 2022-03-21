/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** my_str_isupper
*/

#include "lib.h"

int my_upper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (IS_UPPER_CHAR(str[i]) != 1)
            return 0;
    }
    return 1;
}

int my_str_isupper(char const *str)
{
    if (str == NULL)
        return 1;
    else if (my_str_isalpha(str) == 1)
        return my_upper(str);
}
