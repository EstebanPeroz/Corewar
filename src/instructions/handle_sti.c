/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** handle_sti
*/

#include "corewar.h"

static int verify_type_and_return(instructions_params_t *params, int idx)
{
    int value = params->values[idx];

    if (params->types[idx] == T_REG) {
        if (!is_valid_register(value))
            return 0;
        return params->champ->registers[value - 1];
    } else if (params->types[idx] == T_DIR
        || params->types[idx] == T_IND) {
        return value;
    }
    return 0;
}

int handle_sti(instructions_params_t *params)
{
    int reg_idx = params->values[0];
    int final_value = 0;
    int val2 = 0;
    int val3 = 0;
    int offset = 0;
    int adresse_to_put = 0;

    if (!is_valid_register(reg_idx))
        return 0;
    final_value = params->champ->registers[reg_idx - 1];
    val2 = verify_type_and_return(params, 1);
    val3 = verify_type_and_return(params, 2);
    offset = (val2 + val3) % IDX_MOD;
    adresse_to_put =
        (params->champ->prog_counter + offset + MEM_SIZE) % MEM_SIZE;
    put_int_in_arena(params->vm->arena, adresse_to_put, final_value);
    return 0;
}
