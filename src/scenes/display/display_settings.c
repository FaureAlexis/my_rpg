/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_settings
*/

#include "rpg.h"

int display_fps(main_game_t *game)
{
    char *fps_txt = my_int_to_str(game->settings->fps);

    sfText_setString(game->settings->fps_text, fps_txt);
    sfRenderWindow_drawText(game->w, game->settings->fps_text, NULL);
    return EXIT_SUCCESS;
}

int display_resolution(main_game_t *game)
{
    char *x_txt = my_int_to_str(game->settings->res_x);
    char *y_txt = my_int_to_str(game->settings->res_y);

    my_strcat(x_txt, "x");
    my_strcat(x_txt, y_txt);
    sfText_setString(game->settings->res_text, x_txt);
    sfRenderWindow_drawText(game->w, game->settings->res_text, NULL);
    return display_fps(game);
}

int display_settings2(main_game_t *gme)
{
    sfRenderWindow_drawSprite(gme->w, gme->btn->sml->plus_r_b->sprite, NULL);
    sfRenderWindow_drawSprite(gme->w, gme->btn->sml->minus_r_b->sprite, NULL);
    sfRenderWindow_drawSprite(gme->w, gme->btn->mid->help_b->sprite, NULL);
    sfRenderWindow_drawSprite(gme->w, gme->btn->mid->keybind_b->sprite, \
    NULL);
    sfRenderWindow_drawSprite(gme->w, gme->btn->mid->mute_b->sprite, NULL);
    sfRenderWindow_drawSprite(gme->w, gme->btn->mid->unmute_b->sprite, NULL);
    sfRenderWindow_drawSprite(gme->w, gme->btn->big->return_b->sprite, NULL);
    sfRenderWindow_drawSprite(gme->w, gme->btn->big->exit_b->sprite, NULL);
    display_resolution(gme);

    return EXIT_SUCCESS;
}

int display_settings(main_game_t *game)
{
    sfSprite_setScale(game->mnu->settings->object->sprite, MENU_BG_SIZE);
    sfSprite_setPosition(game->mnu->settings->object->sprite, SETTINGS_BG_POS);
    pos_button_settings(game);
    sfRenderWindow_drawSprite(game->w, \
    game->mnu->settings->bg_object->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->mnu->settings->object->sprite, \
    NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->sml->right_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->sml->left_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->sml->plus_b->sprite, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->sml->minus_b->sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->w, game->vol->thickness, NULL);
    sfRenderWindow_drawRectangleShape(game->w, game->vol->volume_rect, NULL);
    display_settings2(game);
    return EXIT_SUCCESS;
}
