/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** handle_or
*/

#include "corewar.h"

int handle_or(instructions_params_t *params)
{
    int and_result = 0;
    int left_params = 0;
    int right_params = 0;

    if (!valid_args(params))
        return EXIT_FAILURE;
    left_params = get_value_with_type(params, 0);
    right_params = get_value_with_type(params, 1);
    and_result = left_params | right_params;
    params->champ->carry = (and_result == 0) ? 1 : 0;
    params->champ->registers[params->values[2] - 1] = and_result;
    return 0;
}
