/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

unsigned long long my_compute_power_rec(int nb, unsigned long p)
{
    unsigned long long res;

    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    res = nb * my_compute_power_rec(nb, p - 1);
    return (res);
}
