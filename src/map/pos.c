/*
** EPITECH PROJECT, 2021
** bs
** File description:
** pos
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int my_isalphanum_pos(char c, char pos)
{
    if (c != pos && c != '\n' && c != '\0') {
        return (1);
    }
    return (0);
}

int get_nb_words_pos(char const *str, char pos, int idx)
{
    int i = idx;
    int nb_words = 0;

    while (str[i] != '\n') {
        if (my_isalphanum_pos(str[i], pos) == 1 &&
            my_isalphanum_pos(str[i + 1], pos) == 0){
            nb_words += 1;
            }
        i += 1;
    }
    return (nb_words);
}

int my_lenword_pos(char const *str, int total, char pos)
{
    int idx = 0;

    while (my_isalphanum_pos(str[total], pos) != 1 && str[total] != '\n') {
        total += 1;
    }
    while (my_isalphanum_pos(str[total], pos) != 0 && str[total] != '\n'){
        idx += 1;
        total += 1;
    }
    return idx;
}

char **my_str_to_word_array_pos(char const *str, char pos, int idx)
{
    char **dest = NULL;
    int total = idx;
    int s = 0;
    int nb_words = get_nb_words_pos(str, pos, idx);

    dest = malloc(sizeof(char *) * (nb_words + 1));
    dest[nb_words] = NULL;
    for (int j = 0; j != nb_words; j += 1) {
        s = my_lenword_pos(str, total, pos);
        dest[j] = malloc(sizeof(char) * (s + 1));
        for (int f = 0; f != s; f += 1) {
            dest[j][f] = str[total + f];
        }
        dest[j][s] = '\0';
        total += (s + 1);
        if (str[total - 1] == '\n')
            return dest;
    }
    return dest;
}
