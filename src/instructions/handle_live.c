/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Handle the live instruction
*/
#include "corewar.h"
#include "op.h"
#include "structs.h"

void print_live_and_win_message(champions_t *champ)
{
    my_putstr("The player ");
    my_put_nbr(champ->prog_id);
    my_putchar('(');
    my_putstr(champ->header.prog_name);
    my_putchar(')');
}

int handle_live(virtual_machine_t *vm, int cycles, int *prog_counter)
{
    champions_t *cur = vm->champion;
    int param;

    *prog_counter += 1;
    param = bytes_to_int(vm->arena + *prog_counter);
    if (param == -1)
        return 0;
    while (cur != NULL) {
        if (param == cur->prog_id) {
            cur->last_live = cycles;
            print_live_and_win_message(cur);
            my_putstr("is alive.\n");
            *prog_counter += op_tab[0].type[0];
            cur->cylces_to_wait = op_tab[0].nbr_cycles;
        }
        cur = cur->next;
    }
    return 1;
}
