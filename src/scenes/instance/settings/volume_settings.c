/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** volume_settings
*/

#include "rpg.h"

int manage_volume_left(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->sml->left_b, mouse_pos) == true
    && game->vol->volume > 0) {
        sfMusic_stop(game->btn->sml->right_b->sound);
        sfMusic_play(game->btn->sml->left_b->sound);
        sfMusic_setVolume(game->mnu->main->theme, (game->vol->volume - 10));
        sfMusic_setVolume(game->mnu->gameplay->theme,
        (game->vol->volume - 10));
        game->vol->size.x -= 70;
        sfRectangleShape_setSize(game->vol->volume_rect, game->vol->size);
        sfRectangleShape_setPosition(game->vol->volume_rect, game->vol->pos);
        game->vol->volume -= 10;
    }
    return EXIT_SUCCESS;
}

int manage_volume_right(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->sml->right_b, mouse_pos) == true
    && game->vol->volume < 100) {
        sfMusic_stop(game->btn->sml->left_b->sound);
        sfMusic_play(game->btn->sml->right_b->sound);
        sfMusic_setVolume(game->mnu->main->theme, (game->vol->volume + 10));
        sfMusic_setVolume(game->mnu->gameplay->theme,
        (game->vol->volume + 10));
        game->vol->size.x += 70;
        sfRectangleShape_setSize(game->vol->volume_rect, game->vol->size);
        sfRectangleShape_setPosition(game->vol->volume_rect, game->vol->pos);
        game->vol->volume += 10;
    }
    manage_volume_left(game, mouse_pos);
    return EXIT_SUCCESS;
}
