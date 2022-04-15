/*
** EPITECH PROJECT, 2022
** game_object
** File description:
** game_object
*/

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_
    #include "csfml.h"

    typedef struct game_object_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f position;
        sfVector2f scale;
        sfIntRect rect;
    } game_object_t;

#endif /* !GAME_OBJECT_H_ */
