/*
** EPITECH PROJECT, 2021
** basic_func_lli
** File description:
** basic_func_lli
*/

#include "lib.h"

void display_nb_list(linked_nb_t *head)
{
    linked_nb_t *tmp = head;

    while (tmp != NULL) {
        my_printf("%d\n", tmp->nb);
        tmp = tmp->next;
    }
}

void display_nb_reverse_list(linked_nb_t *head)
{
    linked_nb_t *tmp = head;

    while (tmp->next != NULL)
        tmp = tmp->next;
    while (tmp != NULL) {
        my_printf("%d\n", tmp->nb);
        tmp = tmp->prev;
    }
}

linked_nb_t *init_linked_nb_list(int ac, char **av)
{
    linked_nb_t *head = NULL;

    for (int i = 1; i < ac; i++) {
        if (add_last_node(&head, NULL, my_atoi(av[i]), 0) == 84)
            return NULL;
    }
    return head;
}
