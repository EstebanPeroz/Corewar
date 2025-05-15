/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** get_instructions
*/

#include "corewar.h"

op_t get_instruction(int opcode)
{
    op_t err = {0, 0, {0}, 0, 0, 0, 0};

    if (opcode >= 1 && opcode <= INSTRUCTIONS_NB)
        return op_tab[opcode - 1];
    return err;
}
