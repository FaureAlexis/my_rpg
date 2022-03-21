/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** my_revstr
*/

#include "lib.h"

char *my_revstr(char *str)
{
    int begin_str = 0;
    int compteur = my_strlen(str);

    for (int i = 0; begin_str <= compteur; i++) {
        reverse_opp_numb(&str[compteur - 1], &str[begin_str]);
        begin_str = begin_str + 1;
        compteur = compteur - 1;
    }
    return (str);
}
