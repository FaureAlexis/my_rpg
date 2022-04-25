/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** custom_skin
*/

#include "rpg.h"

static int red_right(main_game_t *g)
{
    sfVector2f size = sfRectangleShape_getSize(g->skin->red);

    if (size.x < 400 && g->skin->red_c < 242.25) {
        g->skin->red_c += 12.75;
        sfRectangleShape_setSize(g->skin->red,
        (sfVector2f){size.x + 20, size.y});
    }
    sfSprite_setColor(g->player->object->sprite,
    sfColor_fromRGB(g->skin->red_c, g->skin->green_c, g->skin->blue_c));
    return 0;
}

static int green_right(main_game_t *g)
{
    sfVector2f size = sfRectangleShape_getSize(g->skin->green);

    if (size.x < 400 && g->skin->green_c < 242.25) {
        g->skin->green_c += 12.75;
        sfRectangleShape_setSize(g->skin->green,
        (sfVector2f){size.x + 20, size.y});
    }
    sfSprite_setColor(g->player->object->sprite,
    sfColor_fromRGB(g->skin->red_c, g->skin->green_c, g->skin->blue_c));
    return 0;
}

static int blue_right(main_game_t *g)
{
    sfVector2f size = sfRectangleShape_getSize(g->skin->blue);

    if (size.x < 400 && g->skin->blue_c < 242.25) {
        g->skin->blue_c += 12.75;
        sfRectangleShape_setSize(g->skin->blue,
        (sfVector2f){size.x + 20, size.y});
    }
    sfSprite_setColor(g->player->object->sprite,
    sfColor_fromRGB(g->skin->red_c, g->skin->green_c, g->skin->blue_c));
    return 0;
}

int set_rgb_right(main_game_t *game)
{
    if (game->skin->click_red == true)
        red_right(game);
    if (game->skin->click_green == true)
        green_right(game);
    if (game->skin->click_blue == true)
        blue_right(game);
    return 0;
}
