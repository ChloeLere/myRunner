/*
** EPITECH PROJECT, 2020
** convert
** File description:
** convert 2, 8, 16
*/

#include "my.h"

void convert(va_list argv, int base)
{
    unsigned int nbr = va_arg(argv, unsigned int);
    unsigned int resoct = 0;
    char *res = malloc(sizeof(va_list));
    int c = 0;

    for (resoct = 0; nbr > 0; nbr /= base, c++) {
        resoct = nbr % base;
        res[c] = resoct + '0';
    }
    c--;
    for (; c >= 0; c--) {
        my_putchar(res[c]);
    }
    free(res);
}

void convert_hexa_lower(va_list argv)
{
    unsigned int nbr = va_arg(argv, unsigned int);
    unsigned int resoct = 0;
    char *res = malloc(sizeof(va_list));
    int c = 0;

    for (; nbr > 0; nbr /= 16, c++) {
        resoct = nbr % 16;
        if (resoct > 9)
            res[c] = resoct + 'W';
        else
            res[c] = resoct + '0';
    }
    c--;
    for (; c >= 0; c--)
        my_putchar(res[c]);
    free(res);
}

void convert_hexa_upper(va_list argv)
{
    unsigned int nbr = va_arg(argv, unsigned int);
    unsigned int resoct = 0;
    char *res = malloc(sizeof(va_list));
    int c = 0;

    for (; nbr > 0; nbr /= 16, c++) {
        resoct = nbr % 16;
        if (resoct > 9)
            res[c] = resoct + '7';
        else
            res[c] = resoct + '0';
    }
    c--;
    for (; c >= 0; c--)
        my_putchar(res[c]);
    free(res);
}

void convert_hexa_lower_int(int nbr, va_list argv)
{
    int resoct = 0;
    char *res = malloc(sizeof(va_list));
    int c = 0;

    for (; nbr > 0; nbr /= 16, c++) {
        resoct = nbr % 16;
        if (resoct > 9)
            res[c] = resoct + 'W';
        else
            res[c] = resoct + '0';
    }
    c--;
    for (; c >= 0; c--)
        my_putchar(res[c]);
    free(res);
}

void convert_hexa_lower_long(unsigned long nbr, va_list argv)
{
    unsigned long resoct = 0;
    char *res = malloc(sizeof(va_list));
    int c = 0;

    for (; nbr > 0; nbr /= 16, c++) {
        resoct = nbr % 16;
        if (resoct > 9)
            res[c] = resoct + 'W';
        else
            res[c] = resoct + '0';
    }
    c--;
    for (; c >= 0; c--)
        my_putchar(res[c]);
    free(res);
}