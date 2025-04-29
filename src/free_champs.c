/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Free champ struct
*/
#include "corewar.h"
#include <stdio.h>

int free_champs(champions_t **head)
{
    champions_t *tmp = *head;
    champions_t *next = tmp->next;

    while (tmp != NULL) {
        free(tmp->file);
        fclose(tmp->fd);
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    return 0;
}
