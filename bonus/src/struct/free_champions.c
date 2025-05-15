/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** free_champions
*/

#include "corewar.h"

void free_champion(champions_t *champ)
{
    champions_t *current = champ;
    champions_t *next;

    while (current != NULL) {
        free(current->name);
        free(current->code);
        fclose(current->fd);
        next = current->next;
        free(current);
        current = next;
    }
}
