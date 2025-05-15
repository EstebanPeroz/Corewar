/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** init_vm_struct
*/

#include "corewar.h"

virtual_machine_t *init_virtual_machine(int cycle_to_tump,
    int nb_processus)
{
    virtual_machine_t *virtual_machine = malloc(sizeof(virtual_machine_t));

    if (virtual_machine == NULL)
        return NULL;
    virtual_machine->cycle = 0;
    virtual_machine->nbr_processus = nb_processus;
    virtual_machine->nbr_processus_to_place = nb_processus;
    virtual_machine->cycle_to_dump = cycle_to_tump;
    virtual_machine->cycle_to_die = CYCLE_TO_DIE;
    virtual_machine->cycle_delta = CYCLE_DELTA;
    virtual_machine->nbr_live = NBR_LIVE;
    for (int i = 0; i < MEM_SIZE; i++) {
        virtual_machine->arena[i] = 0;
    }
    virtual_machine->champion = NULL;
    return virtual_machine;
}
