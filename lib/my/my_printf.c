/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** display
*/

#include "my.h"

int my_printf(char *s, ...)
{
    va_list argv;
    int add = 0;
    int c = 1;

    va_start(argv, s);
    for (add = 0; s[0] != '\0'; s++) {
        if (s[0] == '%') {
            add = edit_add(s + 1, argv, add);
            s += add;
            check_string(s + 1, argv);
            check_int(s + 1, argv);
            check_char(s + 1, argv);
            c = check_other(s + 1, argv);
            if (add <= 1)
                s += c;
        } else
            my_putchar(s[0]);
    }
    va_end(argv);
    return (0);
}