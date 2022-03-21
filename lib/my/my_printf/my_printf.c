/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include "lib.h"

static const pr_type_flags_t type_flags[] = {
    {.flags = 'c', .flptr = &int_flags},
    {.flags = 'd', .flptr = &int_flags},
    {.flags = 'i', .flptr = &int_flags},
    {.flags = 'u', .flptr = &int_flags},
    {.flags = 's', .flptr = &str_flags},
    {.flags = 'S', .flptr = &str_flags},
    {.flags = '%', .flptr = &str_flags},
    {.flags = 'x', .flptr = &base_flags},
    {.flags = 'X', .flptr = &base_flags},
    {.flags = 'o', .flptr = &base_flags},
    {.flags = 'p', .flptr = &base_flags},
    {.flags = 'b', .flptr = &base_flags},
    {.flags = 'l', .flptr = &double_flags},
    {.flags = 'h', .flptr = &double_flags},
    {.flags = '#', .flptr = &hashtag_flags},
    {.flags = '\0', .flptr = NULL}
};

const pr_type_flags_t *get_flags(char flags)
{
    for (int i = 0; type_flags[i].flags != '\0'; i++) {
        if (type_flags[i].flags == flags)
            return &type_flags[i];
    }
    return NULL;
}

int checkflag(const pr_type_flags_t *fl, int i, char const *format, va_list ap)
{
    fl = get_flags(format[i + 1]);
    if (fl != NULL)
        i = fl->flptr(format[i + 1], i + 1, format, ap);
    else
        my_putchar(format[i]);
    i++;
    return i;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    const pr_type_flags_t *fl = NULL;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0';) {
        if (format[i] == '%') {
            i = checkflag(fl, i, format, ap);
        } else {
            my_putchar(format[i]);
            i++;
        }
    }
    va_end(ap);
}
