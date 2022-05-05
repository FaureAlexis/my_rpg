/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** keybinding struct
*/

#ifndef KEYS_H
    #define KEYS_H

    /* Keysbind struct */
typedef struct keys_s {
    sfKeyCode quit;
    sfKeyCode pause;
    sfKeyCode interact;
    sfKeyCode zoom;
    sfKeyCode unzoom;
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode right;
    sfKeyCode left;
    sfKeyCode attack;
    sfKeyCode inventory;
} keys_t;

#endif /* !KEYS_H */
