/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** custom_skin
*/

#include "rpg.h"

static int red_left(main_game_t *g)
{
    sfVector2f size = sfRectangleShape_getSize(g->skin->red);

    if (size.x > 0 && g->skin->red_c > 12.75) {
        g->skin->red_c -= 12.75;
        sfRectangleShape_setSize(g->skin->red,
        (sfVector2f){size.x - 20, size.y});
    }
    sfSprite_setColor(g->player->object->sprite,
    sfColor_fromRGBA(g->skin->red_c, g->skin->green_c, g->skin->blue_c, 255));
    return EXIT_SUCCESS;
}

static int green_left(main_game_t *g)
{
    sfVector2f size = sfRectangleShape_getSize(g->skin->green);

    if (size.x > 0 && g->skin->green_c > 12.75) {
        g->skin->green_c -= 12.75;
        sfRectangleShape_setSize(g->skin->green,
        (sfVector2f){size.x - 20, size.y});
    }
    sfSprite_setColor(g->player->object->sprite,
    sfColor_fromRGBA(g->skin->red_c, g->skin->green_c, g->skin->blue_c, 255));
    return EXIT_SUCCESS;
}

static int blue_left(main_game_t *g)
{
    sfVector2f size = sfRectangleShape_getSize(g->skin->blue);

    if (size.x > 0 && g->skin->blue_c > 12.75) {
        g->skin->blue_c -= 12.75;
        sfRectangleShape_setSize(g->skin->blue,
        (sfVector2f){size.x - 20, size.y});
    }
    sfSprite_setColor(g->player->object->sprite,
    sfColor_fromRGBA(g->skin->red_c, g->skin->green_c, g->skin->blue_c, 255));
    return EXIT_SUCCESS;
}

int set_rgb_left(main_game_t *game)
{
    if (game->skin->click_red == true)
        red_left(game);
    if (game->skin->click_green == true)
        green_left(game);
    if (game->skin->click_blue == true)
        blue_left(game);
    return EXIT_SUCCESS;
}
