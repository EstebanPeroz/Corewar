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

int (* const funcs[INSTRUCTIONS_NB])
(instructions_params_t *) = {
    handle_live, handle_zjmp, handle_fork, handle_lfork,
};

static void call_instruction_functions(virtual_machine_t *vm,
    int cycles, champions_t *champ, int instruction)
{
    instructions_params_t params = { vm, cycles, champ };

    for (int i = 0; i < INSTRUCTIONS_NB; i++) {
        if (instruction == i + 1) {
            funcs[i](&params);
        }
    }
}

int handle_instructions(virtual_machine_t *vm, int cycles)
{
    champions_t *current = vm->champion;
    char instruction;

    while (current != NULL) {
        instruction = vm->arena[current->prog_counter];
        if (is_cooldown(&current))
            continue;
        call_instruction_functions(vm,
        cycles, current, instruction);
        current->prog_counter += 1;
        current->prog_counter %= MEM_SIZE;
        current = current->next;
    }
    return 0;
}

int vm_loop(virtual_machine_t *vm)
{
    int last_dump = 1;

    for (int cycles = 1; cycles <= vm->cycle_to_die ||
    vm->alive_champions > 1; cycles++) {
        if (cycles > vm->cycle_to_die)
            reset_cycles(vm, &cycles);
        handle_instructions(vm, cycles);
        get_alive_champions(vm, cycles);
        handle_dump(vm, &last_dump);
        decrease_cycle_to_die(vm);
    }
    get_winner(vm);
    return 0;
}
