/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Champions retriever
*/

#include "corewar.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int get_total_champs(champions_t **head)
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
    set_options(head, 1, used_id) == -1)
        return -1;
    for (; tmp->next != NULL; i++) {
        if (set_options(&tmp->next, i + 1, used_id) == -1)
            return -1;
        tmp->registers[0] = tmp->prog_id;
        tmp = tmp->next;
    }
    tmp->registers[0] = tmp->prog_id;
    return 0;
}

static bool file_exist(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        close(fd);
        return false;
    }
    close(fd);
    return true;
}

static bool process_champion(champions_t **champs, char **list, int *i,
    options_t *option)
{
    if (handle_options(champs, list, i, option) == -1 || !file_exist(list[*i]))
        return false;
    if (fill_struct_champions(list[*i], champs, option->id, option->address)
        == EXIT_FAILURE)
        return false;
    option->id = -1;
    option->address = -1;
    return true;
}

champions_t *get_champs_with_options(char **list)
{
    champions_t *champs = NULL;
    options_t option = { -1, -1 };

    for (int i = 1; list[i] != NULL; i++) {
        if (!process_champion(&champs, list, &i, &option)) {
            free_champion(champs);
            return NULL;
        }
    }
    if (set_champs_params(&champs) == -1) {
        free_champion(champs);
        return NULL;
    }
    return champs;
}
