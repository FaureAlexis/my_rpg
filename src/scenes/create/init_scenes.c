/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** init_menus
*/

#include "rpg.h"

static int init_menu_sprite(menu_t **menu)
{
    if (menu == NULL)
        return EPITECH_ERROR;
    (*menu)->object->sprite = sfSprite_create();
    (*menu)->bg_object->sprite = sfSprite_create();
    if ((*menu)->bg_object->sprite == NULL || (*menu)->object->sprite == NULL)
        return EPITECH_ERROR;
    sfSprite_setTexture((*menu)->object->sprite,
    (*menu)->object->texture, sfTrue);
    sfSprite_setTexture((*menu)->bg_object->sprite,
    (*menu)->bg_object->texture, sfTrue);
    return EXIT_SUCCESS;
}

int init_menu(menu_t **menu, char *theme, char *texture, sfIntRect rect)
{
    if (!theme || !texture)
        return EPITECH_ERROR;
    (*menu) = malloc(sizeof(menu_t));
    if (!(*menu))
        return EPITECH_ERROR;
    (*menu)->object = malloc(sizeof(game_object_t));
    (*menu)->bg_object = malloc(sizeof(game_object_t));
    if (!(*menu)->object || !(*menu)->bg_object)
        return EPITECH_ERROR;
    (*menu)->object->rect = rect;
    (*menu)->theme = sfMusic_createFromFile(theme);
    (*menu)->bg_object->texture = sfTexture_createFromFile(SETTINGS_BG, NULL);
    (*menu)->object->texture = sfTexture_createFromFile(texture, NULL);
    if ((*menu)->bg_object->texture == NULL || (*menu)->theme == NULL
    || (*menu)->object->texture == NULL)
        return EPITECH_ERROR;
    sfMusic_setLoop((*menu)->theme, true);
    if (init_menu_sprite(menu) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
