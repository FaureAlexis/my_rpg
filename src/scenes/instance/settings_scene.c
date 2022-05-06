/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

static const event_t event_array[] = {
    {.type = sfEvtClosed, .events = &close_window, .index = 0},
    {.type = -1, .events = NULL, .index = -1}
};

static int settings_scene_event(main_game_t *game)
{
    const event_t *event = get_event(game->event.type, event_array);

    if (event)
        return event->events(game);
    return game->player->current_scene;
}

static int manage_button_action_scene(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->big->return_b, mouse_pos) == true) {
        clicked_state_settings(game, game->btn->big->return_b->shape,
        (sfVector2f){520, 780});
        if (game->menu_depth == 1)
            game->player->next_scene = MENU_SCENE;
        else
            game->player->next_scene = PAUSE_SCENE;
        return game->player->next_scene;
    }
    if (button_is_clicked(game->btn->mid->keybind_b, mouse_pos) == true) {
        clicked_state_settings(game, game->btn->mid->keybind_b->shape,
        (sfVector2f){1500, 600});
        return game->player->next_scene = KEYBIND_SCENE;
    }
    if (button_is_clicked(game->btn->mid->help_b, mouse_pos) == true) {
        clicked_state_settings(game, game->btn->mid->help_b->shape,
        (sfVector2f){10, 10});
        return game->player->next_scene = HELP_SCENE;
    }
    return game->player->current_scene;
}

static int manage_button_action(main_game_t *game, sfVector2i mouse_pos)
{
    if (manage_button_action_scene(game, mouse_pos)
    != game->player->current_scene)
        return game->player->next_scene;
    if (button_is_clicked(game->btn->big->exit_b, mouse_pos) == true) {
        clicked_state_settings(game, game->btn->big->exit_b->shape,
        (sfVector2f){1000, 780});
        return close_window(game);
    }
    mute_all(game, mouse_pos);
    unmute_all(game, mouse_pos);
    manage_volume_right(game, mouse_pos);
    manage_fps_plus(game, mouse_pos);
    manage_reso_plus(game, mouse_pos);
    return game->player->current_scene;
}

static int settings_check_events(main_game_t *game, sfVector2i mouse_pos)
{
    while (sfRenderWindow_pollEvent(game->w, &game->event)) {
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_button_action(game, mouse_pos);
        if (settings_scene_event(game) != game->player->current_scene)
            return game->player->next_scene;
        if (game->event.type == sfEvtClosed || (game->event.key.code
        == game->keys->quit && game->event.type == sfEvtKeyPressed)) {
            return close_window(game);
        }
    }
    return game->player->current_scene;
}

int settings_scene(main_game_t *game)
{
    sfVector2i mouse_pos;

    starting_settings_scene(game);
    while (sfRenderWindow_isOpen(game->w)) {
        mouse_pos = sfMouse_getPositionRenderWindow(game->w);
        sfRenderWindow_clear(game->w, sfWhite);
        manage_all_hover(game, mouse_pos);
        if (settings_check_events(game, mouse_pos)
        != game->player->current_scene) {
            sfMusic_stop(game->btn->big->settings_b->sound);
            return game->player->next_scene;
        }
        display_settings(game);
        sfRenderWindow_display(game->w);
    }
    return 0;
}
