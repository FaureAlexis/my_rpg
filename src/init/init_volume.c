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
    (*vol)->pos = VOL_POS;
    (*vol)->volume = 10;
    (*vol)->size = VOL_SIZE;
    (*vol)->volume_rect = sfRectangleShape_create();
    (*vol)->thickness = sfRectangleShape_create();
    if ((*vol)->volume_rect == NULL || (*vol)->thickness == NULL)
        return EPITECH_ERROR;
    sfRectangleShape_setFillColor((*vol)->volume_rect, sfGreen);
    sfRectangleShape_setFillColor((*vol)->thickness, sfTransparent);
    sfRectangleShape_setSize((*vol)->volume_rect, (*vol)->size);
    sfRectangleShape_setPosition((*vol)->volume_rect, (*vol)->pos);
    sfRectangleShape_setSize((*vol)->thickness, VOL_OUTLINE_SIZE);
    sfRectangleShape_setPosition((*vol)->thickness, (*vol)->pos);
    sfRectangleShape_setOutlineColor((*vol)->thickness, sfBlack);
    sfRectangleShape_setOutlineThickness((*vol)->thickness, 7);
    return EXIT_SUCCESS;
}
