/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** rpg
*/

#include <math.h>
#include "lib.h"
#include "csfml.h"

#ifndef RPG_H_
    #define RPG_H_
    #define EPITECH_ERROR 84
    #define BUTTON_SOUND "assets/sounds/click.ogg"
    #define BUTTON_SS "assets/button/button_spritesheet.png"
    #define MENU_BG "assets/menu/main_menu.jpg"

    typedef enum button_size_s {
        SMALL,
        MEDIUM,
        LARGE
    } bt_size_t;

    typedef struct menu_s {
        sfMusic *theme;
        sfIntRect rect;
        sfSprite *sprite;
        sfTexture *texture;
        sfSprite *bg_sprite;
        sfTexture *bg_texture;
    } menu_t;

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

    typedef struct volume_s {
        float volume;
        sfVector2f size;
        sfVector2f pos;
        sfRectangleShape *volume_rect;
    } vol_t;

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
    } sml_btn_t;

    typedef struct all_buttons_s {
        big_btn_t *big;
        mid_btn_t *mid;
        sml_btn_t *sml;
    } btn_t;

    typedef struct all_menu_s {
        menu_t *main;
        menu_t *shop;
        menu_t *scoreboard;
        menu_t *gameplay;
        menu_t *settings;
        menu_t *help_play;
        menu_t *pause_m;
    } mnu_t;

    typedef enum {
        UNKNOWN_SCENE = -1,
        MENU_SCENE,
        GAME_SCENE,
        PAUSE_SCENE
    } scenes_name;

    typedef struct player_s {
        scenes_name current_scene;
        scenes_name next_scene;
        int life;
        int attack;
    } player_t;

    typedef struct main_game_s {
        sfRenderWindow *window;
        sfEvent event;
        vol_t *vol;
        btn_t *btn;
        mnu_t *mnu;
        player_t *player;
    } main_game_t;

    typedef struct event_s {
        sfEventType type;
        int (*events)(main_game_t *);
    } event_t;

    typedef struct scenes_s {
        sfKeyCode key;
        scenes_name name;
        int (*go_scene)(main_game_t *);
    } scenes_t;

    /* Check environnement */

    int check_env(char **env);

    /* Inits */
    player_t *init_player(void);
    main_game_t *init_game(void);
    sfRenderWindow *init_window(void);
    int init_all(main_game_t *game);
    int init_button(button_t **button, sfVector2f position, int size,
    char **tab);
    int init_all_buttons(main_game_t *game);
    int init_button_shape(button_t **button, sfVector2f position, int size,
    char **tab);
    int init_menu(menu_t **menu, char *theme, char *texture, sfIntRect rect);
    int init_volume(vol_t **vol);
    int init_menu(menu_t **menu, char *theme, char *texture, sfIntRect rect);

    /*Menu management*/
        /*Initalization*/
    sfRenderWindow *create_window(void);
    char **init_menu_rsc(char *sound, char *texture, char *texture_bg);
    char **init_button_rsc2(char *sound, char *texture);
    int create_menus(main_game_t *game);
        /*Button Position*/
    void pos_button_settings(sfRenderWindow *window, main_game_t *game);
    void pos_button_pause(sfRenderWindow *window, main_game_t *game);
    void pos_button_game(sfRenderWindow *window, main_game_t *game);
    void pos_button_main(sfRenderWindow *window, main_game_t *game);
    void pos_button_scoreboard(sfRenderWindow *window, main_game_t *game);;
        /*Display*/
    int display_menu(sfRenderWindow *window, main_game_t *game);
    int display_game(sfRenderWindow *window, main_game_t *game);
    int display_pause_menu(sfRenderWindow *window, main_game_t *game);
    int display_settings(sfRenderWindow *window, main_game_t *game);
    int display_help_menu(sfRenderWindow *window, main_game_t *game);
    int display_score_menu(sfRenderWindow *window, main_game_t *game);
    int display_shop(sfRenderWindow *window, main_game_t *game);
    int change_menu(main_game_t *game, sfRenderWindow *window, sfVector2i
    mouse_pos);
    int manage_volume_right(main_game_t *game, sfVector2i mouse_pos);

    /*Button management*/
        /*Create*/
    int create_all_big_buttons(main_game_t *game);
    int create_all_medium_buttons(main_game_t *game);
    int create_all_small_buttons(main_game_t *game);
    int create_all_buttons(main_game_t *game);
        /*Set Rect*/
    void set_rect_big_buttons(main_game_t *game);
    void set_rect_mid_buttons(main_game_t *game);
    void set_rect_mid_buttons2(main_game_t *game);
    void set_rect_small_buttons(main_game_t *game);
    void set_rect_all_buttons(main_game_t *game);
        /*Hover*/
    int manage_hover_big_buttons(main_game_t *game, sfVector2i mouse_pos);
    int manage_hover_medium_buttons(main_game_t *game, sfVector2i mouse_pos);
    int manage_hover_small_buttons(main_game_t *game, sfVector2i mouse_pos);
    void manage_all_hover(main_game_t *game, sfVector2i mouse_pos);
    int button_action_menu(sfRenderWindow *window, main_game_t *game,
    sfVector2i mouse_pos);
    int button_action_game(sfRenderWindow *window, main_game_t *game,
    sfVector2i mouse_pos);
    int button_action_pause(sfRenderWindow *window, main_game_t *game,
    sfVector2i mouse_pos);
    int button_action_help(sfRenderWindow *window, main_game_t *game,
    sfVector2i mouse_pos);
    int button_action_settings(sfRenderWindow *window, main_game_t *game,
    sfVector2i mouse_pos);
    int button_action_scoreboard(sfRenderWindow *window, main_game_t *game,
    sfVector2i mouse_pos);
    int manage_hover_buttons(main_game_t *game, sfVector2i mouse_pos);
    int manage_hover(button_t *button, sfVector2i mouse_pos);

    /* Events */

    const event_t *get_event(sfEventType type, const event_t event_array[]);
    int close_window(main_game_t *game);

    /* Scenes */

    const scenes_t *manage_scenes(sfKeyCode key, scenes_name name);
    int pause_scene(main_game_t *game);
    int main_menu_scene(main_game_t *game);

    /* Free data */

    void free_game_struct(main_game_t *game);

    /* Main function */

    int rpg(int argc, const char * const *argv, char ** env);

#endif /* !RPG_H_ */
