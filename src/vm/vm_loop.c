/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Vm loop
*/
#include "corewar.h"
#include "op.h"
#include "structs.h"
#include <stdio.h>

// Needs to change the if instruction == 1 by the function pointer
int handle_instructions(virtual_machine_t *vm, int cycles)
{
    champions_t *current = vm->champion;
    char instruction;

    while (current != NULL) {
        instruction = vm->arena[current->prog_counter];
        if (current->cylces_to_wait > 0) {
            current->cylces_to_wait--;
            current = current->next;
            continue;
        }
        if (instruction == 1)
            handle_live(vm, cycles, &(current->prog_counter));
        current = current->next;
    }
    return 0;
}

int vm_loop(virtual_machine_t *vm)
{
    for (int cycles = 1; cycles < vm->cycle_to_die ||
    vm->alive_champions > 1; cycles++) {
        if (cycles == vm->cycle_to_die)
            reset_cycles(vm, &cycles);
        handle_instructions(vm, cycles);
        get_alive_champions(vm, cycles);
    }
    get_winner(vm);
    return 0;
}
