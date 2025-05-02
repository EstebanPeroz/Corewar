/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Check the cooldown before calling any instruction
*/
#include "structs.h"

int is_cooldown(champions_t **current)
{
    if ((*current)->cylces_to_wait > 0) {
        (*current)->cylces_to_wait--;
        *current = (*current)->next;
        return 1;
    }
    return 0;
}
