/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Get arguments
*/
#include "corewar.h"

#include <string.h>

int is_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int get_cycles(char ***av, int ac)
{
    if (ac < 5 || (*av)[2][0] == '-')
        return -1;
    if (!is_nbr((*av)[2]))
        return -1;
    *av += 2;
    return my_getnbr((*av)[2]);
}
