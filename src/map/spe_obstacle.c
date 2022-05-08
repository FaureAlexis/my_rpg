/*
** EPITECH PROJECT, 2022
** spe_obstacle
** File description:
** spe_obstacle
*/

#include "rpg.h"

static speobstacle_t *set_next_pos(main_game_t *game, speobstacle_t *tmp)
{
    sfSprite_setTextureRect(tmp->object->sprite, tmp->object->rect);
    sfSprite_setPosition(tmp->object->sprite, tmp->object->position);
    tmp->hitbox = sfSprite_getGlobalBounds(tmp->object->sprite);
    sfRectangleShape_setPosition(tmp->hitbox_shape,
    (sfVector2f){tmp->object->position.x - 40, tmp->object->position.y +
    5});
    tmp->hitbox = sfRectangleShape_getGlobalBounds(tmp->hitbox_shape);
    sfRenderWindow_drawSprite(game->w, tmp->object->sprite, NULL);
    return tmp;
}

void display_speobstacle(main_game_t *game)
{
    speobstacle_t *tmp = game->map->speobstacle;

    while (tmp) {
        if (sqrt(pow(game->player->object->position.x - tmp->object->position.x
        , 2) + pow(game->player->object->position.y - tmp->object->position.y,
        2)) < 90) {
            tmp->object->rect.left = 16 * tmp->type;
            tmp->hp = tmp->type - 1;
            gen_artific(tmp);
        } else {
            tmp->object->rect.left = 0;
            tmp->hp = tmp->type + 1;
        }
        tmp = set_next_pos(game, tmp);
        anim_artific(tmp->artific, game->w, tmp);
        tmp = tmp->next;
    }
}
