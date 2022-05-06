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

static int game_scene_event(main_game_t *game)
{
    const event_t *event = get_event(game->event.type, event_array);

    if (event)
        return event->events(game);
    if (game->event.key.code == game->keys->pause
    && game->event.type == sfEvtKeyPressed) {
        clicked_state_game(game, game->btn->mid->pause_b->shape,
        (sfVector2f){10, 10});
        game->player->next_scene = PAUSE_SCENE;
        return game->player->next_scene;
    }
    trigger_inventory(game);
    zoom_event(game);
    return game->player->current_scene;
}

static int manage_button_action(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->mid->pause_b, mouse_pos) == true) {
        clicked_state_game(game, game->btn->mid->pause_b->shape,
        (sfVector2f){10, 10});
        game->player->next_scene = PAUSE_SCENE;
        return game->player->next_scene;
    }
    return game->player->current_scene;
}

static int game_check_events(main_game_t *game, sfVector2i mouse_pos)
{
    while (sfRenderWindow_pollEvent(game->w, &game->event)) {
        set_player_movements(game, game->player, game->event);
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_button_action(game, mouse_pos);
        if (game_scene_event(game) != game->player->current_scene)
            return game->player->next_scene;
        if (game->event.key.code == game->keys->quit && game->event.type
        == sfEvtKeyPressed)
            return close_window(game);
    }
    return game->player->current_scene;
}

int game_scene(main_game_t *game)
{
    sfVector2i mouse_pos;

    starting_game_scene(game);
    while (sfRenderWindow_isOpen(game->w)) {
        sfRenderWindow_setView(game->w, game->game_view);
        mouse_pos = sfMouse_getPositionRenderWindow(game->w);
        sfRenderWindow_clear(game->w, sfColor_fromRGB(80,155,102));
        manage_all_hover(game, mouse_pos);
        if (game_check_events(game, mouse_pos)
        != game->player->current_scene) {
            sfMusic_stop(game->btn->big->play_b->sound);
            return game->player->next_scene;
        }
        player_animations(game->player, game->map->mobe);
        display_game(game);
        sfRenderWindow_display(game->w);
    }
    return EXIT_SUCCESS;
}
