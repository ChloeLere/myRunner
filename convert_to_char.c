/*
** EPITECH PROJECT, 2020
** convert_to_char
** File description:
** convert int -> char
*/

#include "include/my.h"

char *inverse_char(int size, char *nbr)
{
    char *result = malloc(sizeof(char) + size);
    int c = 0;
    int temp = size - 1;

    for (; size > 0; size--, c++, temp--) {
        result[c] = nbr[temp];
    }
    return (result);
}

char *int_to_char(int nbr)
{
    int size = my_nbrlen(nbr);
    char *temp = malloc(sizeof(char) * (size + 1));
    int c = 0;
    char *result;

    if (nbr == 0) {
        temp[0] = '0';
        temp[1] = '\0';
        return (temp);
    }
    for (; nbr > 0; nbr /= 10, ++c)
        temp[c] = (nbr % 10) + '0';
    temp[c + 1] = '\0';
    result = inverse_char(c, temp);
    free(temp);
    return (result);
}

/*char *int_to_char(int nbr)
{
    int size = my_nbrlen(nbr);
    char *temp = malloc(sizeof(char) * (size));
    int c = size - 1;
    int d = 1;

    if (nbr == 0) {
        temp[0] = '0';
        temp[1] = '\0';
        return (temp);
    }
    for (; c >= 0; c--, d *= 10)
        temp[c] = ((nbr / d) % 10 + '0');
    temp[size + 1] = '\0';
    return (temp);
}*/