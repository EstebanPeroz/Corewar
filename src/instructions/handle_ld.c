/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle ld isntruction
*/

#include "corewar.h"
#include "op.h"

int handle_ld(instructions_params_t *params)
{
    params->champ->carry = 1;
    return 1;
}
