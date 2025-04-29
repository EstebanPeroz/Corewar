/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Debug printer
*/
#include "corewar.h"
#include <stdio.h>

int print_champions(champions_t **head)
{
    champions_t *tmp = *head;

    while (tmp != NULL) {
        printf("File: %s, id: %i, address: %i", tmp->file, tmp->id, tmp->address);
        tmp = tmp->next;
    }
    return 0;
}
