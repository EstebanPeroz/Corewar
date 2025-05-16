/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Test fork
*/
#include "corewar.h"
#include "op.h"
#include "structs.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/redirect.h>
#include <stdio.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

const int fork_call = 7;

Test(corewar, test_handle_fork, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/cor_files/pdd.cor", "-n", "3", "tests/cor_files/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    vm->champion->prog_counter += fork_call;
    instructions_params_t params = { vm, 1, vm->champion, 0x0c, 1 , {0}, {0} };
    if (vm->arena[vm->champion->prog_counter] != 0x0c) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    handle_fork(&params);
    cr_assert_eq(vm->champion->carry, 0);
    cr_assert_eq(vm->champion->next->next->carry, 0);
}

Test(corewar, test_handle_lfork, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/cor_files/pdd.cor", "-n", "3", "tests/cor_files/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    vm->champion->prog_counter += fork_call;
    instructions_params_t params = { vm, 1, vm->champion, LFORK_ID + 1, 1 , {0}, {0} };
    if (vm->arena[vm->champion->prog_counter] != 0x0c) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    handle_lfork(&params);
    cr_assert_eq(vm->champion->carry, 0);
    cr_assert_eq(vm->champion->next->next->carry, 0);
}
