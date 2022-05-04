/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init keybinding
*/

#include "rpg.h"

int init_keys(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    game->keys = malloc(sizeof(keys_t));
    if (!game->keys)
        return EPITECH_ERROR;
    game->keys->up = sfKeyW;
    game->keys->down = sfKeyS;
    game->keys->right = sfKeyA;
    game->keys->left = sfKeyD;
    game->keys->attack = sfKeySpace;
    game->keys->inventory = sfKeyI;
    return EXIT_SUCCESS;
}
