/*
** EPITECH PROJECT, 2020
** open_map
** File description:
** open map
*/

#include "include/my.h"

int load_file_in_mem(char const *filepath)
{
    struct stat buff;
    int size = 0;

    stat(filepath, &buff);
    size = buff.st_size;
    return (size);
}

int open_map(char **argv)
{
    int memory_area = load_file_in_mem(argv[1]);
    int fd = open(argv[1], O_RDWR);
    char buffer[memory_area];
    int r = 0;

    if (fd == -1)
        return (84);
    r = read(fd, buffer, memory_area);
    if (r == -1)
        return (84);
    close(fd);
    return (0);
}