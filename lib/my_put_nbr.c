/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** my_put_nbr
*/
#include "corewar.h"

static void printer(long long nb)
{
    long long i;
    int nb_h;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb == 0) {
        my_putchar('0');
    }
    for (i = nb; i != 0; i = i / 10) {
        nb_h = i % 10;
        my_putchar(nb_h + 48);
    }
}

int my_put_nbr(int nb)
{
    long long mul = 0;
    long long nbl = nb;
    int z = 0;

    for (; nbl != 0; nbl = nbl / 10) {
        mul = mul * 10 + nbl % 10;
        if (mul == 0) {
            z++;
        }
    }
    printer(mul);
    for (; z != 0; z--) {
        my_putchar('0');
    }
    return 0;
}
