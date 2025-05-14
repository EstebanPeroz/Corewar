/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** is_valid_register
*/

#include "corewar.h"

bool is_valid_register(int reg)
{
    return (reg >= 1 && reg <= REG_NUMBER);
}
