/*
** EPITECH PROJECT, 2021
** my_str_to_oct
** File description:
** my_str_to_oct
*/

#include "lib.h"

void put_zero(char c)
{
    if (c < 8)
        my_putstr("00");
    else if (c < 32 && c > 8)
        my_putstr("0");
}

void my_put_printable_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] == 127) {
            my_putchar('\\');
            put_zero(str[i]);
            my_putnbr_base(str[i], "01234567");
        } else {
            my_putchar(str[i]);
        }
    }
}
