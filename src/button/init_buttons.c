/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** init_buttons
*/

#include "rpg.h"

int init_button_shape(button_t **button, sfVector2f position, int size,
char **tab)
{
    (*button)->sound = sfMusic_createFromFile(tab[0]);
    if ((*button)->sound == NULL)
        return EPITECH_ERROR;
    (*button)->shape = sfRectangleShape_create();
    if ((*button)->shape == NULL)
        return EPITECH_ERROR;
    if (size == SMALL)
        sfRectangleShape_setSize((*button)->shape, (sfVector2f){80, 80});
    if (size == MEDIUM)
        sfRectangleShape_setSize((*button)->shape, (sfVector2f){120, 120});
    if (size == LARGE)
        sfRectangleShape_setSize((*button)->shape, (sfVector2f){330, 180});
    sfRectangleShape_setPosition((*button)->shape, (*button)->position);
    sfRectangleShape_setFillColor((*button)->shape,
    sfColor_fromRGBA(0, 0, 255, 150));
    return EXIT_SUCCESS;
}

int init_button(button_t **button, sfVector2f position, int size,
char **tab)
{
    (*button) = malloc(sizeof(button_t));
    if (!(*button))
        return EPITECH_ERROR;
    (*button)->position = position;
    init_button_shape(button, position, size, tab);
    (*button)->texture = sfTexture_createFromFile(tab[1], NULL);
    if ((*button)->texture == NULL)
        return EPITECH_ERROR;
    (*button)->sprite = sfSprite_create();
    if ((*button)->sprite == NULL)
        return EPITECH_ERROR;
    sfSprite_setTexture((*button)->sprite, (*button)->texture, sfTrue);
    sfSprite_setPosition((*button)->sprite, position);
    (*button)->sprite_pos = sfSprite_getPosition((*button)->sprite);
    (*button)->bsize = size;
    return EXIT_SUCCESS;
}
