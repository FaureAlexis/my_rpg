/*
** EPITECH PROJECT, 2021
** basic_flags
** File description:
** basic_flags
*/

#include "lib.h"

int int_flags(char flags, int i, const char *format, va_list ap)
{
    switch (flags) {
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 'd':
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'u':
            my_put_nbr(va_arg(ap, unsigned int));
            break;
    }
    return i;
}

int str_flags(char flags, int i, const char *format, va_list ap)
{
    switch (flags) {
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'S':
            my_put_printable_str(va_arg(ap, char *));
            break;
        case '%':
            my_putchar('%');
            break;
    }
    return i;
}

int double_flags(char flags, int i, const char *format, va_list ap)
{
    char *unsigned_nb = NULL;

    if (flags == 'l') {
        switch (format[i + 1]) {
            case 'i':
            case 'd':
                my_put_nbr(va_arg(ap, long int));
                break;
            case 'u':
                my_put_ul(va_arg(ap, unsigned long));
                break;
        }
    }
    return i += 1;
}

int base_flags(char flags, int i, const char *format, va_list ap)
{
    switch (flags) {
        case 'x':
            my_putnbr_base(va_arg(ap, unsigned long), "0123456789abcdef");
            break;
        case 'X':
            my_putnbr_base(va_arg(ap, unsigned long), "0123456789ABCDEF");
            break;
        case 'o':
            my_putnbr_base(va_arg(ap, unsigned long), "01234567");
            break;
        case 'b':
            my_putnbr_base(va_arg(ap, unsigned int), "01");
            break;
        case 'p':
            my_putstr("0x");
            my_putnbr_base(va_arg(ap, unsigned long), "0123456789abcdef");
            break;
    }
    return i;
}

int hashtag_flags(char flags, int i, const char *format, va_list ap)
{
    unsigned long value = va_arg(ap, unsigned long);

    if (value != 0)
        manage_hashtag_flags(format[i + 1]);
    switch (format[i + 1]) {
        case 'o':
            my_putnbr_base(value, "01234567");
            break;
        case 'x':
        case 'p':
            my_putnbr_base(value, "0123456789abcdef");
            break;
        case 'X':
            my_putnbr_base(value, "0123456789ABCDEF");
            break;
    }
    return i += 1;
}
