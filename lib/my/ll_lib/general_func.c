/*
** EPITECH PROJECT, 2021
** general_func
** File description:
** general_func
*/

#include "lib.h"

int add_last_node(linked_nb_t **head, char *value, int nb, bool status)
{
    linked_nb_t *node = malloc(sizeof(linked_nb_t));
    linked_nb_t *lnode;

    if (node == NULL)
        return 84;
    node->nb = nb;
    node->data = value;
    node->status = status;
    node->next = NULL;
    node->prev = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        lnode = *head;
        while (lnode->next != NULL)
            lnode = lnode->next;
        lnode->next = node;
        node->prev = lnode;
    }
    return 0;
}

int get_list_len(linked_nb_t *head)
{
    int count = 1;
    linked_nb_t *temp = head;

    while (temp->next != NULL) {
        count += 1;
        temp = temp->next;
    }
    return count;
}

linked_nb_t *get_node(linked_nb_t **head, int pos)
{
    linked_nb_t *temp = *head;

    if (pos > get_list_len(temp) - 1)
        return NULL;
    for (int i = 0; i < pos; i++)
        temp = temp->next;
    return temp;
}

void free_linked_list(linked_nb_t *head)
{
    linked_nb_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
