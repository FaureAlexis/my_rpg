/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib
*/

#ifndef MY_RPG
    #define MY_RPG

    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <errno.h>
    #include <string.h>
    #include <limits.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct game_object
{
    sfVector2f cord;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect frame;
} game_object_s;

typedef struct cloc
{
    sfClock *clock1;
    sfTime time1;
    float seconds1;
}cloc_s;

typedef struct obstacle_s
{
    game_object_s *src;
    struct obstacle_s *next;
}obstacle_t;

typedef struct wind_s
{
    sfRenderWindow* window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
    sfMusic *music;
}wind_t;

typedef struct game_scene_s
{
    wind_t *window;
    obstacle_t *obstacle;
}game_scene_t;

    char *open_file(char const *filepath);
    char **my_str_to_word_array_pos(char const *str, char pos, int idx);
    char ***make_tab(char *filepath);
    int my_arraylen(char *const *array);
    void launch_rpg(char ***tab);
    void init_obstacle(game_scene_t *src, char ***tab, int i);
    void display_obstacle(game_scene_t *src);
    obstacle_t *add_node_to_obstacle(obstacle_t *head, obstacle_t *node);

#endif
