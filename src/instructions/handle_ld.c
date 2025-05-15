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
    if (!is_valid_register(params->values[1]))
        return 1;
    params->champ->registers[params->values[1] - 1]
        = read_bytes(params->vm->arena, load_place, REG_SIZE);
    if (params->champ->registers[params->values[1] - 1] == 0)
        params->champ->carry = 1;
    printf("chamion: %s ", params->champ->name);
    printf("prog c: %d ", params->champ->prog_counter);
    printf("LD: %d\n\n", params->values[0]);
    return 0;
}

int handle_lld(instructions_params_t *params)
{
    int load_place = (params->champ->prog_counter +
        params->values[0]) % MEM_SIZE;

    if (load_place < 0)
        load_place += MEM_SIZE;
    params->champ->carry = 0;
    if (!is_valid_register(params->values[1]))
        return 1;
    params->champ->registers[params->values[1] - 1] =
        read_bytes(params->vm->arena, load_place, REG_SIZE);
    if (params->champ->registers[params->values[1] - 1] == 0)
        params->champ->carry = 1;
    return 0;
}

// values[0] is the adress to read_bytes
// values[1] is the value to add to the previous one
// values[2] is the register
int handle_ldi(instructions_params_t *params)
{
    int load_place = (params->champ->prog_counter +
        params->values[0] % IDX_MOD) % MEM_SIZE;

    if (load_place < 0)
        load_place += MEM_SIZE;
    params->champ->carry = 0;
    if (!is_valid_register(params->values[2]))
        return 1;
    params->champ->registers[params->values[2] - 1]
        = read_bytes(params->vm->arena, load_place, IND_SIZE)
        + params->values[1];
    if (params->champ->registers[params->values[2] - 1] == 0)
        params->champ->carry = 1;
    return 0;
}

int handle_lldi(instructions_params_t *params)
{
    int load_place = (params->champ->prog_counter +
        params->values[0]) % MEM_SIZE;

    if (load_place < 0)
        load_place += MEM_SIZE;
    params->champ->carry = 0;
    if (!is_valid_register(params->values[2]))
        return 1;
    params->champ->registers[params->values[2] - 1]
        = read_bytes(params->vm->arena, load_place, IND_SIZE)
        + params->values[1];
    if (params->champ->registers[params->values[2] - 1] == 0)
        params->champ->carry = 1;
    return 0;
}
