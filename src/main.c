/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Main
*/
#include "corewar.h"

int main(int ac, char **av)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);

    if (vm == NULL)
        return 84;
    if (ac < 3)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        return help();
    }
    vm = fill_vm(ac, av, vm);
    if (vm->champion == NULL || vm->champion->next == NULL)
        return 84;
    free_virtual_machine(vm);
    return 0;
}
