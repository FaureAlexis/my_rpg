/*
** EPITECH PROJECT, 2021
** get_from_nodec
** File description:
** get_from_nodec
*/

#include "lib.h"

char *get_value_from_pos(linked_nb_t *list, int pos)
{
    linked_nb_t *temp = list;

    for (int i = 0; i < pos; i++) {
        if (temp->next == NULL)
            return NULL;
        temp = temp->next;
    }
    temp = list;
    for (int i = 0; temp != NULL && i < pos; i++)
        temp = temp->next;
    return temp->data;
}
