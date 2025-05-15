/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Get the list of alive champs
*/
#include "structs.h"
#include "corewar.h"
#include <stdio.h>

int reset_cycles(virtual_machine_t *vm, int *cycles)
{
    champions_t *current = vm->champion;

    vm->alive_champions = 0;
    *cycles = 1;
    while (current != NULL) {
        current->last_live = -1;
        current = current->next;
    }
    return 0;
}

int get_alive_champions(virtual_machine_t *vm, int cycles)
{
    champions_t *current = vm->champion;

    if (cycles < vm->cycle_to_die)
        return 0;
    while (current != NULL) {
        if (current->last_live != -1) {
            vm->alive_champions++;
        } else {
            current->is_alive = 0;
        }
        current = current->next;
    }
    return 1;
}
