/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hover_medium_buttons
*/

#include "rpg.h"

int manage_hover_medium_buttons(main_game_t *game, sfVector2i mouse_pos)
{
    manage_hover(game->btn->mid->main_b, mouse_pos);
    manage_hover(game->btn->mid->pause_b, mouse_pos);
    manage_hover(game->btn->mid->mute_b, mouse_pos);
    manage_hover(game->btn->mid->help_b, mouse_pos);
    manage_hover(game->btn->mid->exit_b, mouse_pos);
    manage_hover(game->btn->mid->unmute_b, mouse_pos);
    manage_hover(game->btn->mid->keybind_b, mouse_pos);
    return EXIT_SUCCESS;
}
