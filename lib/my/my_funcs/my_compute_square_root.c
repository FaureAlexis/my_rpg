/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int n = 1;

    for (int i = 1; n < 46340; i++) {
        if (n * n == nb)
            return n;
        else
            n = i;
    }
    return 0;
}
