/*
** EPITECH PROJECT, 2021
** my_putnbr_base
** File description:
** my_putnbr_base
*/

#include "lib.h"

unsigned long put_base(unsigned long nbr, char const *base)
{
    int op = 0;
    int power = 0;

    for (; nbr > my_compute_power_rec(my_strlen(base), power); power++);
    power -= 1;
    while (power != 0) {
        op = nbr / my_compute_power_rec(my_strlen(base), power);
        my_putchar(base[op]);
        nbr %= my_compute_power_rec(my_strlen(base), power);
        power -= 1;
    }
    op = nbr / my_compute_power_rec(my_strlen(base), power);
    my_putchar(base[op]);
    return 0;
}

unsigned long my_putnbr_base(unsigned long nbr, char const *base)
{
    int len_base = my_strlen(base);

    if (nbr == 0)
        my_putchar(base[0]);
    else if (nbr == 1)
        my_putchar(base[1]);
    else
        put_base(nbr, base);
}
