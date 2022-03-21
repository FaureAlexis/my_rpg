/*
** EPITECH PROJECT, 2021
** counter_sign
** File description:
** counter_sign
*/

#include "lib.h"

int counter_sign(char const *str)
{
    int counter = 0;

    for (int i = 0; IS_NUM(str[i]) == 0; i++) {
        if (str[i] == '-')
            counter += 1;
    }
    if (counter % 2 == 1)
        return -1;
    return 1;
}
