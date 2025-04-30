/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Vm loop
*/
#include "corewar.h"
#include "op.h"
#include <stdio.h>

int handle_instructions(virtual_machine_t *vm, int cycles)
{
    return 0;
}

int vm_loop(virtual_machine_t *vm)
{
    for (int cycles = 1; cycles < vm->cycle_to_die ||
    vm->alive_champions > 1; cycles++) {
        handle_instructions(vm, cycles);
    }
    return 0;
}
