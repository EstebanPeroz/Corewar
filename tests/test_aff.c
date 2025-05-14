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

const int aff_call = 80;

Test(corewar, test_handle_aff, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    vm->champion->prog_counter += aff_call;
    instructions_params_t *params = init_instruction_params(vm, 0, vm->champion, AFF_ID + 1);
    if (vm->arena[vm->champion->prog_counter] != AFF_ID + 1) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    vm->champion->registers[0] = 48;
    handle_aff(params);
    cr_assert_stdout_eq_str("0");
}

