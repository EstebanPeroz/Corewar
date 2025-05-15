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
        op_t op;
        unsigned char opcode;

    new_adress = params->champ->prog_counter + new_adress % IDX_MOD;
    fill_struct_champions(params->champ->file,
        &params->vm->champion, params->champ->prog_id, new_adress);
    opcode = params->vm->arena[params->champ->prog_counter % MEM_SIZE];
    op = get_instruction(opcode);
    if (op.code != 0) {
        params->champ->cylces_to_wait = op.nbr_cycles;
    } else {
        params->champ->cylces_to_wait = 0;
    }
    return 1;
}
