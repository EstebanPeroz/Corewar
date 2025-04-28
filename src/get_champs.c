/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Champions retriever
*/
#include "corewar.h"
#include <stdbool.h>
#include <stdlib.h>

static void init_node(champions_t **champ, char *file, options_t *opt)
{
    *champ = malloc(sizeof(champions_t));
    (*champ)->file = my_strdup(file);
    (*champ)->address = opt->address;
    (*champ)->id = opt->id;
    (*champ)->next = NULL;
}

int *add_node(champions_t **head, char *filename, options_t *option)
{
    champions_t *tmp = *head;

    if (*head == NULL) {
        init_node(head, filename, option);
        return 0;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    init_node(&tmp->next, filename, option);
    return 0;
}

int handle_options(champions_t **head, char **str, int *i, options_t *options)
{
    for (int j = 0; j < 3; j++)
        if (str[*i][0] == '-' && str[*i + j] == NULL)
            return -1;
    if (my_strcmp(str[*i], "-a") == 0) {
        *i += 2;
        if (!is_nbr(str[*i - 1]))
            return -1;
        options->address = atoi(str[*i - 1]);
        return handle_options(head, str, i, options);
    }
    if (my_strcmp(str[*i], "-n") == 0) {
        *i += 2;
        if (!is_nbr(str[*i - 1]))
            return -1;
        options->id = atoi(str[*i - 1]);
        return handle_options(head, str, i, options);
    }
    return 0;
}

champions_t *get_champs(char **list)
{
    champions_t *champs = NULL;
    options_t option = { -1, -1 };

    for (int i = 1; list[i] != NULL; i++) {
        if (handle_options(&champs, list, &i, &option) == -1)
            return NULL;
        add_node(&champs, list[i], &option);
    }
    return champs;
}
