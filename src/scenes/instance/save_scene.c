/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

static const event_t event_array[] = {
    {.type = sfEvtClosed, .events = &close_window},
    {.type = -1, .events = NULL}
};

static int save_scene_event(main_game_t *game)
{
    const event_t *event = get_event(game->event.type, event_array);

    if (event)
        return event->events(game);
    return game->player->current_scene;
}

static int manage_button_action_scene(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->big->newsave_b, mouse_pos) == true) {
        clicked_state_save(game, game->btn->big->newsave_b->shape,
        (sfVector2f){540, 450});
        sfMusic_play(game->btn->big->settings_b->sound);
        return game->player->next_scene = SKIN_SCENE;
    }
    if (button_is_clicked(game->btn->big->load_b, mouse_pos) == true) {
        clicked_state_save(game, game->btn->big->load_b->shape,
        (sfVector2f){960, 450});
        sfMusic_play(game->btn->big->settings_b->sound);
        return game->player->next_scene = GAME_SCENE;
    }
    if (button_is_clicked(game->btn->big->return_b, mouse_pos) == true) {
        clicked_state_save(game, game->btn->big->return_b->shape,
        (sfVector2f){750, 700});
        sfMusic_play(game->btn->big->settings_b->sound);
        return game->player->next_scene = MENU_SCENE;
    }
    return game->player->current_scene;
}

static int manage_button_action(main_game_t *game, sfVector2i mouse_pos)
{
    if (manage_button_action_scene(game, mouse_pos)
    != game->player->current_scene)
        return game->player->next_scene;
    if (button_is_clicked(game->btn->big->exit_b, mouse_pos) == true) {
        clicked_state_save(game, game->btn->big->exit_b->shape,
        (sfVector2f){750, 700});
        return close_window(game);
    }
    return game->player->current_scene;
}

static int save_check_events(main_game_t *game, sfVector2i mouse_pos)
{
    while (sfRenderWindow_pollEvent(game->w, &game->event)) {
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_button_action(game, mouse_pos);
        if (save_scene_event(game) != game->player->current_scene)
            return game->player->next_scene;
        if (game->event.type == sfEvtClosed || (game->event.key.code == sfKeyQ
        && game->event.type == sfEvtKeyPressed)) {
            return close_window(game);
        }
    }
    return game->player->current_scene;
}

int save_scene(main_game_t *game)
{
    sfVector2i mouse_pos;

    starting_save_scene(game);
    while (sfRenderWindow_isOpen(game->w)) {
        mouse_pos = sfMouse_getPositionRenderWindow(game->w);
        sfRenderWindow_clear(game->w, sfWhite);
        manage_all_hover(game, mouse_pos);
        if (save_check_events(game, mouse_pos) != game->player->current_scene)
            return game->player->next_scene;
        display_save(game);
        sfRenderWindow_display(game->w);
    }
    return 0;
}