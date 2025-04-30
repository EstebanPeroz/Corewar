/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Vm loop
*/
#include "corewar.h"
#include <stdio.h>

int vm_loop(virtual_machine_t *vm)
{
    printf("%d\n", vm->cycle_to_dump);
    return 0;
}
