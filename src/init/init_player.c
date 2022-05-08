/*
** EPITECH PROJECT, 2022
** init_player
** File description:
** init_player
*/

#include "rpg.h"

static player_t *set_player_stats(player_t *player)
{
    if (!player)
        return NULL;
    player->life = 20;
    player->attack = 5;
    player->attack_action = 0;
    player->dust = NULL;
    player->object->position = PLAYER_POS;
    player->object->scale = PLAYER_SCALE;
    player->object->rect = PLAYER_RECT;
    return player;
}

static int set_sound_effect(player_t *player)
{
    if (!player)
        return EPITECH_ERROR;
    player->walk = sfMusic_createFromFile(WALK_SOUND);
    player->death = sfMusic_createFromFile(DEATH_SOUND);
    player->sword = sfMusic_createFromFile(SWORD_USING_SOUND);
    if (player->walk == NULL || player->death == NULL || player->sword == NULL)
        return EPITECH_ERROR;
    sfMusic_setLoop(player->walk, true);
    return EXIT_SUCCESS;
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

static int init_text_interaction(player_t *player)
{
    sfFont *gravity = sfFont_createFromFile("./assets/font/fs-gravity.ttf");

    if (!gravity)
        return EPITECH_ERROR;
    player->interaction_text = sfText_create();
    if (!player->interaction_text)
        return EPITECH_ERROR;
    sfText_setFont(player->interaction_text, gravity);
    sfText_setCharacterSize(player->interaction_text, 40);
    sfText_setColor(player->interaction_text, sfWhite);
    sfText_setPosition(player->interaction_text, INTERACT_TXT_POS);
    return EXIT_SUCCESS;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->object = malloc(sizeof(game_object_t));
    if (!player->object)
        return NULL;
    player = set_player_stats(player);
    if (!player)
        return NULL;
    player->p_clock = init_clock();
    if (!player->p_clock)
        return NULL;
    player->interaction = 0;
    init_text_interaction(player);
    if (!player->interaction_text)
        return NULL;
    player->object->texture = sfTexture_createFromFile(PLAYER_SS, NULL);
    player->object->sprite = sfSprite_create();
    if (!player->object->texture || !player->object->sprite)
        return NULL;
    if (set_sprite(player) == EPITECH_ERROR)
        return NULL;
    return player;
}
