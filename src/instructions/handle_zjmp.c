/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle zjmp
*/
#include "corewar.h"
#include "op.h"

static void change_variables(champions_t *cur, int *prog_counter)
{
    *prog_counter += op_tab[ZJMP_ID].type[0];
    cur->cylces_to_wait = op_tab[ZJMP_ID].nbr_cycles;
}

int handle_zjmp(instructions_params_t *params)
{
    short index;

    if (params->champ->carry != 1) {
        change_variables(params->champ, &params->champ->prog_counter);
        return 0;
    }
    index = bytes_to_short(params->vm->arena +
        params->champ->prog_counter) - 1;
    if (index == -1)
        return -1;
    params->champ->prog_counter += index % IDX_MOD;
    params->champ->cylces_to_wait = op_tab[ZJMP_ID].nbr_cycles;
    return 1;
}
