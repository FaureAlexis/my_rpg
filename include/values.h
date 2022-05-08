/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** values
*/

#ifndef VALUES_H_
    #include "button_value.h"
    #define VALUES_H_
    #define EPITECH_ERROR 84
    #define ASSET 0
    #define CORD_X 1
    #define CORD_Y 2
    #define REC_LEFT 3
    #define REC_TOP 4
    #define REC_WIDTH 5
    #define REC_HEIGHT 6
    #define HP 7
    #define POWER 8
    #define TYPE 9
    #define MAP_X_MIN -3098
    #define MAP_X_MAX 922
    #define MAP_Y_MIN -3403
    #define MAP_Y_MAX 607
    #define X_MIN -3088
    #define X_MAX 912
    #define Y_MIN -3393
    #define Y_MAX 597
    #define INV_CASE_MAX_X 3550
    #define INV_CASE_MAX_Y 2445
    #define INV_CASE_X 2540
    #define INV_CASE_Y 795
    #define INV_CASE_OFFSET 310
    #define INV_CASE_SPACE 20
    #define INV_CASE_NB 15
    #define SECONDS 1000000.0
    #define CLOCK_LIMIT 0.2
    #define CLOCK_LIMIT_ATK 0.08
    #define MIN_COLOR 12.75
    #define MAX_COLOR 242.25
    #define OFFSET_COLOR 12.75
    #define MV_UP (sfVector2f){0, 10}
    #define MV_DOWN (sfVector2f){0, -10}
    #define MV_RIGHT (sfVector2f){-10, 0}
    #define MV_LEFT (sfVector2f){10, 0}
    #define MAX_ZOOM 0.5
    #define MIN_ZOOM 1.2
    #define ZOOM_OFFSET 0.1
    #define ZOOM 0.9
    #define UNZOOM 1.2
    #define MAX_W_X 1920
    #define MIN_W_X 1440
    #define MAX_W_Y 1080
    #define DUST_COLOR (sfColor){153, 150, 146, 180}
    #define SPEOBS_COLOR 0, 220, 200, 100
    #define GOAL_TXT_POS (sfVector2f){550, 20}
    #define HELP_TXT_POS (sfVector2f){940, 150}
    #define INTERACT_TXT_POS (sfVector2f){700, 1000}
    #define RED_HITBOX 255, 0, 0, 100
    #define GREEN_HITBOX 0, 255, 0, 100
    #define BLUE_HITBOX 0, 0, 255, 100
    #define GAME_BG_COLOR 80,155,102
    #define PLAYER_POS (sfVector2f){960, 600}
    #define PLAYER_SCALE (sfVector2f){4, 4}
    #define PLAYER_SCALE_GAME (sfVector2f){8, 8}
    #define PLAYER_RECT (sfIntRect){0, 0, 48, 48}
    #define PLAYER_ORIGIN (sfVector2f){24, 24}
    #define RES_TXT (sfVector2f){1060, 450}
    #define FPS_TXT (sfVector2f){1100, 600}
    #define CUS_RECT_SIZE (sfVector2f){400, 30}
    #define RED_POS (sfVector2f){850, 400}
    #define GREEN_POS (sfVector2f){850, 460}
    #define BLUE_POS (sfVector2f){850, 520}
    #define VOL_POS (sfVector2f){575, 320}
    #define VOL_SIZE (sfVector2f){(700 / 10), 30}
    #define VOL_OUTLINE_SIZE (sfVector2f){700, 30}
    #define ICON_WIDTH 514
    #define ICON_HEIGHT 528
    #define INIT_RECT_MENU (sfIntRect){200, 200, 0, 0}
    #define INIT_RECT_MENU2 (sfIntRect){0, 0, 0, 0}
    #define INV_SIZE (sfVector2f){0.3, 0.3}
    #define INV_POS (sfVector2f){80, 100}
    #define MENU_BG_SIZE (sfVector2f){0.28, 0.28}
    #define SETTINGS_BG_POS (sfVector2f){100, 10}
    #define SKIN_CUS_BG_POS  (sfVector2f){100, -10}
    #define PLAYER_POS_SKIN_CUS (sfVector2f){600, 435}
    #define MIN_FPS 30
    #define MAX_FPS 120
    #define FPS_OFFSET 30
    #define VIEW_SIZE (sfFloatRect){0, 0, 1920, 1080}
    #define HELP_UP (sfVector2f){600, 300}
    #define HELP_DOWN (sfVector2f){600, 400}
    #define HELP_ATTACK (sfVector2f){600, 500}
    #define HELP_RIGHT (sfVector2f){1050, 300}
    #define HELP_LEFT (sfVector2f){1050, 400}
    #define HELP_INVENTORY (sfVector2f){1050, 500}
    #define TOUCH_UP (sfVector2f){800, 300}
    #define TOUCH_DOWN (sfVector2f){800, 400}
    #define TOUCH_ATTACK (sfVector2f){800, 500}
    #define TOUCH_RIGHT (sfVector2f){1300, 300}
    #define TOUCH_LEFT (sfVector2f){1300, 400}
    #define TOUCH_INVENTORY (sfVector2f){1300, 500}

#endif /* !VALUES_H_ */
