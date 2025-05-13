/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** set_cycle_to_wait
*/

#include "corewar.h"

void update_champs_cycle_to_wait(virtual_machine_t *vm)
{
    champions_t *current = vm->champion;
    unsigned char opcode;
    const op_t *op;

    while (current != NULL) {
        opcode = vm->arena[current->prog_counter % MEM_SIZE];
        op = get_instruction(opcode);
        if (op) {
            current->cylces_to_wait = op->nbr_cycles;
        } else {
            current->cylces_to_wait = 0;
        }
        current = current->next;
    }
}
