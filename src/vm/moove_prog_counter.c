/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** moove_prog_counter
*/

#include "corewar.h"

unsigned char get_coding_byte(virtual_machine_t *vm, int pc)
{
    return vm->arena[(pc + 1) % MEM_SIZE];
}

int get_params_size(int params, op_t *op)
{
    if (params == TYPE_REG)
        return REG_SIZE;
    if (params == TYPE_IND)
        return IND_SIZE;
    if (params == TYPE_DIR)
        return op->force_indexes ? IND_SIZE : DIR_SIZE;
    return 0;
}

int update_prog_counter(virtual_machine_t *vm,
    champions_t *champ, op_t *op)
{
    int new_offset = 1;
    unsigned char coding = get_coding_byte(vm, champ->prog_counter);
    int params_type;

    if (op->nbr_args > 0 && op->code != LIVE_ID + 1 && op->code != ZJMP_ID + 1
        && op->code != FORK_ID + 1 && op->code != LFORK_ID + 1)
        new_offset++;
    if (op->code == LIVE_ID + 1)
        return new_offset + DIR_SIZE;
    if (op->code == ZJMP_ID + 1 || op->code == FORK_ID + 1
        || op->code == LFORK_ID + 1)
        return new_offset + IND_SIZE;
    for (int i = 0; i < op->nbr_args; i++) {
        params_type = (coding >> (6 - 2 * i)) & MAX_BIN_BYTES;
        new_offset += get_params_size(params_type, op);
    }
    return new_offset;
}
