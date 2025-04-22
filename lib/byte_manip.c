/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** byte_manip
*/

#include "corewar.h"

long long inverse_byte_order(long long nb, size_t byte_nb)
{
    long long res = 0;

    for (size_t i = 1; i <= byte_nb; i++) {
        res |= (nb & 255) << ((byte_nb - i) * 8);
        nb >>= 8;
    }
    return res;
}
