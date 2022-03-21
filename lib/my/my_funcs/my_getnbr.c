/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** my_getnbr
*/

#include <stdbool.h>
#include "lib.h"

int char_nb(char c)
{
    if (IS_NUM(c) || c == '-' || c == '+')
        return 1;
    return 0;
}

int my_getnbr(char const *str)
{
    int sign = counter_sign(str);
    long returned_number = 0;
    int max = 2147483647;
    int min = -2147483648;

    for (int i = 0; str[i] != '\0' && char_nb(str[i]) == 1; i++) {
        if (IS_NUM(str[i - 1]) == 1 && IS_NUM(str[i]) == 0) {
            break;
        } else if (IS_NUM(str[i]) == 1) {
            returned_number = returned_number * 10 + (str[i] - '0');
        }
    }
    returned_number *= sign;
    if (returned_number > max || returned_number < min) {
        return (0);
    } else {
        return (returned_number);
    }
}
