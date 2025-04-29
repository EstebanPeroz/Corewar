/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Get arguments
*/
#include "corewar.h"

#include <string.h>

int is_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

static int get_cycles(char ***av, int ac)
{
    if (ac < 5 || (*av)[2][0] == '-')
        return -1;
    if (!is_nbr((*av)[2]))
        return -1;
    *av += 2;
    return my_getnbr((*av)[2]);
}

virtual_machine_t *fill_vm(int ac, char **av, virtual_machine_t *vm)
{
    // args.nb_cycles = 0;
    // args.champs = NULL;
    if (my_strcmp(av[1], "-dump") == 0) {
        vm->cycle_to_dump = get_cycles(&av, ac);
    }
    if (vm->cycle_to_dump == -1)
        return vm;
    vm->champion = get_champs_with_options(av);
    return vm;
}
