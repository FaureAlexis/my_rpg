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
    #include "assets.h"
    #include "keys.h"
    #include "values.h"

    typedef struct volume_s {
        float volume;
        sfVector2f size;
        sfVector2f pos;
        sfRectangleShape *volume_rect;
        sfRectangleShape *thickness;
    } vol_t;

    typedef struct skin_custom_s {
        sfRectangleShape *red;
        sfRectangleShape *green;
        sfRectangleShape *blue;
        sfVector2f size;
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
        sfFloatRect hitbox;
        sfRectangleShape *hitbox_shape;
        struct obstacle_s *next;
    } obstacle_t;

    typedef struct particles_s {
        sfVector2f cord;
        sfVector2f direction;
        my_clock_t *timer;
        int size;
        float end;
        float y;
        sfUint8 *pixels;
        sfRectangleShape *shape;
        sfTexture *texture;
        sfColor color;
        struct particles_s *next;
    } particles_t;

    typedef struct speobstacle_s {
        game_object_t *object;
        sfFloatRect hitbox;
        sfRectangleShape *hitbox_shape;
        int hp;
        int type;
        particles_t *artific;
        struct speobstacle_s *next;
    } speobstacle_t;

    typedef struct mobe_s {
        game_object_t *object;
        game_object_t *item;
        sfFloatRect hitbox;
        sfRectangleShape *hitbox_shape;
        my_clock_t *my_clock;
        my_clock_t *attack_clock;
        bool attack;
        int hp;
        int power;
        int obj;
        int type;
        bool dead;
        struct mobe_s *next;
    } mobe_t;

    typedef struct map_s {
        char ***tab;
        speobstacle_t *speobstacle;
        obstacle_t *obstacle;
        mobe_t *mobe;
        game_object_t *map;
        game_object_t *back;
        my_clock_t *artificlock;
    } map_t;

    typedef struct player_s {
        scenes_name current_scene;
        scenes_name next_scene;
        int life;
        int attack;
        sfFloatRect hitbox;
        sfRectangleShape *hitbox_shape;
        game_object_t *object;
        my_clock_t *p_clock;
        particles_t *dust;
        bool attack_action;
        sfMusic *walk;
        sfMusic *death;
        sfMusic *sword;
    } player_t;

    typedef struct settings_s {
        int fps;
        int res_x;
        int res_y;
        sfText *fps_text;
        sfText *res_text;
    } settings_t;

    typedef struct help_touch_s {
        sfText *up;
        sfText *down;
        sfText *right;
        sfText *left;
        sfText *inventory;
        sfText *attack;
    } help_touch_t;

    typedef struct help_s {
        sfText *goal_text;
        sfText *help_text;
        sfText *up;
        sfText *down;
        sfText *right;
        sfText *left;
        sfText *inventory;
        sfText *attack;
        help_touch_t *h_touch;
    } help_t;

    typedef struct armor_s {
        game_object_t *object;
        struct armor_s *next;
    } armor_t;

    typedef struct case_inventory_s {
        int x;
        int y;
        game_object_t *object;
        struct case_inventory_s *next;
    } case_inventory_t;

    typedef struct inventory_s {
        bool inv_open;
        int armor_x;
        int armor_y;
        int offset_armor;
        int nb_armor;
        int case_inventory_max_x;
        int case_inventory_max_y;
        int case_inventory_x;
        int case_inventory_y;
        int offset_case_inventory;
        int space_case;
        int nb_case_inventory;
        armor_t *armor;
        case_inventory_t *case_inventory;
    } inventory_t;

    typedef struct main_game_s {
        sfRenderWindow *w;
        sfView *game_view;
        sfView *basic_view;
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
        help_t *help;
        int menu_depth;
        inventory_t *inventory;
        bool inv_open;
        keys_t *keys;
    } main_game_t;

    typedef struct event_s {
        sfEventType type;
        int index;
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
    int manage_errors(const int argc, char **env);

    /* Inits */

    player_t *init_player(void);
    main_game_t *init_game(void);
    map_t *init_map(void);
    int init_inventory(main_game_t *game);
    int init_settings(main_game_t *game);
    int init_help(main_game_t *game);
    sfRenderWindow *init_window(void);
    sfView *init_view(sfRenderWindow *window, sfFloatRect size);
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
    particles_t *creat_particles(int enum_type, sfVector2f cord, int size,
    sfVector2f direction);
    int draw_circle(particles_t *particle, int radius, sfColor color);
    void gen_artific(speobstacle_t *speobstacle);
    int init_keys(main_game_t *game);

        /*Map Management*/

    char *open_file(char const *filepath);
    char **my_str_to_word_array_pos(char const *str, char pos, int idx);
    char ***make_tab(char const *filepath);
    int my_arraylen(char *const *array);
    void launch_rpg(char ***tab);
    int init_obstacle(map_t *map, char ***tab, int i);
    int init_mob(map_t *map, char ***tab, int i);
    int init_speobstacle(map_t *map, char ***tab, int i);
    void display_speobstacle(main_game_t *game);
    void display_obstacle(main_game_t *game);
    void display_mob(main_game_t *game);
    void display_skeleton(mobe_t *tmp, main_game_t *game);
    void display_slime(mobe_t *tmp, main_game_t *game);
    void display_hasbulla(mobe_t *hasbulla, main_game_t *game);
    speobstacle_t *add_node_to_speobstacle(speobstacle_t *head,
    speobstacle_t *node);
    obstacle_t *add_node_to_obstacle(obstacle_t *head, obstacle_t *node);
    mobe_t *add_node_to_mobe(mobe_t *head, mobe_t *node);
    int parse_tab(map_t *map, char ***tab, int i);
    void mob_action_move(mobe_t *mob, player_t *player);
    void attack_slime(mobe_t *mob, player_t *player);
    void attack_skeleton(mobe_t *mob, player_t *player);
    void hasbulla_attack(mobe_t *mob, player_t *player);
        /*Collision*/
    int set_big_tree_hitbox(obstacle_t *tmp);
    int set_long_tree_hitbox(obstacle_t *tmp);
    int set_small_tree_hitbox(obstacle_t *tmp);
    int set_log_hitbox(obstacle_t *tmp);
    bool player_obstacle_collision(main_game_t *game, sfVector2f next);
    bool all_player_obstacle_collision(main_game_t *game);
    bool mob_obstacle_collision(main_game_t *game, sfVector2f next);

    /*Animations*/

    particles_t *anim_artific(particles_t *head, sfRenderWindow *w,
    speobstacle_t *spe);
    void my_put_pixel(particles_t *particle, unsigned int x, unsigned int y,
    sfColor color);
    /*Player animations*/
    int player_animations(player_t *player, mobe_t *mob);
    int player_check_key(sfKeyCode key);
    int set_player_movements(main_game_t *game, player_t *player,
    sfEvent *event);
    int detect_animations(movements_t movements_array[]);
    int modify_animations(main_game_t *game, player_t *player, sfEvent event,
    movements_t movements_array[]);
    void move_obstacle(map_t *map, sfVector2f move);
    void move_speobstacle(map_t *map, sfVector2f move);
    void move_mob(map_t *map, sfVector2f move);
    int move_up(map_t *map, player_t *player);
    int move_down(map_t *map, player_t *player);
    int move_right(map_t *map, player_t *player);
    int move_left(map_t *map, player_t *player);
    int move_player(main_game_t *game, const movements_t *movements);
    particles_t *create_dust(sfVector2f cord, int size, sfVector2f direction);
    particles_t *anim_dust(particles_t *head, sfRenderWindow *w);
    particles_t *add_particle_to_list(particles_t *head, particles_t *node,
    sfVector2f move);

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
    void pos_button_save(main_game_t *game);
    void pos_button_keybind(main_game_t *game);

    /*Display*/

    int display_menu(main_game_t *game);
    int display_skin_cus(main_game_t *game);
    int display_game(main_game_t *game);
    int display_pause(main_game_t *game);
    int display_settings(main_game_t *game);
    int display_help(main_game_t *game);
    int display_save(main_game_t *game);
    int display_keybind(main_game_t *game);
    int change_menu(main_game_t *game, sfRenderWindow *window, sfVector2i
    mouse_pos);
    void change_volume(main_game_t *game);
    int manage_volume_right(main_game_t *game, sfVector2i mouse_pos);
    int manage_volume_left(main_game_t *game, sfVector2i mouse_pos);
    int mute_all(main_game_t *game, sfVector2i mouse_pos);
    int unmute_all(main_game_t *game, sfVector2i mouse_pos);
    int manage_fps_plus(main_game_t *game, sfVector2i mouse_pos);
    int display_fps(main_game_t *game);
    int manage_reso_plus(main_game_t *game, sfVector2i mouse_pos);

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
    /*Resize*/
    int resize_all_big_buttons(main_game_t *game, float x, float y);
    int resize_all_mid_buttons(main_game_t *game, float x, float y);
    int resize_all_sml_buttons(main_game_t *game, float x, float y);
    int resize_all_buttons(main_game_t *game, float x, float y);
    int resize_pos_big_buttons(main_game_t *game, float x, float y);
    int resize_big_buttons(main_game_t *game, float x, float y);
    int set_big_buttons_sprite_pos(main_game_t *game);
    int resize_pos_mid_buttons(main_game_t *game, float x, float y);
    int resize_mid_buttons(main_game_t *game, float x, float y);
    int set_mid_buttons_sprite_pos(main_game_t *game);
    int resize_pos_sml_buttons(main_game_t *game, float x, float y);
    int resize_sml_buttons(main_game_t *game, float x, float y);
    int set_sml_buttons_sprite_pos(main_game_t *game);

    /* Events */

    bool button_is_clicked(button_t *button, sfVector2i mouse_pos);
    bool shape_is_clicked(sfRenderWindow *win, sfRectangleShape *shape,
    sfVector2i mouse_pos);
    void shape_red_clicked(main_game_t *game);
    void shape_green_clicked(main_game_t *game);
    void shape_blue_clicked(main_game_t *game);
    void clicked_state_game(main_game_t *game, sfRectangleShape *shape,
    sfVector2f position);
    void clicked_state_pause(main_game_t *game, sfRectangleShape *shape,
    sfVector2f position);
    void clicked_state_settings(main_game_t *game, sfRectangleShape *shape,
    sfVector2f position);
    void clicked_state_help(main_game_t *game, sfRectangleShape *shape,
    sfVector2f position);
    void clicked_state_main(main_game_t *game, sfRectangleShape *shape,
    sfVector2f position);
    void clicked_state_custom_skin(main_game_t *game, sfRectangleShape *shape,
    sfVector2f position);
    void clicked_state_keybind(main_game_t *game, sfRectangleShape *shape,
    sfVector2f position);
    void clicked_state_save(main_game_t *game, sfRectangleShape *shape,
    sfVector2f position);
    const event_t *get_event(sfEventType type, const event_t event_array[]);
    int zoom_event(main_game_t *game);
    int trigger_inventory(main_game_t *game);
    int event_skin_choice(main_game_t *game, sfVector2i mouse_pos);
    int set_rgb_right(main_game_t *game);
    int set_rgb_left(main_game_t *game);
    int set_rgb_shape(cus_t **cus);
    int close_window(main_game_t *game);

    /* Scenes */

    int starting_pause_scene(main_game_t *game);
    int starting_main_menu_scene(main_game_t *game);
    int starting_game_scene(main_game_t *game);
    int starting_settings_scene(main_game_t *game);
    int starting_keybind_scene(main_game_t *game);
    int starting_save_scene(main_game_t *game);
    int starting_help_scene(main_game_t *game);
    int starting_skin_scene(main_game_t *game);
    int starting_create_menus(main_game_t *game);
    const scenes_t *manage_scenes(sfKeyCode key, scenes_name name);
    int pause_scene(main_game_t *game);
    int main_menu_scene(main_game_t *game);
    int game_scene(main_game_t *game);
    int settings_scene(main_game_t *game);
    int keybind_scene(main_game_t *game);
    int save_scene(main_game_t *game);
    int help_scene(main_game_t *game);
    int skin_scene(main_game_t *game);

    /* Free data */

    int free_game_struct(main_game_t *game);
    int free_player(player_t *player);
    void destroy_all_button(main_game_t *game);
    void destroy_all_menu(main_game_t *game);
    void free_tab(char ***tab);
    particles_t *free_a_particule(particles_t *head);
    void destroy_all_texts(main_game_t *game);

    /* Load and Save progression/settings */

    FILE *open_save(const char *path);
    int save_settings(main_game_t *game);
    int load_settings(main_game_t *game);
    char **buffer_to_array(char *buffer);
    char *get_key(char *line);
    char *get_value(char *line);

    /* KeyBinding */

    /* Main function */

    int rpg(void);

#endif/* !RPG_H_ */
