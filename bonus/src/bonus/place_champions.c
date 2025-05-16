/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** place_champions
*/

#include "corewar.h"

void place_champion(virtual_machine_t *virtual_machine,
    champions_t *champion, int id)
{
    int adress = champion->address;

    for (int i = 0; i < champion->header.prog_size; i++) {
        virtual_machine->arena[(adress + i) % MEM_SIZE] = champion->code[i];
        virtual_machine->owner_map[(adress + i) % MEM_SIZE] = id;
    }
    champion->is_placed = true;
}

static bool is_processus_with_adress(virtual_machine_t *virtual_machine)
{
    champions_t *current = virtual_machine->champion;

    while (current != NULL) {
        if (current->address != DEFAULT_ADRESS) {
            return true;
        }
        current = current->next;
    }
    return false;
}

champions_t *get_champion_to_place(virtual_machine_t *vm)
{
    champions_t *champ = vm->champion;

    while (champ != NULL) {
        if (!champ->is_placed) {
            return champ;
        }
        champ = champ->next;
    }
    return NULL;
}

static void place_processus_auto(virtual_machine_t *virtual_machine)
{
    champions_t *current = virtual_machine->champion;
    int auto_adress = 0;
    int distance = MEM_SIZE / virtual_machine->nbr_processus;

    while (current != NULL) {
        current->address = auto_adress;
        current->prog_counter = auto_adress;
        auto_adress += distance;
        place_champion(virtual_machine, current,
            virtual_machine->placed_champs + 1);
        virtual_machine->placed_champs += 1;
        current = current->next;
    }
}

static void place_processus_with_address(virtual_machine_t *virtual_machine)
{
    champions_t *current = virtual_machine->champion;

    while (current != NULL) {
        if (current->address != DEFAULT_ADRESS) {
            place_champion(virtual_machine, current,
                virtual_machine->placed_champs + 1);
            virtual_machine->placed_champs += 1;
            virtual_machine->nbr_processus_to_place--;
        }
        current = current->next;
    }
}

static void place_remaining_processus(virtual_machine_t *virtual_machine)
{
    free_space_t free_space;
    champions_t *champ_to_place = NULL;
    int adress = 0;

    while (virtual_machine->nbr_processus_to_place > 0) {
        free_space = find_largest_free_space(virtual_machine);
        champ_to_place = get_champion_to_place(virtual_machine);
        if (champ_to_place == NULL)
            break;
        adress = free_space.start + (free_space.size / 2);
        champ_to_place->address = adress;
        place_champion(virtual_machine, champ_to_place,
            virtual_machine->placed_champs + 1);
        virtual_machine->placed_champs += 1;
        virtual_machine->nbr_processus_to_place--;
    }
}

void place_all_processus(virtual_machine_t *virtual_machine)
{
    virtual_machine->placed_champs = 0;
    if (!is_processus_with_adress(virtual_machine)) {
        place_processus_auto(virtual_machine);
    } else {
        place_processus_with_address(virtual_machine);
        place_remaining_processus(virtual_machine);
    }
}
