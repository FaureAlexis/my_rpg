/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** open file using fopen
*/

#include "rpg.h"

FILE *open_save(const char *path)
{
    if (!path)
        return NULL;
    FILE *file = fopen(path, "w");
    if (!file)
        return NULL;
    return file;
}
