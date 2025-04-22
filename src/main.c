/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Main
*/
#include "corewar.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        return help();
    }
    parse_args(ac, av);
    return 0;
}
