/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Vm loop with cooldown and parameter decoding + debug
*/
#include "corewar.h"
#include "op.h"
#include "structs.h"
#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include <string.h>

int (* const funcs[INSTRUCTIONS_NB])(instructions_params_t *) = {
    handle_live, handle_ld, handle_st, handle_add,
    handle_sub, handle_and, handle_or, handle_xor,
    handle_zjmp, handle_ldi, handle_sti, handle_fork,
    handle_lld, handle_lldi, handle_lfork, handle_aff
};

static void call_instruction_functions(virtual_machine_t *vm,
    int cycles, champions_t *champ, int opcode)
{
    const op_t op = get_instruction(opcode);
    instructions_params_t *params = NULL;

    if (op.code == 0)
        return;
    params = init_instruction_params(vm, cycles, champ, opcode);
    if (!params || opcode > INSTRUCTIONS_NB)
        return;
    funcs[opcode - 1](params);
    free_instruction_params(params);
}

static void handle_champion_instruction(virtual_machine_t *vm,
    champions_t *champ, int cycles)
{
    unsigned char opcode = vm->arena[champ->prog_counter % MEM_SIZE];
    op_t op = get_instruction(opcode);
    int new_offset = 0;

    if (is_cooldown(champ) || !champ->is_alive)
        return;
    if (op.code == 0) {
        champ->prog_counter = (champ->prog_counter + 1) % MEM_SIZE;
        return;
    }
    call_instruction_functions(vm, cycles, champ, opcode);
    if (op.code != ZJMP_ID + 1) {
        new_offset += update_prog_counter(vm, champ, &op);
        champ->prog_counter = (champ->prog_counter + new_offset) % MEM_SIZE;
    }
    op = get_instruction(vm->arena[champ->prog_counter % MEM_SIZE]);
    champ->cylces_to_wait = op.nbr_cycles;
}

int handle_instructions(virtual_machine_t *vm, int cycles)
{
    champions_t *current = vm->champion;

    while (current != NULL) {
        handle_champion_instruction(vm, current, cycles);
        current = current->next;
    }
    return 0;
}

int vm_loop(virtual_machine_t *vm)
{
    int last_dump = 1;

    for (int cycles = 1; (cycles <= vm->cycle_to_die
    || vm->alive_champions > 1) &&
    sfRenderWindow_isOpen(vm->display->window); cycles++) {
        if (vm->display->sim_timer >= vm->display->sim_delay) {
            if (cycles > vm->cycle_to_die)
                reset_cycles(vm, &cycles);
            handle_instructions(vm, cycles);
            get_alive_champions(vm, cycles);
            handle_dump(vm, &last_dump);
            decrease_cycle_to_die(vm);
            vm->display->sim_timer = 0;
        }
        draw_arena(vm, vm->display);
    }
    if (sfRenderWindow_isOpen(vm->display->window))
        sfRenderWindow_close(vm->display->window);
    get_winner(vm);
    return 0;
}
