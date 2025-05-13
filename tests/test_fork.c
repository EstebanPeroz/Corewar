/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Test zjmp
*/
#include "corewar.h"
#include "op.h"
#include "structs.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/redirect.h>
#include <stdio.h>

const int fork_call = 7;

Test(corewar, test_handle_fork)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    vm->champion->prog_counter += fork_call;
    instructions_params_t params = { vm, 1, vm->champion };
    if (vm->arena[vm->champion->prog_counter] != 0x0c) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    handle_fork(&params);
    cr_assert_eq(vm->champion->cylces_to_wait, 800);
    cr_assert_eq(vm->champion->carry, 0);
    cr_assert_eq(vm->champion->prog_counter, fork_call + IND_SIZE);
    // Checking the forked champ
    cr_assert_eq(vm->champion->next->next->prog_counter, fork_call + 0x2e);
    cr_assert_eq(vm->champion->next->next->carry, 0);
}

