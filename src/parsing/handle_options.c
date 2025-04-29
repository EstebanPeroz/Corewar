/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** handle_options
*/

#include "corewar.h"


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

int set_options(champions_t **tmp, int total_champs, int i,
    int *used_id)
{
    if (!is_valid_magic((*tmp)->fd)) {
        my_puterr("ERROR: specified file is not a champion.\n");
        return -1;
    }
    if ((*tmp)->prog_id == -1) {
        (*tmp)->prog_id = i;
    }
    for (int j = 0; j < i; j++) {
        if ((*tmp)->prog_id == used_id[j]) {
            (*tmp)->prog_id = i + 1;
        }
    }
    return 0;
}
