/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** get_instructions
*/

#include "corewar.h"

const op_t *get_instruction(int opcode)
{
    if (opcode >= 1 && opcode <= INSTRUCTIONS_NB)
        return &(op_tab[opcode - 1]);
    return NULL;
}
