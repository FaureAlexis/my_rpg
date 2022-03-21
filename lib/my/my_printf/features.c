/*
** EPITECH PROJECT, 2021
** features
** File description:
** features
*/

#include "lib.h"

int nblen(unsigned long nb)
{
    int i = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb /= 10;
        i += 1;
    }
    return i;
}

void manage_hashtag_flags(char flags)
{
    if (flags == 'o') {
        my_putstr("0");
    } else if (flags == 'x' || flags == 'p') {
        my_putstr("0x");
    } else {
        my_putstr("0X");
    }
}
