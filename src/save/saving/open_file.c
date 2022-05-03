/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** open file using fopen
*/

#include "rpg.h"

FILE *open_save(const char *path)
{
    FILE *file = NULL;

    if (!path)
        return NULL;
    file = fopen(path, "w+");
    if (!file)
        return NULL;
    return file;
}
