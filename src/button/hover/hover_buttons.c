/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** hover_button
*/

#include "rpg.h"

static void hover_scale(button_t *button)
{
    if (button->bsize == SMALL)
        sfSprite_setScale(button->sprite, SML_HOVER_SCALE);
    if (button->bsize == MEDIUM)
        sfSprite_setScale(button->sprite, MID_HOVER_SCALE);
    if (button->bsize == LARGE)
        sfSprite_setScale(button->sprite, BIG_HOVER_SCALE);
}

static void base_scale(button_t *button)
{
    if (button->bsize == SMALL)
        sfSprite_setScale(button->sprite, SML_IDLE_SCALE);
    if (button->bsize == MEDIUM)
        sfSprite_setScale(button->sprite, MID_IDLE_SCALE);
    if (button->bsize == LARGE)
        sfSprite_setScale(button->sprite, BIG_IDLE_SCALE);
}

int manage_hover(button_t *button, sfVector2i mouse_pos)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->shape);
    sfVector2f tmp = {(button->sprite_pos.x + OFFSET_HOVER),
    (button->sprite_pos.y + OFFSET_HOVER)};

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
        sfSprite_setPosition(button->sprite, tmp);
        hover_scale(button);
    } else {
        sfSprite_setPosition(button->sprite, button->sprite_pos);
        base_scale(button);
    }
    return EXIT_SUCCESS;
}

void manage_all_hover(main_game_t *game, sfVector2i mouse_pos)
{
    manage_hover_big_buttons(game, mouse_pos);
    manage_hover_medium_buttons(game, mouse_pos);
    manage_hover_small_buttons(game, mouse_pos);
}
