/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle zjmp
*/
#include "corewar.h"

static void change_variables(champions_t *cur, int *prog_counter)
{
    *prog_counter += op_tab[ZJMP_ID].type[0];
    cur->cylces_to_wait = op_tab[ZJMP_ID].nbr_cycles;
}

int handle_zjmp(instructions_params_t *params)
{
    if (params->champ->carry == 0) {
        change_variables(params->champ, &params->champ->prog_counter);
        return 0;
    }
    return 0;
}
