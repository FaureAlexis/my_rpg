/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "rpg.h"

int main(int argc, const char * const *argv, char ** env)
{
    if (!argv || !env || check_env(env) == 84)
        return 84;
    return 0;
}
