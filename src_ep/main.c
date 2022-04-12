/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "lib.h"
#include "rpg.h"

int main(int argc, char **argv)
{
    char ***tab = make_tab("world.txt");

    launch_rpg(tab);
    for (int i = 0; tab[i] != NULL; i += 1) {
        for (int j = 0; tab[i][j] != NULL; j += 1) {
            free(tab[i][j]);
        }
        free(tab[i]);
    }
    free(tab);
    return 0;
}
