/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** hover_button
*/

#include "rpg.h"

int manage_hover(button_t *button, sfVector2i mouse_pos)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->shape);
    sfVector2f tmp = {(button->sprite_pos.x - 5),
    (button->sprite_pos.y - 5)};

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
        sfSprite_setPosition(button->sprite, tmp);
        if (button->bsize == SMALL)
            sfSprite_setScale(button->sprite, (sfVector2f){1.2, 1.2});
        if (button->bsize == MEDIUM)
            sfSprite_setScale(button->sprite, (sfVector2f){1.2, 1.2});
    } else {
        sfSprite_setPosition(button->sprite, button->sprite_pos);
        if (button->bsize == SMALL)
            sfSprite_setScale(button->sprite, (sfVector2f){1, 1});
        if (button->bsize == MEDIUM)
            sfSprite_setScale(button->sprite, (sfVector2f){1, 1});
    }
    return EXIT_SUCCESS;
}

void manage_all_hover(main_game_t *game, sfVector2i mouse_pos)
{
    manage_hover_big_buttons(game, mouse_pos);
    manage_hover_medium_buttons(game, mouse_pos);
    manage_hover_small_buttons(game, mouse_pos);
}
