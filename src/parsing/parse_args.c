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

static void update_id_address(virtual_machine_t *vm)
{
    sort_champs(&vm->champion);
    manage_adress(vm->champion);
    vm->nbr_processus = get_total_champs(&vm->champion);
}

int fill_vm(int ac, char **av, virtual_machine_t *vm)
{
    if (my_strcmp(av[1], "-dump") == 0) {
        vm->cycle_to_dump = get_cycles(&av, ac);
    }
    if (vm->cycle_to_dump == -1)
        return -1;
    vm->champion = get_champs_with_options(av);
    if (vm->champion == NULL) {
        return EXIT_FAILURE;
    }
    update_id_address(vm);
    return 0;
}
