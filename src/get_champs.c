/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Champions retriever
*/
#include "op.h"
#include "corewar.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int init_node(champions_t **champ, char *file, options_t *opt)
{
    FILE *fd = fopen(file, "r");
    struct stat statbuf;

    stat(file, &statbuf);
    *champ = malloc(sizeof(champions_t));
    if (fd == NULL || *champ == NULL || !S_ISREG(statbuf.st_mode)) {
        my_puterr("ERROR: Invalid file.\n");
        return -1;
    }
    (*champ)->fd = fd;
    (*champ)->file = my_strdup(file);
    (*champ)->address = opt->address;
    (*champ)->id = opt->id;
    (*champ)->next = NULL;
    return 0;
}

int add_node(champions_t **head, char *filename, options_t *option)
{
    champions_t *tmp = *head;

    if (*head == NULL) {
        return init_node(head, filename, option);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    return init_node(&tmp->next, filename, option);
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
        options->address = my_getnbr(str[*i - 1]);
        return handle_options(head, str, i, options);
    }
    if (my_strcmp(str[*i], "-n") == 0) {
        *i += 2;
        if (!is_nbr(str[*i - 1]))
            return -1;
        options->id = my_getnbr(str[*i - 1]);
        return handle_options(head, str, i, options);
    }
    return 0;
}

// Divided by 4 for the moment. Needs to be the number of champs in the future
static int set_options(champions_t **tmp, int total_champs, int i,
    int *used_id)
{
    if (!is_valid_magic((*tmp)->fd)) {
        my_puterr("ERROR: specified file is not a champion.\n");
        return -1;
    }
    if ((*tmp)->id == -1) {
        (*tmp)->id = i;
    }
    for (int j = 0; j < i; j++) {
        if ((*tmp)->id == used_id[j]) {
            (*tmp)->id = i + 1;
        }
    }
    if ((*tmp)->address == -1)
        (*tmp)->address = (MEM_SIZE / total_champs) * (i - 1);
    used_id[i] = (*tmp)->id;
    return 0;
}

static int get_total_champs(champions_t **head)
{
    int nb = 0;
    champions_t *tmp = *head;

    while (tmp != NULL) {
        nb++;
        tmp = tmp->next;
    }
    if (nb < 2) {
        my_puterr("ERROR: missing champs.\n");
        return -1;
    }
    if (nb > 4) {
        my_puterr("ERROR: too many champs.\n");
        return -1;
    }
    return nb;
}

static int set_champs_params(champions_t **head)
{
    champions_t *tmp = *head;
    int i = 1;
    int used_id[4] = {-1, -1, -1, -1};
    int total_champs = get_total_champs(head);

    if (total_champs == -1 ||
    set_options(head, total_champs, 1, used_id) == -1)
        return -1;
    for (; tmp->next != NULL; i++) {
        if (set_options(&tmp->next, total_champs, i + 1, used_id) == -1)
            return -1;
        tmp = tmp->next;
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
        if (add_node(&champs, list[i], &option) == -1)
            return NULL;
        option.id = -1;
        option.address = -1;
    }
    if (set_champs_params(&champs) == -1)
        return NULL;
    return champs;
}
