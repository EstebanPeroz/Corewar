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

const int ld_call = 10;

Test(corewar, test_handle_ld_reset_carry)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    vm->champion->prog_counter += ld_call;
    instructions_params_t *params = init_instruction_params(vm, 1, vm->champion, LD_ID + 1);
    int expected_loaded_value = vm->arena[(vm->champion->prog_counter + 76 % IDX_MOD) % MEM_SIZE];
    if (vm->arena[vm->champion->prog_counter] != LD_ID + 1) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    handle_ld(params);
    cr_assert_eq(vm->champion->carry, 0);
    cr_assert_eq(vm->champion->registers[0], expected_loaded_value);
}

Test(corewar, test_handle_lld_reset_carry)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    vm->champion->prog_counter += ld_call;
    instructions_params_t *params = init_instruction_params(vm, 1, vm->champion, LD_ID + 1);
    int expected_loaded_value = vm->arena[(vm->champion->prog_counter + 76 % IDX_MOD) % MEM_SIZE];
    if (vm->arena[vm->champion->prog_counter] != LD_ID + 1) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    handle_lld(params);
    cr_assert_eq(vm->champion->carry, 0);
    cr_assert_eq(vm->champion->registers[0], expected_loaded_value);
}

Test(corewar, test_handle_ld_set_carry_to_1)
{
    char *av[] = {"./corewar", "tests/ld_carry.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    instructions_params_t *params = init_instruction_params(vm, 1, vm->champion, LD_ID + 1);
    int expected_loaded_value = 0;
    if (vm->arena[vm->champion->prog_counter] != LD_ID + 1) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    handle_ld(params);
    fflush(NULL);
    cr_assert_eq(vm->champion->carry, 1);
    cr_assert_eq(vm->champion->registers[0], expected_loaded_value);
}

Test(corewar, test_handle_lld_set_carry_to_1)
{
    char *av[] = {"./corewar", "tests/ld_carry.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    instructions_params_t *params = init_instruction_params(vm, 1, vm->champion, LD_ID + 1);
    int expected_loaded_value = 0;
    if (vm->arena[vm->champion->prog_counter] != LD_ID + 1) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    handle_lld(params);
    fflush(NULL);
    cr_assert_eq(vm->champion->carry, 1);
    cr_assert_eq(vm->champion->registers[0], expected_loaded_value);
}

Test(corewar, test_handle_ldi_set_carry_to_1)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    vm->champion->prog_counter += ld_call;
    instructions_params_t *params = init_instruction_params(vm, 1, vm->champion, LD_ID + 1);
    int expected_loaded_value = read_bytes(vm->arena, (vm->champion->prog_counter + 76 % IDX_MOD) % MEM_SIZE, IND_SIZE) - 1799;
    if (vm->arena[vm->champion->prog_counter] != LD_ID + 1) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    params->values[2] = params->values[1];
    params->values[1] = -1799;
    handle_ldi(params);
    cr_assert_eq(vm->champion->carry, 1);
    cr_assert_eq(vm->champion->registers[0], expected_loaded_value);
}

Test(corewar, test_handle_ldi)
{
    char *av[] = {"./corewar", "tests/ld_carry.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    instructions_params_t *params = init_instruction_params(vm, 1, vm->champion, LD_ID + 1);
    int expected_loaded_value = 0 - 5;
    if (vm->arena[vm->champion->prog_counter] != LD_ID + 1) {
        printf("Current instruction: %i\n", vm->arena[vm->champion->prog_counter]);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    params->values[2] = params->values[1];
    params->values[1] = -5;
    handle_ldi(params);
    fflush(NULL);
    cr_assert_eq(vm->champion->carry, 0);
    cr_assert_eq(vm->champion->registers[0], expected_loaded_value);
}

