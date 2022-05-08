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
    sfRectangleShape_setSize((*cus)->red, (*cus)->size);
    sfRectangleShape_setSize((*cus)->green, (*cus)->size);
    sfRectangleShape_setSize((*cus)->blue, (*cus)->size);
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
    (*cus)->size = CUS_RECT_SIZE;
    (*cus)->pos_red = RED_POS;
    (*cus)->pos_green = GREEN_POS;
    (*cus)->pos_blue = BLUE_POS;
    (*cus)->red = sfRectangleShape_create();
    (*cus)->green = sfRectangleShape_create();
    (*cus)->blue = sfRectangleShape_create();
    if ((*cus)->red == NULL || (*cus)->green == NULL || (*cus)->blue == NULL)
        return EPITECH_ERROR;
    return set_rgb_shape(cus);
}
