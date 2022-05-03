/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_skin_custom
*/

#include "rpg.h"

int set_rgb_shape(cus_t **cus)
{
    if (cus == NULL)
        return EPITECH_ERROR;
    sfRectangleShape_setFillColor((*cus)->red, sfRed);
    sfRectangleShape_setFillColor((*cus)->green, sfGreen);
    sfRectangleShape_setFillColor((*cus)->blue, sfBlue);
    sfRectangleShape_setSize((*cus)->red, (sfVector2f){400, 30});
    sfRectangleShape_setSize((*cus)->green, (sfVector2f){400, 30});
    sfRectangleShape_setSize((*cus)->blue, (sfVector2f){400, 30});
    sfRectangleShape_setPosition((*cus)->red, (*cus)->pos_red);
    sfRectangleShape_setPosition((*cus)->green, (*cus)->pos_green);
    sfRectangleShape_setPosition((*cus)->blue, (*cus)->pos_blue);
    return EXIT_SUCCESS;
}

int init_skin_custom(cus_t **cus)
{
    (*cus) = malloc(sizeof(cus_t));
    if (!(*cus))
        return EPITECH_ERROR;
    (*cus)->click_red = true;
    (*cus)->click_green = false;
    (*cus)->click_blue = false;
    (*cus)->red_c = 255;
    (*cus)->green_c = 255;
    (*cus)->blue_c = 255;
    (*cus)->pos_red = (sfVector2f){850, 400};
    (*cus)->pos_green = (sfVector2f){850, 460};
    (*cus)->pos_blue = (sfVector2f){850, 520};
    (*cus)->red = sfRectangleShape_create();
    (*cus)->green = sfRectangleShape_create();
    (*cus)->blue = sfRectangleShape_create();
    if ((*cus)->red == NULL || (*cus)->green == NULL || (*cus)->blue == NULL)
        return EPITECH_ERROR;
    if (set_rgb_shape(cus) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
