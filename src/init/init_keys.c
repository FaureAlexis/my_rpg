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
    game->keys->quit = sfKeyF4;
    game->keys->pause = sfKeyEscape;
    game->keys->interact = sfKeyE;
    game->keys->zoom = sfKeyP;
    game->keys->unzoom = sfKeyM;
    game->keys->up = sfKeyUp;
    game->keys->down = sfKeyDown;
    game->keys->right = sfKeyRight;
    game->keys->left = sfKeyLeft;
    game->keys->attack = sfKeyA;
    game->keys->inventory = sfKeyI;
    return EXIT_SUCCESS;
}
