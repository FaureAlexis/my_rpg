/*
** EPITECH PROJECT, 2022
** init_inventory
** File description:
** init_inventory
*/

#include "rpg.h"

static int add_node(case_inventory_t **case_inventory, int x, int y)
{
    case_inventory_t *node = malloc(sizeof(case_inventory_t));
    case_inventory_t *lnode = NULL;

    node->next = NULL;
    node->x = x;
    node->y = y;
    node->object = NULL;
    if (!node)
        return EPITECH_ERROR;
    if (*case_inventory == NULL) {
        *case_inventory = node;
    } else {
        lnode = *case_inventory;
        while (lnode->next != NULL)
            lnode = lnode->next;
        lnode->next = node;
    }
    return EXIT_SUCCESS;
}

static case_inventory_t *init_case_x_inventory(inventory_t *inventory, \
int offset, case_inventory_t *case_inventory, int i)
{
    int x = inventory->case_inventory_x + inventory->space_case;

    for (int j = x; j < inventory->case_inventory_max_x; j += offset) {
        if (add_node(&case_inventory, j, i) == EPITECH_ERROR)
            return NULL;
    }
    return case_inventory;
}

static case_inventory_t *init_case_inventory(inventory_t *inventory)
{
    case_inventory_t *case_inventory = NULL;
    int y = inventory->case_inventory_y + inventory->space_case;
    int offset = inventory->offset_case_inventory + inventory->space_case;

    for (int i = y; i < inventory->case_inventory_max_y; i += offset) {
        case_inventory = init_case_x_inventory(inventory,
        offset, case_inventory, i);
        if (case_inventory == NULL)
            return NULL;
    }
    return case_inventory;
}

int init_inventory(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    game->inv_open = 0;
    game->inventory = malloc(sizeof(inventory_t));
    if (!game->inventory)
        return EPITECH_ERROR;
    game->inventory->case_inventory_max_x = INV_CASE_MAX_X;
    game->inventory->case_inventory_max_y = INV_CASE_MAX_Y;
    game->inventory->case_inventory_x = INV_CASE_X;
    game->inventory->case_inventory_y = INV_CASE_Y;
    game->inventory->offset_case_inventory = INV_CASE_OFFSET;
    game->inventory->space_case = INV_CASE_SPACE;
    game->inventory->nb_case_inventory = INV_CASE_NB;
    game->inventory->case_inventory = init_case_inventory(game->inventory);
    if (!game->inventory->case_inventory)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
