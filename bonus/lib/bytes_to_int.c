/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Transform 4 bytes to an int
*/
#include "corewar.h"
#include "op.h"

// Works for big endian directs
int bytes_to_int(unsigned char *arena, int pc)
{
    int to_ret;
    int first = pc % MEM_SIZE;
    int second = (pc + 1) % MEM_SIZE;
    int third = (pc + 2) % MEM_SIZE;
    int fourth = (pc + 3) % MEM_SIZE;

    if (arena == NULL)
        return -1;
    to_ret = (arena[first] << 24) | (arena[second] << 16)
        | (arena[third] << 8) | arena[fourth];
    return to_ret;
}

// Works for big endian indexs or indirects
short bytes_to_short(unsigned char *arena, int pc)
{
    short to_ret;
    int first = pc % MEM_SIZE;
    int second = (pc + 1) % MEM_SIZE;

    if (arena == NULL)
        return -1;
    to_ret = (arena[first] << 8) | arena[second];
    return to_ret;
}
