/*
** EPITECH PROJECT, 2021
** sign
** File description:
** sign
*/

int my_str_isnum(char const *str);

int check_sign(char const *nb)
{
    if (my_str_isnum(nb + 1) == 1 && nb[0] == '-')
        return 1;
    return 0;
}
