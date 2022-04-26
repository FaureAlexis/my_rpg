/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_
    #include <math.h>
    #include "lib.h"
    #include "game_object.h"
    #include "button.h"
    #include "menu.h"
    #include "csfml.h"

    #define EPITECH_ERROR 84
    #define BUTTON_SOUND "assets/sounds/click.ogg"
    #define BUTTON_SS "assets/button/button_spritesheet.png"
    #define MENU_BG "assets/menu/main_menu.jpg"
    #define GAME_EX "assets/menu/game_example.jpg"
    #define SETTINGS_BG "assets/menu/settings_menu.png"
    #define SETTINGS_SS "assets/window/settings_sprite.png"
    #define SKIN_CUS_SS "assets/window/custom_menu.png"
    #define PLAYER_SS "assets/player/player.png"
    #define MAP_TXT "assets/map/world.txt"

    typedef struct volume_s {
        float volume;
        sfVector2f size;
        sfVector2f pos;
        sfRectangleShape *volume_rect;
    } vol_t;

    typedef struct skin_custom_s {
        sfRectangleShape *red;
        sfRectangleShape *green;
        sfRectangleShape *blue;
        sfVector2f pos_red;
        sfVector2f pos_green;
        sfVector2f pos_blue;
        sfUint8 red_c;
        sfUint8 green_c;
        sfUint8 blue_c;
        bool click_red;
        bool click_green;
        bool click_blue;
    } cus_t;

    typedef struct my_clock_s {
        sfClock *clock;
        sfTime time;
        float seconds;
    } my_clock_t;

    typedef struct obstacle_s {
        game_object_t *object;
        struct obstacle_s *next;
    } obstacle_t;

    typedef struct mobe_s {
        game_object_t *object;
        my_clock_t *my_clock;
        int hp;
        int power;
        int obj;
        struct mobe_s *next;
    }mobe_t;

    typedef struct map_s {
        char ***tab;
        obstacle_t *obstacle;
        mobe_t *mobe;
        game_object_t *map;
        game_object_t *back;
    } map_t;

    typedef struct player_s {
        scenes_name current_scene;
        scenes_name next_scene;
        int life;
        int attack;
        game_object_t *object;
        my_clock_t *p_clock;
    } player_t;

    typedef struct settings_s {
        int fps;
        int res_x;
        int res_y;
        sfText *fps_text;
    } settings_t;

    typedef struct main_game_s {
        sfRenderWindow *w;
        sfView *view;
        float view_zoom;
        sfVector2f view_pos;
        sfEvent event;
        vol_t *vol;
        cus_t *skin;
        btn_t *btn;
        mnu_t *mnu;
        player_t *player;
        map_t *map;
        settings_t *settings;
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

    typedef struct movements_s {
        sfKeyCode key;
        int height_ss;
        int flip;
    } movements_t;

/* Check environnement */

    int check_env(char **env);

/* Inits */

    player_t *init_player(void);
    main_game_t *init_game(void);
    map_t *init_map(void);
    sfRenderWindow *init_window(void);
    sfView *init_view(sfRenderWindow *window);
    my_clock_t *init_clock(void);
    int init_all(main_game_t *game);
    int init_button(button_t **button, sfVector2f position, int size,
    char **tab);
    int init_all_buttons(main_game_t *game);
    int init_button_shape(button_t **button, sfVector2f position, int size,
    char **tab);
    int init_skin_custom(cus_t **cus);
    int init_menu(menu_t **menu, char *theme, char *texture, sfIntRect rect);
    int init_volume(vol_t **vol);
    int init_menu(menu_t **menu, char *theme, char *texture, sfIntRect rect);

/*Map Management*/

    char *open_file(char const *filepath);
    char **my_str_to_word_array_pos(char const *str, char pos, int idx);
    char ***make_tab(char *filepath);
    int my_arraylen(char *const *array);
    void launch_rpg(char ***tab);
    void init_obstacle(map_t *map, char ***tab, int i);
    void init_mobe(map_t *map, char ***tab, int i);
    void display_obstacle(main_game_t *game);
    void display_mobe(main_game_t *game);
    obstacle_t *add_node_to_obstacle(obstacle_t *head, obstacle_t *node);
    mobe_t *add_node_to_mobe(mobe_t *head, mobe_t *node);
    void parse_tab(map_t *map, char ***tab, int i);

/*Animations*/

/*Player animations*/
        int player_animations(player_t *player);
        int player_check_key(sfKeyCode key);
        int set_player_movements(main_game_t *game, player_t *player,
        sfEvent event);
        void move_up(map_t *map);
        void move_down(map_t *map);
        void move_right(map_t *map);
        void move_left(map_t *map);

/*Menu management*/

/*Initalization*/
    sfRenderWindow *create_window(void);
    char **init_menu_rsc(char *sound, char *texture, char *texture_bg);
    char **init_button_rsc2(char *sound, char *texture);
    int create_menus(main_game_t *game);

/*Button Position*/
    void pos_button_settings(main_game_t *game);
    void pos_button_settings_two(main_game_t *game);
    void pos_button_pause(main_game_t *game);
    void pos_button_help(main_game_t *game);
    void pos_button_game(main_game_t *game);
    void pos_button_main(main_game_t *game);
    void pos_button_skin_cus(main_game_t *game);
    void pos_button_scoreboard(main_game_t *game);

/*Display*/

    int display_menu(main_game_t *game);
    int display_skin_cus(main_game_t *game);
    int display_game(main_game_t *game);
    int display_pause(main_game_t *game);
    int display_settings(main_game_t *game);
    int display_help(main_game_t *game);
    int display_score(main_game_t *game);
    int display_shop(main_game_t *game);
    int change_menu(main_game_t *game, sfRenderWindow *window, sfVector2i
    mouse_pos);
    int manage_volume_right(main_game_t *game, sfVector2i mouse_pos);
    int manage_volume_left(main_game_t *game, sfVector2i mouse_pos);
    int manage_fps_plus(main_game_t *game, sfVector2i mouse_pos);
    int display_fps(main_game_t *game);

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

    bool button_is_clicked(button_t *button, sfVector2i mouse_pos);
    bool shape_is_clicked(sfRectangleShape *shape, sfVector2i mouse_pos);
    void shape_red_clicked(main_game_t *game);
    void shape_green_clicked(main_game_t *game);
    void shape_blue_clicked(main_game_t *game);
    void clicked_state_game(main_game_t *game, sfRectangleShape *shape);
    void clicked_state_pause(main_game_t *game, sfRectangleShape *shape);
    void clicked_state_settings(main_game_t *game, sfRectangleShape *shape);
    void clicked_state_help(main_game_t *game, sfRectangleShape *shape);
    void clicked_state_main(main_game_t *game, sfRectangleShape *shape);
    void clicked_state_custom_skin(main_game_t *game, sfRectangleShape *shape);
    const event_t *get_event(sfEventType type, const event_t event_array[]);
    int event_skin_choice(main_game_t *game, sfVector2i mouse_pos);
    int close_window(main_game_t *game);

/* Scenes */

    int create_menus(main_game_t *game);
    const scenes_t *manage_scenes(sfKeyCode key, scenes_name name);
    int pause_scene(main_game_t *game);
    int main_menu_scene(main_game_t *game);
    int game_scene(main_game_t *game);
    int settings_scene(main_game_t *game);
    int help_scene(main_game_t *game);
    int skin_scene(main_game_t *game);

/* Free data */

    void free_game_struct(main_game_t *game);
    void destroy_all_button(main_game_t *game);
    void destroy_all_menu(main_game_t *game);
    void free_tab(char ***tab);

/* Main function */

    int rpg(int argc, const char * const *argv, char ** env);

    int set_rgb_right(main_game_t *game);
    int set_rgb_left(main_game_t *game);
    void set_rgb_shape(cus_t **cus);

#endif/* !RPG_H_ */
