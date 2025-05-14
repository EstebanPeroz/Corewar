/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle aff instruction
*/

#include "corewar.h"
#include "op.h"

int handle_aff(instructions_params_t *params)
{
    if (!is_valid_register(params->values[0]))
        return 1;
    my_putchar(params->champ->registers[params->values[0] - 1] % 256);
    return 0;
}
