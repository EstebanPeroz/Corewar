/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** moove_prog_counter
*/

#include "corewar.h"

static unsigned char get_coding_byte(virtual_machine_t *vm, int pc)
{
    return vm->arena[(pc + 1) % MEM_SIZE];
}

int update_prog_counter(virtual_machine_t *vm,
    champions_t *champ, const op_t *op)
{
    int new_offset = 1;
    unsigned char coding = get_coding_byte(vm, champ->prog_counter);
    int params_type;

    if (op->nbr_args > 0 && op->code != 1 && op->code != 9
        && op->code != 12 && op->code != 15)
        new_offset++;
    for (int i = 0; i < op->nbr_args; i++) {
        params_type = (coding >> (6 - 2 * i)) & 0b11;
        if (params_type == TYPE_REG)
            new_offset += REG_SIZE;
        if (params_type == TYPE_IND)
            new_offset += IND_SIZE;
        if (params_type == TYPE_DIR)
            new_offset += op->force_indexes ? IND_SIZE : DIR_SIZE;
    }
    return new_offset % MEM_SIZE;
}
