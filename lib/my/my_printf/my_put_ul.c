/*
** EPITECH PROJECT, 2021
** my_put_ul
** File description:
** my_put_ul
*/

#include "lib.h"

void my_put_ul(unsigned long nbr)
{
    int pos_nb = 1;
    int len = 0;

    len = nblen(nbr);
    while (pos_nb <= len) {
        my_putchar(nbr / my_compute_power_rec(10, len - pos_nb) + '0');
        nbr %= my_compute_power_rec(10, len - pos_nb);
        pos_nb += 1;
    }
}
