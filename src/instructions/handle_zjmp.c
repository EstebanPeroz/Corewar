/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle zjmp
*/
#include "corewar.h"
#include "op.h"

int handle_zjmp(instructions_params_t *params)
{
    short index;

    if (params->champ->carry != 1) {
        params->champ->prog_counter += (1 + IND_SIZE) % IDX_MOD;
        params->champ->prog_counter %= MEM_SIZE;
        return 0;
    }
    index = read_bytes(params->vm->arena,
        params->champ->prog_counter + 1, IND_SIZE);
    params->champ->prog_counter += index % IDX_MOD;
    params->champ->prog_counter %= MEM_SIZE;
    return 1;
}
