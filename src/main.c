/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Main
*/
#include "corewar.h"

int main(int ac, char **av)
{
    parsed_args_t args;

    if (ac < 3)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        return help();
    }
    args = parse_args(ac, av);
    if (args.nb_cycles == -1)
        return 84;
    return 0;
}
