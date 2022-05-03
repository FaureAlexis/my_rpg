/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hover_big_buttons
*/

#include "rpg.h"

int manage_hover_big_buttons(main_game_t *game, sfVector2i mouse_pos)
{
    manage_hover(game->btn->big->score_b, mouse_pos);
    manage_hover(game->btn->big->resume_b, mouse_pos);
    manage_hover(game->btn->big->help_b, mouse_pos);
    manage_hover(game->btn->big->settings_b, mouse_pos);
    manage_hover(game->btn->big->return_b, mouse_pos);
    manage_hover(game->btn->big->play_b, mouse_pos);
    manage_hover(game->btn->big->exit_b, mouse_pos);
    manage_hover(game->btn->big->newsave_b, mouse_pos);
    manage_hover(game->btn->big->load_b, mouse_pos);
    return EXIT_SUCCESS;
}
