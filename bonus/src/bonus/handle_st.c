/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** handle_st
*/

#include "corewar.h"
#include "op.h"

static void st_with_number(int dest, instructions_params_t *params, int value)
{
    int offset = dest % IDX_MOD;
    int addr = (params->champ->prog_counter + offset + MEM_SIZE) % MEM_SIZE;

    put_int_in_arena(params->vm->arena, addr, value);
    for (int i = 0; i < 4; i++)
        params->vm->owner_map[(addr + i) % MEM_SIZE] = params->champ->dev_id;
}

int handle_st(instructions_params_t *params)
{
    int reg_src_content = params->values[0];
    int dest = params->values[1];
    int value = 0;

    if (params->types[0] != T_REG || !is_valid_register(reg_src_content))
        return EXIT_FAILURE;
    value = params->champ->registers[reg_src_content - 1];
    if (params->types[1] == T_REG) {
        if (!is_valid_register(dest))
            return EXIT_FAILURE;
        params->champ->registers[dest - 1] = value;
    } else
        st_with_number(dest, params, value);
    return 0;
}
