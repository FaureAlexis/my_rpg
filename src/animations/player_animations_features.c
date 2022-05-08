/*
** EPITECH PROJECT, 2022
** player_animations_features
** File description:
** player_animations_features
*/

#include "rpg.h"

int set_player_movements(main_game_t *game, player_t *player, sfEvent *event)
{
    movements_t movements_array[] = {
        {.key = game->keys->up, .height_ss = 48, .flip = 0},
        {.key = game->keys->left, .height_ss = 48, .flip = -4},
        {.key = game->keys->down, .height_ss = 48, .flip = 0},
        {.key = game->keys->right, .height_ss = 48, .flip = 4},
        {.key = game->keys->attack, .height_ss = 96, .flip = 0},
        {.key = game->keys->interact, .height_ss = 0, .flip = 0},
        {.key = sfKeyUnknown, .height_ss = 0, .flip = 0}
    };
    bool pressed = detect_animations(movements_array);

    if (pressed)
        modify_animations(game, player, *event, movements_array);
    else
        player->object->rect.top = 0;
    return player->current_scene;
}

static const movements_t *get_animations(movements_t movements_array[],
sfEvent event)
{
    for (int i = 0; movements_array[i].key != sfKeyUnknown; i++) {
        if (movements_array[i].key == event.key.code)
            return &movements_array[i];
    }
    return NULL;
}

int detect_animations(movements_t movements_array[])
{
    for (int i = 0; movements_array[i].key != sfKeyUnknown; i++) {
        if (sfKeyboard_isKeyPressed(movements_array[i].key))
            return 1;
    }
    return 0;
}

static int set_player_interactions_in_func(player_t *player)
{
    if (player->interaction && player->nb_interactions < 3)
        player->nb_interactions++;
    else
        player->nb_interactions = 0;
    return EXIT_SUCCESS;
}

int modify_animations(main_game_t *game, player_t *player, sfEvent event,
movements_t movements_array[])
{
    const movements_t *movements = NULL;

    movements = get_animations(movements_array, event);
    if (!movements)
        return player->current_scene;
    if (sfKeyboard_isKeyPressed(game->keys->interact))
        return set_player_interactions_in_func(player);
    if (movements->flip != 0)
        player->object->scale.x = movements->flip;
    if (movements->height_ss == 96 && !player->attack_action) {
        player->attack_action = 1;
        player->object->rect.left = 0;
    }
    player->hitbox = sfRectangleShape_getGlobalBounds(player->hitbox_shape);
    move_player(game, movements);
    player->object->rect.top = movements->height_ss;
    sfSprite_setScale(player->object->sprite, player->object->scale);
    return EXIT_SUCCESS;
}
