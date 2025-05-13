/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle ld instruction
*/

#include "corewar.h"

int handle_ld(instructions_params_t *params)
{
    int load_place = (params->champ->prog_counter +
        params->values[0] % IDX_MOD) % MEM_SIZE;

    params->champ->carry = 0;
    if (params->values[1] <= 0 || params->values[1] > 16)
        return 1;
    params->champ->registers[params->values[1] - 1] =
        params->vm->arena[load_place];
    if (params->champ->registers[params->values[1] - 1] == 0)
        params->champ->carry = 1;
    return 0;
}
