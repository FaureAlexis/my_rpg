/*
** EPITECH PROJECT, 2022
** button
** File description:
** button
*/

#ifndef BUTTON_H_
#define BUTTON_H_
    #include "csfml.h"

    typedef enum button_size_s {
        SMALL,
        MEDIUM,
        LARGE
    } bt_size_t;

    typedef struct button_s {
        int bsize;
        sfMusic *sound;
        sfVector2f position;
        sfVector2f size;
        sfVector2f sprite_pos;
        sfRectangleShape *shape;
        sfSprite *sprite;
        sfTexture *texture;
    } button_t;

    typedef struct big_button_s {
        button_t *score_b;
        button_t *resume_b;
        button_t *help_b;
        button_t *settings_b;
        button_t *return_b;
        button_t *play_b;
        button_t *exit_b;
    } big_btn_t;

    typedef struct medium_button_s {
        button_t *main_b;
        button_t *top_sc_b;
        button_t *save_b;
        button_t *pause_b;
        button_t *right_b;
        button_t *mute_b;
        button_t *help_b;
        button_t *settings_b;
        button_t *exit_b;
        button_t *resume_b;
        button_t *left_b;
        button_t *unmute_b;
    } mid_btn_t;

    typedef struct small_button_s {
        button_t *plus_b;
        button_t *minus_b;
        button_t *talk_b;
        button_t *accept_b;
        button_t *deny_b;
        button_t *left_b;
        button_t *right_b;
        button_t *top_b;
        button_t *bot_b;
        button_t *plus_r_b;
        button_t *minus_r_b;
    } sml_btn_t;

    typedef struct all_buttons_s {
        big_btn_t *big;
        mid_btn_t *mid;
        sml_btn_t *sml;
    } btn_t;

#endif /* !BUTTON_H_ */
