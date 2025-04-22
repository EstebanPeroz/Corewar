/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Get arguments
*/
#include "corewar.h"

static int get_cycles(char ***av, int ac)
{
    if (ac < 5 || (*av)[2][0] == '-')
        return -1;
    for (int i = 0; (*av)[2][i] != '\0'; i++) {
        if ((*av)[2][i] < '0' || (*av)[2][i] > '9')
            return -1;
    }
    *av += 2;
    return my_getnbr((*av)[2]);
}

parsed_args_t parse_args(int ac, char **av)
{
    parsed_args_t args = {};

    if (my_strcmp(av[1], "-dump") == 0) {
        args.nb_cycles = get_cycles(&av, ac);
    }
    args.core_files = av;
    for (int i = 1; av[i] != NULL; i++) {
        my_putstr(av[i]);
        my_putchar('\n');
    }
    return args;
}
