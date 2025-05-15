/*
** EPITECH PROJECT, 2025
** my_puterr
** File description:
** put error
*/
#include "corewar.h"
#include <unistd.h>

int my_puterr(char const *str)
{
    write(2, str, my_strlen((char *)str));
    return 84;
}
