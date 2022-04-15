/*
** EPITECH PROJECT, 2021
** node
** File description:
** lemin
*/

#include "lib.h"
#include "rpg.h"

obstacle_t *add_node_to_obstacle(obstacle_t *head, obstacle_t *node)
{
    obstacle_t *tmp = head;

    if (head == NULL) {
        head = node;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return head;
}
