/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** manage_address
*/

#include "corewar.h"

static void verify_other_champ_adress(champions_t *champ, int adress,
    int prog_size)
{
    champions_t *current = champ;

    while (current != NULL) {
        if (current->address < 0 || !(current->address < adress)
            || !(current->address > adress + prog_size)) {
            current->address = DEFAULT_ADRESS;
        }
        current = current->next;
    }
}

void manage_adress(champions_t *champ)
{
    champions_t *current = champ;

    while (current != NULL) {
        if (current->next != NULL && current->address > 0) {
            verify_other_champ_adress(current->next, current->address,
                current->header.prog_size);
        }
        current = current->next;
    }
}
