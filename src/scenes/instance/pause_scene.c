/*
** EPITECH PROJECT, 2022
** pause_scene
** File description:
** pause_scene
*/

#include "rpg.h"

static const event_t event_array[] = {
    {.type = sfEvtClosed, .events = &close_window, .index = 0},
    {.type = -1, .events = NULL, .index = -1}
};

static int pause_scene_event(main_game_t *game)
{
    const event_t *event = get_event(game->event.type, event_array);

    if (event)
        return event->events(game);
    return game->player->current_scene;
}

static int manage_button_action_scene(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->big->settings_b, mouse_pos) == true) {
        clicked_state_pause(game, game->btn->big->settings_b->shape,
        (sfVector2f){1010, 330});
        game->player->next_scene = SETTINGS_SCENE;
        return game->player->next_scene;
    }
    if (button_is_clicked(game->btn->mid->main_b, mouse_pos) == true) {
        clicked_state_pause(game, game->btn->mid->main_b->shape,
        (sfVector2f){1800, 0});
        game->player->next_scene = MENU_SCENE;
        sfSprite_setColor(game->player->object->sprite,
        sfColor_fromRGB(255, 255, 255));
        return game->player->next_scene;
    }
    return game->player->current_scene;
}

static int manage_button_action(main_game_t *game, sfVector2i mouse_pos)
{
    if (manage_button_action_scene(game, mouse_pos)
    != game->player->current_scene)
        return game->player->next_scene;
    if (button_is_clicked(game->btn->big->return_b, mouse_pos) == true) {
        clicked_state_pause(game, game->btn->big->return_b->shape,
        (sfVector2f){500, 330});
        game->player->next_scene = GAME_SCENE;
        return game->player->next_scene;
    }
    if (button_is_clicked(game->btn->big->exit_b, mouse_pos) == true) {
        clicked_state_pause(game, game->btn->big->exit_b->shape,
        (sfVector2f){750, 650});
        return close_window(game);
    }
    return game->player->current_scene;
}

static int pause_check_events(main_game_t *game, sfVector2i mouse_pos)
{
    while (sfRenderWindow_pollEvent(game->w, &game->event)) {
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == game->keys->pause) {
            clicked_state_pause(game, game->btn->big->return_b->shape,
            (sfVector2f){500, 330});
            game->player->next_scene = GAME_SCENE;
            return game->player->next_scene;
        }
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_button_action(game, mouse_pos);
        if (pause_scene_event(game) != game->player->current_scene)
            return game->player->next_scene;
        if (game->event.type == sfEvtClosed || (game->event.key.code
        == game->keys->quit && game->event.type == sfEvtKeyPressed)) {
            return close_window(game);
        }
    }
    return game->player->current_scene;
}

int pause_scene(main_game_t *game)
{
    sfVector2i mouse_pos;

    starting_pause_scene(game);
    while (sfRenderWindow_isOpen(game->w)) {
        sfView_reset(game->basic_view, (sfFloatRect){0, 0, 1920, 1080});
        sfRenderWindow_setView(game->w, game->basic_view);
        mouse_pos = sfMouse_getPositionRenderWindow(game->w);
        sfRenderWindow_clear(game->w, sfWhite);
        manage_all_hover(game, mouse_pos);
        if (pause_check_events(game, mouse_pos)
        != game->player->current_scene) {
            sfMusic_stop(game->btn->mid->pause_b->sound);
            return game->player->next_scene;
        }
        display_pause(game);
        sfRenderWindow_display(game->w);
    }
    return EXIT_SUCCESS;
}
