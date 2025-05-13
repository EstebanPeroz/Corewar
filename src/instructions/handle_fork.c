/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle fork
*/
#include "corewar.h"
#include "op.h"
#include "structs.h"

int handle_fork(instructions_params_t *params)
{
    short new_adress = bytes_to_short(params->vm->arena +
        params->champ->prog_counter + 1);

    new_adress = params->champ->prog_counter + new_adress % IDX_MOD;
    fill_struct_champions(params->champ->file,
        &params->vm->champion, params->champ->prog_id, new_adress);
    return 1;
}
