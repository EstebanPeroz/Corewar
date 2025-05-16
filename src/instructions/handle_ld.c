/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle ld instruction
*/

#include "corewar.h"
#include "op.h"

int handle_ld(instructions_params_t *pa)
{
    int value = 0;
    int load_place = 0;

    if (!is_valid_register(pa->values[1]))
        return EXIT_FAILURE;
    if (pa->types[0] == T_DIR)
        value = pa->values[0];
    else if (pa->types[0] == T_IND) {
        load_place = (pa->champ->prog_counter
            + (pa->values[0] % IDX_MOD)) % MEM_SIZE;
        value = read_bytes(pa->vm->arena, load_place, IND_SIZE);
    } else {
        return EXIT_FAILURE;
    }
    pa->champ->registers[pa->values[1] - 1] = value;
    pa->champ->carry = (value == 0) ? 1 : 0;
    return 0;
}

int handle_lld(instructions_params_t *pa)
{
    int value = 0;
    int load_place = 0;

    if (!is_valid_register(pa->values[1]))
        return EXIT_FAILURE;
    if (pa->types[0] == T_DIR)
        value = pa->values[0];
    else if (pa->types[0] == T_IND) {
        load_place = (pa->champ->prog_counter
            + pa->values[0]) % MEM_SIZE;
        value = read_bytes(pa->vm->arena, load_place, IND_SIZE);
    } else {
        return EXIT_FAILURE;
    }
    pa->champ->registers[pa->values[1] - 1] = value;
    pa->champ->carry = (value == 0) ? 1 : 0;
    return 0;
}

int handle_ldi(instructions_params_t *p)
{
    int v1 = p->values[0];
    int v2 = p->values[1];
    int dest = p->values[2];
    int result = 0;

    if (!is_valid_register(dest))
        return EXIT_FAILURE;
    if (p->types[0] == T_REG)
        v1 = p->champ->registers[v1 - 1];
    else if (p->types[0] == T_IND) {
        v1 = read_bytes(p->vm->arena,
            (p->champ->prog_counter + (v1 % IDX_MOD)) % MEM_SIZE, IND_SIZE);
        }
    if (p->types[1] == T_REG)
        v2 = p->champ->registers[v2 - 1];
    result = v1 + v2;
    p->champ->registers[dest - 1] = result;
    p->champ->carry = (result == 0);
    return 0;
}

int handle_lldi(instructions_params_t *p)
{
    int v1 = p->values[0];
    int v2 = p->values[1];
    int dest = p->values[2];
    int result = 0;

    if (!is_valid_register(dest))
        return EXIT_FAILURE;
    if (p->types[0] == T_REG)
        v1 = p->champ->registers[v1 - 1];
    else if (p->types[0] == T_IND)
        v1 = read_bytes(p->vm->arena,
            (p->champ->prog_counter + v1) % MEM_SIZE, IND_SIZE);
    if (p->types[1] == T_REG)
        v2 = p->champ->registers[v2 - 1];
    result = v1 + v2;
    p->champ->registers[dest - 1] = result;
    p->champ->carry = (result == 0);
    return 0;
}
