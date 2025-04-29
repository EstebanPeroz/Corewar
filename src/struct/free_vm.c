/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** free_vm
*/

#include "corewar.h"

void free_virtual_machine(virtual_machine_t *virtual_machine)
{
    free_champion(virtual_machine->champion);
    free(virtual_machine);
}
