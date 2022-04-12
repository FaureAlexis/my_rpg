/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hover_small_buttons
*/

#include "rpg.h"

int manage_hover_small_buttons(main_game_t *game, sfVector2i mouse_pos)
{
    manage_hover(game->btn->sml->plus_b, mouse_pos);
    manage_hover(game->btn->sml->minus_b, mouse_pos);
    manage_hover(game->btn->sml->talk_b, mouse_pos);
    manage_hover(game->btn->sml->accept_b, mouse_pos);
    manage_hover(game->btn->sml->deny_b, mouse_pos);
    manage_hover(game->btn->sml->left_b, mouse_pos);
    manage_hover(game->btn->sml->right_b, mouse_pos);
    manage_hover(game->btn->sml->top_b, mouse_pos);
    manage_hover(game->btn->sml->bot_b, mouse_pos);
    return EXIT_SUCCESS;
}
