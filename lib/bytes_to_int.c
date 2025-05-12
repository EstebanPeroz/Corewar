/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Transform 4 bytes to an int
*/
#include "corewar.h"

// Works for big endian indexs
int bytes_to_int(unsigned char *bytes)
{
    int to_ret;

    if (bytes == NULL)
        return -1;
    to_ret = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
    return to_ret;
}

short bytes_to_short(unsigned char *bytes)
{
    short to_ret;

    if (bytes == NULL)
        return -1;
    to_ret = (bytes[0] << 8) | bytes[1];
    return to_ret;
}
