/*
** EPITECH PROJECT, 2020
** main_runner
** File description:
** main + display h
*/

#include "include/my.h"

void display_h(void)
{
    my_printf("Finite runner created with CSFML.\n\nUSAGE\n");
    my_printf(" ./my_runner maps/.map.txt\n\n\nOPTIONS\n -i\t\t");
    my_printf("launch the game in infinity mode.\n -h\t\t");
    my_printf("print the usage and quit.\n\n");
    my_printf("USER INTERACTIONS\n SPACE_KEY\tjump.\n");
    my_printf(" ESCAPE_KEY\tpaused.\n");
}

int open_project(char *argv)
{
    if (argv[0] == '-' && argv[1] == 'h') {
        display_h();
        return (0);
    }
    if (argv[0] == '-' && argv[1] == 'i') {
        open_window(1, argv);
        return (0);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 2) {
        write(2, "Error: not enough/too many argument\n", 37);
        return (84);
    }
    if (open_project(argv[1]) == 0)
        return (0);
    if (open_map(argv) == 84) {
        write(2, "Error\n", 7);
        return (84);
    }
    open_window(0, argv[1]);
    return (0);
}
