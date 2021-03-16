/*
** EPITECH PROJECT, 2020
** space_or_zero
** File description:
** other flag for my_printf
*/

#include "my.h"

int add_zero_or_space(char *str, va_list argv, int add)
{
    add++;
    int nbr = my_getnbr_with_i(str, add);
    int size = my_nbrlen(nbr) + 1;

    if (str[size] == 'd' || str[size] == 'i')
        zero_or_space_int(str[0], argv, nbr);
    if (str[size] == 's')
        space_char(argv, nbr);
    add += size;
    return (add);
}

void space_char(va_list argv, int nbr)
{
    char *str = va_arg(argv, char *);
    int size = my_strlen(str);
    int x = nbr - size - 1;
    int c = 0;

    for (; c < x && x > 0; c++)
        my_putchar(' ');
    my_putstr(str);
}

void zero_or_space_int(char str, va_list argv, int nb_z)
{
    int nbr = va_arg(argv, int);
    int size = my_nbrlen(nbr);
    int x = nb_z - size;
    int c = 0;

    for (; c < x && x > 0 ; c++) {
        my_putchar(str);
    }
    my_put_nbr(nbr);
}
