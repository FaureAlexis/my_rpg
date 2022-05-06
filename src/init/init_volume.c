/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_volume
*/

#include "rpg.h"

int init_volume(vol_t **vol)
{
    (*vol) = malloc(sizeof(vol_t));
    if (!(*vol))
        return EPITECH_ERROR;
    (*vol)->pos = (sfVector2f){575, 320};
    if (!(*vol)->volume)
        (*vol)->volume = 10;
    (*vol)->size = (sfVector2f){(700 / (*vol)->volume), 30};
    (*vol)->volume_rect = sfRectangleShape_create();
    if ((*vol)->volume_rect == NULL)
        return EPITECH_ERROR;
    sfRectangleShape_setFillColor((*vol)->volume_rect, sfGreen);
    sfRectangleShape_setSize((*vol)->volume_rect, (*vol)->size);
    sfRectangleShape_setPosition((*vol)->volume_rect, (*vol)->pos);
    return EXIT_SUCCESS;
}
