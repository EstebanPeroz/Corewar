/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** instructions_struct_process
*/

#include "corewar.h"

void free_instruction_params(instructions_params_t *params)
{
    free(params);
}

instructions_params_t *init_instruction_params(
    virtual_machine_t *vm, int cycles, champions_t *champ)
{
    instructions_params_t *params = malloc(sizeof(instructions_params_t));

    if (!params)
        return NULL;
    params->vm = vm;
    params->cycles = cycles;
    params->champ = champ;
    return params;
}
