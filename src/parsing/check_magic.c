/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Check champ magic nb
*/
#include "corewar.h"
#include "op.h"

int inverse_byte_order(int nb, size_t byte_nb)
{
    long long res = 0;

    for (size_t i = 1; i <= byte_nb; i++) {
        res |= (nb & 255) << ((byte_nb - i) * 8);
        nb >>= 8;
    }
    return res;
}

int is_valid_magic(FILE *fd)
{
    header_t buf;

    fread(&buf, 1, sizeof(header_t), fd);
    if (inverse_byte_order(buf.magic, sizeof(int)) == COREWAR_EXEC_MAGIC) {
        return 1;
    }
    return 0;
}
