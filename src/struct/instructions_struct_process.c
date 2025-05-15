/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** instructions_struct_process
*/

#include "corewar.h"

void free_instruction_params(instructions_params_t *params)
{
    free(params);
}

int read_bytes(unsigned char *arena, int start, int size)
{
    if (size == 2)
        return bytes_to_short(arena, start);
    if (size == 4)
        return bytes_to_int(arena, start);
    if (size == 1)
        return arena[start];
    return 0;
}

static void init_types_and_values(virtual_machine_t *vm, champions_t *champ,
    int opcode, instructions_params_t *params)
{
    op_t op = get_instruction(opcode);
    unsigned char coding = 0;
    int offset = 1;
    int size = DEFAULT_SIZE;

    if (op.nbr_args > 0 && op.code != LIVE_ID && op.code != ZJMP_ID
        && op.code != FORK_ID && op.code != LFORK_ID) {
        coding = get_coding_byte(vm, champ->prog_counter);
        offset++;
    } else
        for (int i = 0; i < op.nbr_args; i++)
            params->types[i] = op.type[i];
    for (int i = 0; i < op.nbr_args; i++) {
        if (coding)
            params->types[i] = (coding >> (6 - 2 * i)) & MAX_BIN_BYTES;
        size = get_params_size(params->types[i], &op);
        params->values[i] = read_bytes(vm->arena, champ->prog_counter
            + offset, size);
        offset += size;
    }
}

instructions_params_t *init_instruction_params(
    virtual_machine_t *vm, int cycles, champions_t *champ, int opcode)
{
    instructions_params_t *params = malloc(sizeof(instructions_params_t));
    op_t op;

    if (!params)
        return NULL;
    op = get_instruction(opcode);
    if (op.code == 0) {
        free(params);
        return NULL;
    }
    params->vm = vm;
    params->cycles = cycles;
    params->champ = champ;
    params->instruction = opcode;
    params->nb_params = op.nbr_args;
    init_types_and_values(vm, champ, opcode, params);
    return params;
}
