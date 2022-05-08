/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_main_menu
*/

#include "rpg.h"

void display_interaction(main_game_t *game)
{
    int index = game->player->nb_interactions;
    char *sentence = my_strdup(game->player->scenario[index]);

    if (game->player->interaction)
        sfText_setString(game->player->interaction_text, sentence);
    else
        sfText_setString(game->player->interaction_text, "");
}

static int check_inventory(main_game_t *game)
{
    if (game->inv_open == true) {
        sfSprite_setScale(game->mnu->gameplay->object->sprite, INV_SIZE);
        sfSprite_setPosition(game->mnu->gameplay->object->sprite, INV_POS);
        sfRenderWindow_drawSprite(game->w,
        game->mnu->gameplay->object->sprite, NULL);
    }
    return EXIT_SUCCESS;
}

static int display_inventory(main_game_t *game)
{
    if (game->inv_open == true && game->player->life > 0) {
        sfSprite_setScale(game->mnu->gameplay->object->sprite, INV_SIZE);
        sfSprite_setPosition(game->mnu->gameplay->object->sprite, INV_POS);
        sfRenderWindow_drawSprite(game->w, game->mnu->gameplay->object->sprite,
        NULL);
        sfRenderWindow_drawText(game->w, game->player->life_txt, NULL);
        sfRenderWindow_drawText(game->w, game->player->atk_txt, NULL);
    }
    return EXIT_SUCCESS;
}

int display_game(main_game_t *game)
{
    pos_button_game(game);
    sfRenderWindow_drawSprite(game->w, game->map->back->sprite, NULL);
    sfSprite_setPosition(game->map->map->sprite, game->map->map->position);
    sfRenderWindow_drawSprite(game->w, game->map->map->sprite, NULL);
    display_mob(game);
    game->player->dust = anim_dust(game->player->dust, game->w);
    sfRenderWindow_drawSprite(game->w, game->player->object->sprite, NULL);
    display_speobstacle(game);
    display_obstacle(game);
    display_interaction(game);
    sfRenderWindow_drawText(game->w, game->player->interaction_text, NULL);
    sfRenderWindow_drawSprite(game->w, game->btn->mid->pause_b->sprite, NULL);
    sfRenderWindow_drawText(game->w, game->player->interaction_text, NULL);
    check_inventory(game);
    sfRenderWindow_drawRectangleShape(game->w, game->player->life_bar, NULL);
    display_inventory(game);
    return EXIT_SUCCESS;
}
