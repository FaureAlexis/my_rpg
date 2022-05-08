/*
** EPITECH PROJECT, 2022
** player_animations_features
** File description:
** player_animations_features
*/

#include "rpg.h"

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

int modify_animations(main_game_t *game, player_t *player, sfEvent event,
movements_t movements_array[])
{
    const movements_t *movements = NULL;

    movements = get_animations(movements_array, event);
    if (!movements)
        return player->current_scene;
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
    return 0;
}
