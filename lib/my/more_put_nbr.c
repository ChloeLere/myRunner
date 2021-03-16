/*
** EPITECH PROJECT, 2020
** more_put_nbr
** File description:
** lib
*/

#include "my.h"

void my_put_nbr_long(long nb)
{
    long n = nb;

    if (n < 0) {
        my_putchar('-');
        n *= (-1);
    }
    if (n >= 10) {
        my_put_nbr_long(n / 10);
    }
    my_putchar((n % 10) + '0');
}

double my_put_float(double nbr)
{
    int entier = ((int) nbr);
    int decimal = 0;
    int size = 10;
    double temp = nbr - entier;

    decimal = (nbr - entier) * size;
    my_put_nbr(entier);
    my_putchar('.');
    my_put_nbr(decimal);
}

void my_put_short(short nb)
{
    short n = ((short) nb);

    if (n < 0) {
        my_putchar('-');
        n *= (-1);
    }
    if (n >= 10) {
        my_put_short(n / 10);
    }
    my_putchar((n % 10) + '0');
}