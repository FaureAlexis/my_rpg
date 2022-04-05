/*
** EPITECH PROJECT, 2022
** get_event
** File description:
** get_event
*/

#include "rpg.h"

const event_t *get_event(sfEventType type, const event_t event_array[])
{
    for (int i = 0; event_array[i].type != -1; i++) {
        if (event_array[i].type == type)
            return &event_array[i];
    }
    return NULL;
}
