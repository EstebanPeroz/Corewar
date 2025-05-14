/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** write_into_arena
*/

#include "corewar.h"

void put_int_in_arena(unsigned char *arena, int adrs, int value)
{
    int offset = 0;

    for (int i = 0; i < 4; i++) {
        offset = (adrs + i) % MEM_SIZE;
        if (offset < 0)
            offset += MEM_SIZE;
        arena[offset] = (value >> (8 * (3 - i))) & MAX_HEXA_BYTES;
    }
}
