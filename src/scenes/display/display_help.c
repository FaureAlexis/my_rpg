/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_help
*/

#include "rpg.h"

static int display_help_touch_text(main_game_t *game)
{
    if (!game || !game->help)
        return EPITECH_ERROR;
    sfText_setString(game->help->h_touch->up, resolve_key(game->keys->up));
    sfText_setString(game->help->h_touch->down, resolve_key(game->keys->down));
    sfText_setString(game->help->h_touch->right,
    resolve_key(game->keys->right));
    sfText_setString(game->help->h_touch->left, resolve_key(game->keys->left));
    sfText_setString(game->help->h_touch->inventory,
    resolve_key(game->keys->inventory));
    sfText_setString(game->help->h_touch->attack,
    resolve_key(game->keys->attack));
    sfRenderWindow_drawText(game->w, game->help->h_touch->up, NULL);
    sfRenderWindow_drawText(game->w, game->help->h_touch->down, NULL);
    sfRenderWindow_drawText(game->w, game->help->h_touch->right, NULL);
    sfRenderWindow_drawText(game->w, game->help->h_touch->left, NULL);
    sfRenderWindow_drawText(game->w, game->help->h_touch->inventory, NULL);
    sfRenderWindow_drawText(game->w, game->help->h_touch->attack, NULL);
    return EXIT_SUCCESS;
}

static int display_help_text(main_game_t *game)
{
    if (!game || !game->help)
        return EPITECH_ERROR;
    sfText_setString(game->help->goal_text, GAME_GOAL);
    sfText_setString(game->help->help_text, GAME_HELP);
    sfRenderWindow_drawText(game->w, game->help->goal_text, NULL);
    sfRenderWindow_drawText(game->w, game->help->help_text, NULL);
    sfRenderWindow_drawText(game->w, game->help->up, NULL);
    sfRenderWindow_drawText(game->w, game->help->down, NULL);
    sfRenderWindow_drawText(game->w, game->help->right, NULL);
    sfRenderWindow_drawText(game->w, game->help->left, NULL);
    sfRenderWindow_drawText(game->w, game->help->inventory, NULL);
    sfRenderWindow_drawText(game->w, game->help->attack, NULL);
    return display_help_touch_text(game);
}

int display_help(main_game_t *game)
{
    if (!game || !game->help)
        return EPITECH_ERROR;
    pos_button_help(game);
    sfRenderWindow_drawSprite(game->w,
    game->mnu->help_play->bg_object->sprite, NULL);
    sfRenderWindow_drawSprite(game->w,
    game->mnu->help_play->object->sprite, NULL);
    sfRenderWindow_drawSprite(game->w,
    game->btn->big->return_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->big->exit_b->sprite, NULL);
    return display_help_text(game);
}
