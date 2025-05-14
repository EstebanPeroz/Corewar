/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** tests_xor
*/

#include "corewar.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(corewar, test_handle_xor_reg_dir)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(3, av, vm);
    vm->champion->registers[1] = 50;
    int dir_value = 10;
    instructions_params_t params = {
        .vm = vm,
        .champ = vm->champion,
        .instruction = XOR_ID,
        .nb_params = 3,
        .values = {2, dir_value, 1},
        .types = {T_REG, T_DIR, T_REG}
    };

    handle_xor(&params);
    int expected_result = vm->champion->registers[1] ^ dir_value;
    cr_assert_eq(vm->champion->registers[0], expected_result);
    cr_assert_eq(vm->champion->carry, expected_result == 0 ? 1 : 0);
}

Test(corewar, test_handle_xor_reg_ind)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(3, av, vm);
    vm->champion->registers[1] = 0b11110000;
    int indirect_value = 0b10101010;
    int offset = 10;
    int address = (vm->champion->prog_counter + (offset % IDX_MOD) + MEM_SIZE) % MEM_SIZE;
    put_int_in_arena(vm->arena, address, indirect_value);
    instructions_params_t params = {
        .vm = vm,
        .champ = vm->champion,
        .instruction = XOR_ID,
        .nb_params = 3,
        .values = {2, offset, 1},
        .types = {T_REG, T_IND, T_REG}
    };

    int expected_result = vm->champion->registers[1] ^ indirect_value;
    handle_xor(&params);
    cr_assert_eq(vm->champion->registers[0], expected_result);
    cr_assert_eq(vm->champion->carry, expected_result == 0 ? 1 : 0);
}


Test(corewar, invalid_register_first_parameter_xor, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(3, av, vm);
    vm->champion->registers[1] = 50;
    int dir_value = 10;
    int saved_carry = 0;
    instructions_params_t params = {
        .vm = vm,
        .champ = vm->champion,
        .instruction = XOR_ID,
        .nb_params = 3,
        .values = {555, dir_value, 1},
        .types = {T_REG, T_DIR, T_REG}
    };

    int res = handle_xor(&params);
    cr_assert_eq(res, EXIT_FAILURE);
    cr_assert_eq(vm->champion->carry, saved_carry);
}

Test(corewar, invalid_register_others_parameters_xor, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(3, av, vm);
    vm->champion->registers[1] = 50;
    int dir_value = 10;
    int saved_carry = 0;
    instructions_params_t params = {
        .vm = vm,
        .champ = vm->champion,
        .instruction = XOR_ID,
        .nb_params = 3,
        .values = {2, dir_value, -84},
        .types = {T_REG, T_DIR, T_REG}
    };

    int res = handle_xor(&params);
    cr_assert_eq(res, EXIT_FAILURE);
    cr_assert_eq(vm->champion->carry, saved_carry);
}
