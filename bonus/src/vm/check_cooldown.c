/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Check the cooldown before calling any instruction
*/
#include "op.h"
#include "structs.h"

int decrease_cycle_to_die(virtual_machine_t *vm)
{
    if (vm->nbr_live <= 0) {
        vm->nbr_live += NBR_LIVE;
        vm->cycle_to_die -= CYCLE_DELTA;
        return 1;
    }
    return 0;
}

int is_cooldown(champions_t **current)
{
    if ((*current)->cylces_to_wait > 0) {
        (*current)->cylces_to_wait--;
        *current = (*current)->next;
        return 1;
    }
    return 0;
}
