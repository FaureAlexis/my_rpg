/*
** EPITECH PROJECT, 2022
** free_tab
** File description:
** free_tab
*/

#include "rpg.h"

void free_tab(char ***tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        for (int j = 0; tab[i][j] != NULL; j += 1)
            free(tab[i][j]);
        free(tab[i]);
    }
    free(tab);
}
