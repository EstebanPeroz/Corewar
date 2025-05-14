/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** handle_sub
*/

#include "corewar.h"

int handle_sub(instructions_params_t *params)
{
    int reg1_content = 0;
    int reg2_content = 0;
    int result = 0;

    if (params->types[0] != T_REG || params->types[1] != T_REG
        || params->types[2] != T_REG)
        return EXIT_FAILURE;
    if (!is_valid_register(params->values[0])
        || !is_valid_register(params->values[1])
        || !is_valid_register(params->values[2]))
        return EXIT_FAILURE;
    reg1_content = params->champ->registers[params->values[0] - 1];
    reg2_content = params->champ->registers[params->values[1] - 1];
    result = reg1_content SUBSTRACTION_MARK reg2_content;
    params->champ->carry = (result == 0) ? 1 : 0;
    params->champ->registers[params->values[2] - 1] = result;
    return 0;
}
