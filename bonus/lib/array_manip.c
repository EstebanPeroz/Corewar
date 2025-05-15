/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** array_manip
*/

#include "corewar.h"

int get_array_len(void **array)
{
    int i = 0;

    if (array)
        for (; array[i] != NULL; i++);
    return i;
}

void **add_array_new_val(void **array, void *val)
{
    int len = get_array_len(array);
    void **new_array = realloc(array, sizeof(void *) * (len + 2));

    if (!new_array)
        return NULL;
    new_array[len] = val;
    new_array[len + 1] = NULL;
    return new_array;
}
