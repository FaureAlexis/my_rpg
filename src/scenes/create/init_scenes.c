/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** init_menus
*/

#include "rpg.h"

int init_menu(menu_t **menu, char *theme, char *texture, sfIntRect rect)
{
    (*menu) = malloc(sizeof(menu_t));
    if (!(*menu))
        return EPITECH_ERROR;
    (*menu)->rect = rect;
    (*menu)->theme = sfMusic_createFromFile(theme);
    if ((*menu)->theme == NULL)
        return EPITECH_ERROR;
    sfMusic_setLoop((*menu)->theme, true);
    (*menu)->bg_texture = sfTexture_createFromFile(SETTINGS_BG, NULL);
    (*menu)->texture = sfTexture_createFromFile(texture, NULL);
    if ((*menu)->bg_texture == NULL || (*menu)->texture == NULL)
        return EPITECH_ERROR;
    (*menu)->sprite = sfSprite_create();
    (*menu)->bg_sprite = sfSprite_create();
    if ((*menu)->bg_sprite == NULL || (*menu)->sprite == NULL)
        return EPITECH_ERROR;
    sfSprite_setTexture((*menu)->sprite, (*menu)->texture, sfTrue);
    sfSprite_setTexture((*menu)->bg_sprite, (*menu)->bg_texture, sfTrue);
    return EXIT_SUCCESS;
}
