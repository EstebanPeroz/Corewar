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
    int cycles)
{
    vm->nbr_live--;
    cur->last_live = cycles;
}

int handle_live(instructions_params_t *params)
{
    printf("handle_live: ");
    champions_t *cur = params->vm->champion;
    int champ_id;

    champ_id = read_bytes(params->vm->arena,
        params->champ->prog_counter + 1, DIR_SIZE);
    printf("champ_id: %d ", champ_id);
    printf("chamion: %s ", params->champ->name);
    printf("prog c: %d Cycles: %d\n\n", params->champ->prog_counter, 
        params->cycles);
    if (champ_id == -1)
        return -1;
    while (cur != NULL) {
        if (champ_id == cur->prog_id && cur->is_alive) {
            print_live_and_win_message(cur);
            my_putstr("is alive.\n");
            change_variables(cur, params->vm,
                params->cycles);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}
