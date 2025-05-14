/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle ld instruction
*/

#include "corewar.h"
#include "op.h"

int handle_ld(instructions_params_t *params)
{
    int load_place = (params->champ->prog_counter +
        params->values[0] % IDX_MOD) % MEM_SIZE;

    if (load_place < 0)
        load_place += MEM_SIZE;
    params->champ->carry = 0;
    if (params->values[1] <= 0 || params->values[1] > 16)
        return 1;
    params->champ->registers[params->values[1] - 1]
        = read_bytes(params->vm->arena, load_place, REG_SIZE);
    if (params->champ->registers[params->values[1] - 1] == 0)
        params->champ->carry = 1;
    return 0;
}

int handle_lld(instructions_params_t *params)
{
    int load_place = (params->champ->prog_counter +
        params->values[0]) % MEM_SIZE;

    if (load_place < 0)
        load_place += MEM_SIZE;
    params->champ->carry = 0;
    if (params->values[1] <= 0 || params->values[1] > 16)
        return 1;
    params->champ->registers[params->values[1] - 1] =
        read_bytes(params->vm->arena, load_place, REG_SIZE);
    if (params->champ->registers[params->values[1] - 1] == 0)
        params->champ->carry = 1;
    return 0;
}
