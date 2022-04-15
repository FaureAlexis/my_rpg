/*
** EPITECH PROJECT, 2022
** get_event
** File description:
** get_event
*/

#include "rpg.h"

bool button_is_clicked(button_t *button, sfVector2i mouse_pos)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->shape);

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y))
        return true;
    return false;
}

const event_t *get_event(sfEventType type, const event_t event_array[])
{
    for (int i = 0; event_array[i].type != -1; i++) {
        if (event_array[i].type == type)
            return &event_array[i];
    }
    return NULL;
}
