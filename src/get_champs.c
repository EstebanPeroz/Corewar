/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Champions retriever
*/
#include "corewar.h"
#include <stdlib.h>

int *add_node(champions_t **head, char *filename)
{
    champions_t *tmp = *head;

    if (*head == NULL) {
        *head = malloc(sizeof(champions_t));
        (*head)->file = my_strdup(filename);
        (*head)->next = NULL;
        return 0;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(champions_t));
    tmp->next->file = my_strdup(filename);
    tmp->next->next = NULL;
    return 0;
}

champions_t *get_champs(char **list)
{
    champions_t *champs = NULL;

    for (int i = 0; list[i] != NULL; i++) {
        add_node(&champs, list[i]);
    }
    while (champs != NULL) {
        my_putstr(champs->file);
        my_putchar('\n');
        champs = champs->next;
    }
    return champs;
}
