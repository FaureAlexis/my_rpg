/*
** EPITECH PROJECT, 2021
** my_getnbr_base
** File description:
** my_getnbr_base
*/

#include "lib.h"

int in_base(char c, char const *base)
{
    for (int i = 0; base[i] != '\0'; i++) {
        if (base[i] == c)
            return 1;
    }
    return 0;
}

int base_valid_nb(char c, char const *base)
{
    if (in_base(c, base) == 1 || c == '-' || c == '+')
        return 1;
    return 0;
}

char *detect_base(char const *str, char const *base)
{
    int size = 0;
    int j = 0;
    int i = 0;
    char *dest = NULL;

    for (; str[i] != '\0' && base_valid_nb(str[i], base) == 1; i++) {
        if (in_base(str[i - 1], base) == 1 && in_base(str[i], base) == 0)
            break;
        else if (in_base(str[i], base) == 1)
            size += 1;
    }
    dest = malloc(sizeof(char) * size + 1);
    size = i - size;
    for (; in_base(str[size], base) == 1 && str[i] != str[size]; size++) {
        dest[j] = str[size];
        j++;
    }
    dest[j] = '\0';
    return dest;
}

int my_getnbr_base(char const *str, char const *base)
{
    char *extract_nb = detect_base(str, base);
    int sign = counter_sign(str);
    int base_nb = my_strlen(base);
    int power = my_strlen(extract_nb) - 1;
    long result = 0;
    int nb = 0;

    for (int i = 0; extract_nb[i] != '\0'; i++) {
        nb = return_index(extract_nb[i], base);
        result += nb * my_compute_power_rec(base_nb, power);
        power -= 1;
    }
    return (result * sign);
}
