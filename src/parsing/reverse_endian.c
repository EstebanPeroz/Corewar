/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** reverse_endian
*/

#include "corewar.h"

static void reverse_endian(int *value)
{
    unsigned char *byte = (unsigned char *)value;
    unsigned char temp;

    temp = byte[0];
    byte[0] = byte[3];
    byte[3] = temp;
    temp = byte[1];
    byte[1] = byte[2];
    byte[2] = temp;
}

void reverse_endian_header(header_t *header)
{
    reverse_endian(&header->magic);
    reverse_endian(&header->prog_size);
}