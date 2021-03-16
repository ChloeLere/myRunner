/*
** EPITECH PROJECT, 2020
** check_type
** File description:
** define type %
*/

#include "my.h"

void check_string(char *type, va_list argv)
{
    if (type[0] == 's')
        my_putstr(va_arg(argv, char *));
    if (type[0] == 'S')
        display_all_char(va_arg(argv, char *));
    if (type[0] == 'p')
        display_p(type, argv);
}

void check_int(char *type, va_list argv)
{
    if (type[0] == 'd' || type[0] == 'i')
        my_put_nbr(va_arg(argv, int));
    if (type[0] == 'u')
        my_put_nbr_uns(va_arg(argv, unsigned int));
    if (type[0] == 'o')
        convert(argv, 8);
    if (type[0] == 'x')
        convert_hexa_lower(argv);
    if (type[0] == 'X')
        convert_hexa_upper(argv);
    if (type[0] == 'b')
        convert(argv, 2);
}

void check_char(char *type, va_list argv)
{
    if (type[0] == 'c' || type[0] == 'C')
        my_putchar(va_arg(argv, int));
    if (type[0] == '%')
        my_putchar('%');
}

int check_other(char *type, va_list argv)
{
    if (type[0] == 'l' && type[1] == 'd') {
        my_put_nbr_long(va_arg(argv, long));
        return (2);
    }
    if (type[0] == 'l' && type[1] == 'f') {
        my_put_float(va_arg(argv, double));
        return (2);
    }
    if (type[0] == 'f') {
        my_put_float(va_arg(argv, double));
        return (1);
    }
    if (type[0] == 'h' && type[1] == 'd') {
        my_put_short(va_arg(argv, int));
        return (2);
    }
    return (1);
}
