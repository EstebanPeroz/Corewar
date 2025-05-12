/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle zjmp
*/
#include "corewar.h"
#include "op.h"
#include <stdio.h>

int handle_zjmp(instructions_params_t *params)
{
    short index;

    if (params->champ->carry != 1) {
        params->champ->cylces_to_wait = op_tab[ZJMP_ID].nbr_cycles;
        return 0;
    }
    index = bytes_to_short(params->vm->arena +
        params->champ->prog_counter + 1);
    params->champ->prog_counter += index % IDX_MOD;
    params->champ->prog_counter %= MEM_SIZE;
    params->champ->cylces_to_wait = op_tab[ZJMP_ID].nbr_cycles;
    return 1;
}
