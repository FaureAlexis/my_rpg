/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** my_strncmp
*/

#include "lib.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == NULL || s2 == NULL)
        return 84;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
