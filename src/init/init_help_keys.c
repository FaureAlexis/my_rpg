/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init help keys
*/

#include "rpg.h"

static int set_text_config(help_touch_t *h_touch)
{
    if (!h_touch)
        return EPITECH_ERROR;
    sfText_setCharacterSize(h_touch->up, 55);
    sfText_setCharacterSize(h_touch->down, 55);
    sfText_setCharacterSize(h_touch->right, 55);
    sfText_setCharacterSize(h_touch->left, 55);
    sfText_setCharacterSize(h_touch->inventory, 55);
    sfText_setCharacterSize(h_touch->attack, 55);
    sfText_setPosition(h_touch->up, TOUCH_UP);
    sfText_setPosition(h_touch->down, TOUCH_DOWN);
    sfText_setPosition(h_touch->right, TOUCH_RIGHT);
    sfText_setPosition(h_touch->left, TOUCH_LEFT);
    sfText_setPosition(h_touch->inventory, TOUCH_INVENTORY);
    sfText_setPosition(h_touch->attack, TOUCH_ATTACK);
    return EXIT_SUCCESS;
}

int init_help_keys(help_t *help, sfFont *gravity)
{
    if (!help || !gravity || !help->h_touch)
        return EPITECH_ERROR;
    help->h_touch->up = sfText_create();
    help->h_touch->down = sfText_create();
    help->h_touch->right = sfText_create();
    help->h_touch->left = sfText_create();
    help->h_touch->inventory = sfText_create();
    help->h_touch->attack = sfText_create();
    sfText_setFont(help->h_touch->up, gravity);
    sfText_setFont(help->h_touch->down, gravity);
    sfText_setFont(help->h_touch->right, gravity);
    sfText_setFont(help->h_touch->left, gravity);
    sfText_setFont(help->h_touch->inventory, gravity);
    sfText_setFont(help->h_touch->attack, gravity);
    return set_text_config(help->h_touch);
}
