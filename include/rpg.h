/*
** EPITECH PROJECT, 2022
<<<<<<< HEAD
** rpg
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

    #include <math.h>
    #include "lib.h"
    #include "csfml.h"

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

    /* Events */

    const event_t *get_event(sfEventType type, const event_t event_array[]);
    int close_window(main_game_t *game);

    /* Scenes */

    const scenes_t *manage_scenes(sfKeyCode key, scenes_name name);
    int pause_scene(main_game_t *game);

    /* Free data */

    void free_game_struct(main_game_t *game);

    /* Main function */

    int rpg(int argc, const char * const *argv, char ** env);

#endif /* !RPG_H_ */
