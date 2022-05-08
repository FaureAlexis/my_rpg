/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** resolve keys to str
*/

#include "rpg.h"

static char *special_keys(sfKeyCode key)
{
    switch (key) {
        case sfKeyEscape:
            return "Escape";
        case sfKeySpace:
            return "Space";
        case sfKeyLeft:
            return "Left Arrow";
        case sfKeyRight:
            return "Right Arrow";
        case sfKeyUp:
            return "Up Arrow";
        case sfKeyDown:
            return "Down Arrow";
        default:
            return "undefined";
    }
}

char *resolve_key(sfKeyCode key)
{
    char *str_key = malloc(15);
    char start = 'A';
    if (key < 27) {
        str_key[0] = start + key;
        str_key[1] = 0;
        return str_key;
    }
    return special_keys(key);
}
