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

static void change_variables(champions_t *cur, virtual_machine_t *vm,
    int *prog_counter, int cycles)
{
    *prog_counter += op_tab[0].type[0];
    vm->nbr_live--;
    cur->last_live = cycles;
    cur->cylces_to_wait = op_tab[0].nbr_cycles;
}

int handle_live(virtual_machine_t *vm, int cycles, int *prog_counter)
{
    champions_t *cur = vm->champion;
    int param;

    *prog_counter += 1;
    param = bytes_to_int((char *)vm->arena + *prog_counter);
    if (param == -1)
        return -1;
    while (cur != NULL) {
        if (param == cur->prog_id) {
            print_live_and_win_message(cur);
            my_putstr("is alive.\n");
            change_variables(cur, vm, prog_counter, cycles);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}
