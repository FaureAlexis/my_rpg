/*
** EPITECH PROJECT, 2021
** basic_func_llc
** File description:
** basic_func_llc
*/

#include "lib.h"

void display_char_list(linked_nb_t *head)
{
    linked_nb_t *tmp = head;

    while (tmp != NULL) {
        my_printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}

void display_char_reverse_list(linked_nb_t *head)
{
    linked_nb_t *tmp = head;

    while (tmp->next != NULL)
        tmp = tmp->next;
    while (tmp != NULL) {
        my_printf("%s\n", tmp->data);
        tmp = tmp->prev;
    }
}

linked_nb_t *init_linked_char_list(int ac, char **av)
{
    linked_nb_t *head = NULL;

    for (int i = 1; i < ac; i++) {
        if (add_last_node(&head, av[i], 0, 0) == 84)
            return NULL;
    }
    return head;
}

void free_linked_char_list(linked_nb_t *head)
{
    linked_nb_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp->data);
        free(tmp);
    }
}
