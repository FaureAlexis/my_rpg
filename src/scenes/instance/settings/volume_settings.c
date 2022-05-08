/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** volume_settings
*/

#include "rpg.h"

void change_volume(main_game_t *game)
{
    sfMusic_setVolume(game->mnu->main->theme, game->vol->volume);
    sfMusic_setVolume(game->mnu->lose_m->theme, game->vol->volume);
    sfMusic_setVolume(game->mnu->win_m->theme, game->vol->volume);
    sfMusic_setVolume(game->mnu->gameplay->theme, game->vol->volume);
    sfMusic_setVolume(game->btn->big->play_b->sound, game->vol->volume);
    sfMusic_setVolume(game->btn->mid->help_b->sound, game->vol->volume);
    sfMusic_setVolume(game->btn->mid->keybind_b->sound, game->vol->volume);
    sfMusic_setVolume(game->btn->mid->main_b->sound, game->vol->volume);
    sfMusic_setVolume(game->btn->mid->pause_b->sound, game->vol->volume);
    sfMusic_setVolume(game->btn->big->settings_b->sound, game->vol->volume);
    sfMusic_setVolume(game->player->sword, game->vol->volume);
    sfMusic_setVolume(game->player->walk, game->vol->volume);
    sfMusic_setVolume(game->player->death, game->vol->volume);
}

int mute_all(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->mid->mute_b, mouse_pos) == true) {
        clicked_state_settings(game, game->btn->mid->keybind_b->shape,
        POS_MUTE);
        sfMusic_stop(game->btn->sml->right_b->sound);
        sfMusic_play(game->btn->sml->left_b->sound);
        game->vol->volume = 0;
        change_volume(game);
        game->vol->size.x = 0;
        sfRectangleShape_setSize(game->vol->volume_rect, game->vol->size);
        sfRectangleShape_setPosition(game->vol->volume_rect, game->vol->pos);
    }
    return EXIT_SUCCESS;
}

int unmute_all(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->mid->unmute_b, mouse_pos) == true) {
        clicked_state_settings(game, game->btn->mid->keybind_b->shape,
        POS_UNMUTE);
        sfMusic_stop(game->btn->sml->right_b->sound);
        sfMusic_play(game->btn->sml->left_b->sound);
        game->vol->volume = 50;
        change_volume(game);
        game->vol->size.x = 350;
        sfRectangleShape_setSize(game->vol->volume_rect, game->vol->size);
        sfRectangleShape_setPosition(game->vol->volume_rect, game->vol->pos);
    }
    return EXIT_SUCCESS;
}

int manage_volume_left(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->sml->left_b, mouse_pos) == true
        && game->vol->volume > 0) {
        game->vol->volume -= 5;
        sfMusic_stop(game->btn->sml->right_b->sound);
        sfMusic_play(game->btn->sml->left_b->sound);
        change_volume(game);
        game->vol->size.x -= 35;
        sfRectangleShape_setSize(game->vol->volume_rect, game->vol->size);
        sfRectangleShape_setPosition(game->vol->volume_rect, game->vol->pos);
    }
    return EXIT_SUCCESS;
}

int manage_volume_right(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->sml->right_b, mouse_pos) == true
        && game->vol->volume < 100) {
        game->vol->volume += 5;
        sfMusic_stop(game->btn->sml->left_b->sound);
        sfMusic_play(game->btn->sml->right_b->sound);
        change_volume(game);
        game->vol->size.x += 35;
        sfRectangleShape_setSize(game->vol->volume_rect, game->vol->size);
        sfRectangleShape_setPosition(game->vol->volume_rect, game->vol->pos);
    }
    manage_volume_left(game, mouse_pos);
    return EXIT_SUCCESS;
}
