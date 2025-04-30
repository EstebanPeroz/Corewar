/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** fill_vm
*/

#include "corewar.h"

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
    vm->alive_champions = 0;
    update_id_address(vm);
    place_all_processus(vm);
    return 0;
}
