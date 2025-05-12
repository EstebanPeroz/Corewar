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

Test(corewar, test_handle_zjmp_no_carry)
{
    char *av[] = {"./corewar", "tests/mine.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    int first_PC = vm->champion->next->prog_counter += DIR_SIZE + 1;
    vm->champion->next->carry = 0;
    instructions_params_t params = { vm, 1, vm->champion->next };
    handle_zjmp(&params);
    cr_assert_eq(vm->champion->next->cylces_to_wait, 20);
    cr_assert_eq(vm->champion->next->carry, 0);
    cr_assert_eq(vm->champion->next->prog_counter, first_PC + IND_SIZE);
}

Test(corewar, test_handle_zjmp)
{
    char *av[] = {"./corewar", "tests/mine.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    vm->champion->next->prog_counter += DIR_SIZE + 1;
    if (vm->arena[vm->champion->next->prog_counter] != 9) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->next->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    vm->champion->next->carry = 1;
    int new_PC = vm->champion->next->prog_counter - 5;
    instructions_params_t params = { vm, 1, vm->champion->next };
    handle_zjmp(&params);
    cr_assert_eq(vm->champion->next->cylces_to_wait, 20);
    cr_assert_eq(vm->champion->next->carry, 1);
    cr_assert_eq(vm->champion->next->prog_counter, new_PC);
}
