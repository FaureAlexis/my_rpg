/*
** EPITECH PROJECT, 2022
** init_player
** File description:
** init_player
*/

#include "rpg.h"

static int set_text_settings(player_t *player, sfFont *gravity)
{
    char *atk_str = my_int_to_str(player->attack);
    char *life_str = my_int_to_str(player->life);

    if (!player || !gravity)
        return EPITECH_ERROR;
    sfText_setPosition(player->life_txt, LIFE_TXT);
    sfText_setCharacterSize(player->life_txt, 58);
    sfText_setColor(player->life_txt, sfWhite);
    sfText_setFont(player->life_txt, gravity);
    sfText_setString(player->life_txt, life_str);
    sfText_setPosition(player->atk_txt, ATK_TXT);
    sfText_setCharacterSize(player->atk_txt, 58);
    sfText_setColor(player->atk_txt, sfWhite);
    sfText_setFont(player->atk_txt, gravity);
    sfText_setString(player->atk_txt, atk_str);
    if (init_life_bar_player(player) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

static player_t *set_player_stats(player_t *player)
{
    sfFont *gravity = NULL;

    if (!player)
        return NULL;
    player->life = 200;
    player->attack = 5;
    player->attack_action = 0;
    player->dust = NULL;
    player->boss_defeated = false;
    player->object->position = PLAYER_POS;
    player->object->scale = PLAYER_SCALE;
    player->object->rect = PLAYER_RECT;
    player->life_txt = sfText_create();
    player->atk_txt = sfText_create();
    gravity = sfFont_createFromFile(TEXT_FONT);
    if (!player->life_txt || !player->atk_txt || !gravity)
        return NULL;
    set_text_settings(player, gravity);
    return player;
}

static int set_sprite(player_t *player)
{
    if (!player || set_sound_effect(player) == EPITECH_ERROR)
        return EPITECH_ERROR;
    sfSprite_setOrigin(player->object->sprite, PLAYER_ORIGIN);
    sfSprite_setTexture(player->object->sprite, player->object->texture,
    sfTrue);
    sfSprite_setTextureRect(player->object->sprite, player->object->rect);
    sfSprite_setScale(player->object->sprite, player->object->scale);
    sfSprite_setPosition(player->object->sprite, player->object->position);
    player->hitbox = sfSprite_getGlobalBounds(player->object->sprite);
    player->hitbox_shape = sfRectangleShape_create();
    if (!player->hitbox_shape)
        return EPITECH_ERROR;
    sfRectangleShape_setSize(player->hitbox_shape,
    (sfVector2f){player->hitbox.width / 2.8, player->hitbox.height / 2.5});
    sfRectangleShape_setPosition(player->hitbox_shape,
    (sfVector2f){player->object->position.x - 35,
    player->object->position.y - 5});
    sfRectangleShape_setFillColor(player->hitbox_shape,
    sfColor_fromRGBA(BLUE_HITBOX));
    return EXIT_SUCCESS;
}

static char **init_scenario(void)
{
    char **scenario = malloc(sizeof(char *) * 5);
    char *sentence1 =
        "Bienvenue dans ce monde ou votre\nquete sera de battre Hasbullah";
    char *sentence2 =
        "Pour le combattre vous devrez\nd'abord trouver la cle d'un \
        \ncoffre dans un squelette";
    char *sentence3 =
        "Puis chasser un slime rouge pour\ntrouver la cle qui vous menera \
        \na hasbullah";

    if (!scenario)
        return NULL;
    scenario[0] = my_strdup("Press E to interact with Mr Hood");
    scenario[1] = my_strdup(sentence1);
    scenario[2] = my_strdup(sentence2);
    scenario[3] = my_strdup(sentence3);
    scenario[4] = NULL;
    return scenario;
}

static int init_text_interaction(player_t *player)
{
    sfFont *gravity = sfFont_createFromFile("./assets/font/fs-gravity.ttf");

    if (!gravity)
        return EPITECH_ERROR;
    player->interaction_text = sfText_create();
    if (!player->interaction_text)
        return EPITECH_ERROR;
    sfText_setFont(player->interaction_text, gravity);
    sfText_setCharacterSize(player->interaction_text, 35);
    sfText_setColor(player->interaction_text, sfWhite);
    sfText_setPosition(player->interaction_text, INTERACT_TXT_POS);
    player->object->texture = sfTexture_createFromFile(PLAYER_SS, NULL);
    player->object->sprite = sfSprite_create();
    player->scenario = init_scenario();
    return EXIT_SUCCESS;
}

player_t *init_player(void)
{
    player_t *p = malloc(sizeof(player_t));

    if (!p)
        return NULL;
    p->object = malloc(sizeof(game_object_t));
    if (!p->object)
        return NULL;
    p = set_player_stats(p);
    if (!p)
        return NULL;
    p->p_clock = init_clock();
    if (!p->p_clock)
        return NULL;
    p->interaction = 0;
    p->nb_interactions = 0;
    init_text_interaction(p);
    if (!p->interaction_text)
        return NULL;
    p->interaction = 0;
    init_text_interaction(p);
    if (!p->object->texture || !p->object->sprite || !p->interaction_text)
        return NULL;
    if (set_sprite(p) == EPITECH_ERROR)
        return NULL;
    return p;
}
