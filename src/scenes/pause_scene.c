/*
** EPITECH PROJECT, 2022
** pause_scene
** File description:
** pause_scene
*/

#include "rpg.h"

static const event_t event_array[] = {
    {.type = sfEvtClosed, .events = &close_window},
    {.type = -1, .events = NULL}
};

static int pause_scene_event(main_game_t *game)
{
    const event_t *event = get_event(game->event.type, event_array);

    if (event)
        return event->events(game);
    return game->player->current_scene;
}

static int pause_check_events(main_game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (pause_scene_event(game) != game->player->current_scene)
            return game->player->next_scene;
        if (game->event.type == sfEvtClosed || (game->event.key.code == sfKeyQ
        && game->event.type == sfEvtKeyPressed)) {
            sfRenderWindow_close(game->window);
            exit(0);
        }
    }
    return game->player->current_scene;
}

int pause_scene(main_game_t *game)
{
    sfVector2i mouse_pos;

    game->player->current_scene = PAUSE_SCENE;
    while (sfRenderWindow_isOpen(game->window)) {
        mouse_pos = sfMouse_getPositionRenderWindow(game->window);
        sfRenderWindow_clear(game->window, sfWhite);
        manage_all_hover(game, mouse_pos);
        if (pause_check_events(game) != game->player->current_scene)
            return game->player->next_scene;
        sfRenderWindow_drawSprite(game->window,
        game->btn->big->play_b->sprite, NULL);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
