/*
** EPITECH PROJECT, 2025
** map
** File description:
** map printer
*/
#include "corewar.h"

int my_put_map(char **map)
{
    if (!map || !map[0])
        return -1;
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar(' ');
    }
    return 0;
}
