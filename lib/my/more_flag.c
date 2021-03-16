/*
** EPITECH PROJECT, 2020
** more_flag
** File description:
** other flag for my_printf
*/

#include "my.h"

int edit_add(char *str, va_list argv, int add)
{
    if ((str[0] == ' ' || str[0] == '+')
        && (str[1] == 'f' || str[1] == 'd' || str[1] == 'i')) {
        add += space_or_plus(str[0], argv, add);
        str += add;
    }
    if (str[0] == '#') {
        if (str[1] == 'o')
            my_putchar('0');
        if (str[1] == 'x' || str[1] == 'X') {
            my_putchar('0');
            my_putchar(str[1]);
        }
        add++;
        str++;
    }
    if ((str[0] == ' ' || str[0] == '0') && (str[1] >= '0' || str[1] <= '9')) {
        add += add_zero_or_space(str, argv, add);
    }
    return (add);
}

int space_or_plus(char str, va_list argv, int add)
{
    int nbr = va_arg(argv, int);

    if (nbr >= 0) {
        my_putchar(str);
        my_put_nbr(nbr);
        add += 2;
        return (add);
    } else {
        my_put_nbr(nbr);
        add += 2;
        return (add);
    }
}

void display_all_char(char *str)
{
    int nbr = 0;

    for (nbr = 0; str[0] != '\0'; str++) {
        if (str[0] <= 31 || str[0] == 127) {
            my_putchar(92);
            my_putchar('0');
            my_put_nbr_oct(str[0]);
        } else {
            my_putchar(str[0]);
        }
    }
}

void display_p(char *str, va_list argv)
{
    unsigned long ad = 0;

    my_putstr("0x");
    ad = ((unsigned long) va_arg(argv, char *));
    convert_hexa_lower_long(ad, argv);
}
