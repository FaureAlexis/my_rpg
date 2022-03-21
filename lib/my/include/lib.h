/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib
*/

#ifndef MY_HEADER
    #define MY_HEADER

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

    #define IS_LETTER(c) \
        ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? (1) : (0))
    #define IS_UPPER_CHAR(c) ((c <= 'A' && c >= 'Z') ? (1) : (0))
    #define IS_LOWER_CHAR(c) ((c >= 'a' && c <= 'z') ? (1) : (0))
    #define IS_PRINTABLE(c) ((c > 31 && c < 127) ? (1) : (0))
    #define IS_NUM(c) ((c >= '0' && c <= '9') ? (1) : (0))

typedef struct pr_type_flags_s {
    char flags;
    int(*flptr)(char, int, const char *, va_list);
}pr_type_flags_t;

    int counter_sign(char const *str);
    int my_isneg(int nb);
    void reverse_opp_numb(char *c, char *d);
    int my_compute_power_rec(int nb, int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    int my_getnbr(char const *str);
    char *my_int_to_str(int nb);
    int my_isneg(int n);
    int my_is_prime(int nb);
    void my_putchar(char c);
    void my_put_nbr(long nbr);
    int my_putstr(char const *str);
    char *my_revstr(char *str);
    int my_showmem(char const *str, int size);
    int my_showstr(char const *str);
    void my_sort_int_array(int *array, int size);
    char *my_strcat(char *dest, char const *str);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    int my_str_isalpha(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);
    int my_strlen(char const *str);
    char *my_strlowcase(char *str);
    char *my_strncat(char *dest, char const *str, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strndup(char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    char *my_strcapitalize(char *str);
    int check_sign(char const *nb);
    int my_atoi(char const *str);
    unsigned long my_putnbr_base(unsigned long nbr, char const *base);
    int my_getnbr_base(char const *str, char const *base);
    int return_index(char c, char const *str);
    void my_put_ul(unsigned long nbr);
    void my_put_printable_str(char *str);
    int nblen(unsigned long nb);
    void manage_hashtag_flags(char flags);
    int int_flags(char flags, int i, const char *format, va_list ap);
    int str_flags(char flags, int i, const char *format, va_list ap);
    int double_flags(char flags, int i, const char *format, va_list ap);
    int base_flags(char flags, int i, const char *format, va_list ap);
    int zero_flags(char flags, int i, const char *format, va_list ap);
    int hashtag_flags(char flags, int i, const char *format, va_list ap);
    int my_printf(const char *format, ...);

typedef struct linked_nb_s {
    struct linked_nb_s *prev;
    int nb;
    char *data;
    bool status;
    struct linked_nb_s *next;
} linked_nb_t;

    void free_linked_list(linked_nb_t *head);
    void free_linked_char_list(linked_nb_t *head);
    void display_nb_list(linked_nb_t *head);
    void display_nb_reverse_list(linked_nb_t *head);
    linked_nb_t *init_linked_nb_list(int ac, char **av);
    void display_char_list(linked_nb_t *head);
    void display_char_reverse_list(linked_nb_t *head);
    linked_nb_t *init_linked_char_list(int ac, char **av);
    int get_list_len(linked_nb_t *head);
    linked_nb_t *get_node(linked_nb_t **head, int pos);
    int get_nb_from_pos(linked_nb_t *list, int pos);
    char *get_value_from_pos(linked_nb_t *list, int pos);
    int add_last_node(linked_nb_t **head, char *value, int nb, bool status);

#endif /* MY_HEADER */
