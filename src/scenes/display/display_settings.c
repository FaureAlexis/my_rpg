/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_settings
*/

#include "rpg.h"

int display_settings(main_game_t *game)
{
    sfSprite_setScale(game->mnu->settings->object->sprite, (sfVector2f){0.28, 0.28});
    sfSprite_setPosition(game->mnu->settings->object->sprite, (sfVector2f){100, 10});
    pos_button_settings(game);
    sfRenderWindow_drawSprite(game->w, game->mnu->settings->bg_object->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->mnu->settings->object->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->help_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->return_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->exit_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->sml->right_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->sml->left_b->sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->w, game->vol->volume_rect, NULL);
    return EXIT_SUCCESS;
}
