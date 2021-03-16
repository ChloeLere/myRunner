/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** lib
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nb;
    int m = 1;

    while (!(str[i] >=  '0' && str[i] <= '9' ) && str[i] != '-') {
        i++;
    }
    for (; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'
    || str[i] == '-'; i++) {
        if (str[i] == '-') {
            m = m * (- 1);
            i++;
        }
        nb = (nb + str[i] - 48) * 10;
    }
    nb = nb / 10;
    return (nb * m);
}

int my_getnbr_with_i(char const *str, int i)
{
    int nb = 0;
    int m = 1;

    while (!(str[i] >=  '0' && str[i] <= '9' ) && str[i] != '-') {
        i++;
    }
    for (; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'
    || str[i] == '-'; i++) {
        if (str[i] == '-') {
            m = m * (- 1);
            i++;
        }
        nb = (nb + str[i] - 48) * 10;
    }
    nb = nb / 10;
    return (nb * m);
}
