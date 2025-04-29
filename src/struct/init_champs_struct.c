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
#include <string.h>

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

static void display_header(header_t *header)
{
    printf("Magic: %x\n", header->magic);
    printf("Name: %s\n", header->prog_name);
    printf("Size: %d\n", header->prog_size);
    printf("Comment: %s\n", header->comment);
}

static void display_champion(champions_t *champ)
{
    champions_t *current = champ;

    while (current != NULL) {
        printf("-------- Champion ID: %d --------------------\n",
            current->prog_id);
        printf("Champion Name: %s\n", current->name);
        printf("Champion Address: %d\n", current->address);
        printf("Champion Program Counter: %d\n", current->prog_counter);
        printf("Champion Cycles to Wait: %d\n", current->cylces_to_wait);
        printf("Champion Last Live: %d\n", current->last_live);
        printf("Champion Registers: ");
        for (int i = 0; i < REG_NUMBER; i++) {
            printf("%d ", current->registers[i]);
        }
        printf("\n");
        printf("Champion Code: ");
        for (int i = 0; i < current->header.prog_size; i++) {
            printf("%02x ", current->code[i]);
        }
        printf("\n");
        display_header(&current->header);
        current = current->next;
    }
}

champions_t *get_champs_with_options(char **list)
{
    champions_t *champs = NULL;
    options_t option = { -1, -1 };

    for (int i = 1; list[i] != NULL; i++) {
        if (handle_options(&champs, list, &i, &option) == -1)
            return NULL;
        if (fill_struct_champions(list[i], &champs, option.id, option.address) == EXIT_FAILURE)
            return NULL;
        option.id = -1;
        option.address = -1;
    }
    if (set_champs_params(&champs) == -1)
        return NULL;
    display_champion(champs);
    return champs;
}
