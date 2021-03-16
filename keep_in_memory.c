/*
** EPITECH PROJECT, 2020
** keep_in_memory
** File description:
** find th hightest score
*/

#include "include/my.h"

char *file_op(char *filepath, char *error)
{
    int fd = 0;
    int memory_area = load_file_in_mem(filepath);
    char *buffer = malloc(sizeof(char) + memory_area);
    int r = 0;

    fd = open(filepath, O_RDWR);
    if (fd == -1)
        return (error);
    r = read(fd, buffer, memory_area);
    if (r == -1)
        return (error);
    close(fd);
    return (buffer);
}

char *find_the_bigger(int n, char *nbr)
{
    int fd = 0;
    char *last = file_op("element/.score", "0");
    int last_nbr = my_getnbr_with_i(last, 0);
    char *better;

    if (last_nbr < n || last[0] == '\0') {
        fd = open("element/.score", O_WRONLY);
        write(fd, nbr, my_strlen(nbr));
        close(fd);
        return (nbr);
    } else {
        better = int_to_char(last_nbr);
        return (better);
    }
}