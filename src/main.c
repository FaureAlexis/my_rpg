/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "rpg.h"

int main(int argc, const char * const *argv, char ** env)
{
    if (!argv || !env)
        return 84;
    return rpg(argc, argv, env);
}
