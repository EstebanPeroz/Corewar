/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** handle_and
*/

#include "corewar.h"

static int get_value_with_type(instructions_params_t *params, int idx)
{
    int final_value = 0;
    int adresse_to_print = 0;

    if (params->types[idx] == T_REG)
        final_value = params->champ->registers[params->values[idx] - 1];
    if (params->types[idx] == T_DIR)
        final_value = params->values[idx];
    if (params->types[idx] == T_IND) {
        adresse_to_print = (params->champ->prog_counter +
            (params->values[idx] % IDX_MOD)) % MEM_SIZE;
        final_value = read_bytes(params->vm->arena,
            (adresse_to_print + MEM_SIZE) % MEM_SIZE, T_IND);
    }
    return final_value;
}

static bool valid_args(instructions_params_t *params)
{
    if (!is_valid_register(params->values[2]) ||
        (params->types[0] == T_REG && !is_valid_register(params->values[0])) ||
        (params->types[1] == T_REG && !is_valid_register(params->values[1])))
        return false;
    return true;
}

int handle_and(instructions_params_t *params)
{
    int and_result = 0;
    int left_params = 0;
    int right_params = 0;

    if (!valid_args(params))
        return EXIT_FAILURE;
    left_params = get_value_with_type(params, 0);
    right_params = get_value_with_type(params, 1);
    and_result = left_params & right_params;
    params->champ->carry = (and_result == 0) ? 1 : 0;
    params->champ->registers[params->values[2] - 1] = and_result;
    return 0;
}
