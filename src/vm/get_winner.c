/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Get the winner
*/
#include "corewar.h"
#include "structs.h"

int get_winner(virtual_machine_t *vm)
{
    champions_t *current = vm->champion;
    champions_t winner = *current;

    while (current != NULL) {
        if (current->last_live > winner.last_live) {
            winner = *current;
        }
        current = current->next;
    }
    print_live_and_win_message(&winner);
    my_putstr("has won.\n");
    return 0;
}
