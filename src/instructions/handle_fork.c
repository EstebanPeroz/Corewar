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
    short new_adress = read_bytes(params->vm->arena,
        params->champ->prog_counter + 1, IND_SIZE);

    new_adress = params->champ->prog_counter + new_adress % IDX_MOD;
    fill_struct_champions(params->champ->file,
        &params->vm->champion, params->champ->prog_id, new_adress);
    printf("Champions %s forked at %d. Cycles: %d\n",
        params->champ->name, new_adress, params->cycles);
    return 1;
}
