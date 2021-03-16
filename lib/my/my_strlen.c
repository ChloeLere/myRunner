/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** lib
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_nbrlen(int str)
{
    int c = 0;

    for (; str > 0; str /= 10) {
        c++;
    }
    return (c);
}
