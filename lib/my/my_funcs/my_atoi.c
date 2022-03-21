/*
** EPITECH PROJECT, 2021
** my_atoi
** File description:
** my_atoi
*/

#include "lib.h"

int my_atoi(char const *str)
{
    int sign = 1;
    int i = 0;
    long return_nb = 0;

    if (str == NULL)
        return 0;
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }
    for (; str[i] != '\0' && IS_NUM(str[i]) == 1; i++)
        return_nb = return_nb * 10 + (str[i] - '0');
    return_nb *= sign;
    if (return_nb > 2147483647 || return_nb < -2147483648)
        return 0;
    return return_nb;
}
