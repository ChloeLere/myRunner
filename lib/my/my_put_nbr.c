/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** lib
*/

#include "my.h"

int my_put_nbr(int nb)
{
    long n = nb;

    if (n < 0) {
        my_putchar('-');
        n *= (-1);
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
    }
    my_putchar((n % 10) + '0');
    return (n % 10);
}

int my_put_nbr_pr(int nb)
{
    long n = nb;

    if (n < 0) {
        n *= (-1);
    }
    if (n >= 10) {
        my_put_nbr_pr(n / 10);
    }
    return (n % 10);
}

void my_put_nbr_oct(int nb)
{
    long n = nb;

    if (n < 0) {
        my_put_nbr_oct((n * (-1)));
    }
    if (n > 9) {
        my_put_nbr_oct(n / 8);
        n = nb % 8;
    }
    if (n < 10) {
        my_putchar(n + '0');
    }
}

void my_put_nbr_uns(unsigned int nb)
{
    unsigned int n = nb;

    if (n > 9) {
        my_put_nbr_uns(n / 10);
        n = nb % 10;
    }
    if (n < 10) {
        my_putchar(n + '0');
    }
}