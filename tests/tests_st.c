/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** tests_st
*/

#include "corewar.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(corewar, test_handle_st_register, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 1234;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = ST_ID,
        .nb_params = 2,
        .values = {1, 2},
        .types = {T_REG, T_REG}
    };

    handle_st(&params);
    cr_assert_eq(champ->registers[1], 1234);
}

Test(corewar, test_handle_st_indirect, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0x12345678;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = ST_ID,
        .nb_params = 2,
        .values = {1, 50},
        .types = {T_REG, T_IND}
    };

    handle_st(&params);
    int addr = (100 + (50 % IDX_MOD)) % MEM_SIZE;
    int value = read_bytes(vm->arena, addr, T_IND);
    cr_assert_eq(value, 0x12345678);
}

Test(corewar, not_a_registre_first_params, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0x12345678;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = ST_ID,
        .nb_params = 2,
        .values = {1, 50},
        .types = {T_IND, T_IND}
    };

    int res = handle_st(&params);
    cr_assert_eq(res, EXIT_FAILURE);
}

Test(corewar, not_a_valid_register, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0x12345678;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = ST_ID,
        .nb_params = 2,
        .values = {55, 50},
        .types = {T_REG, T_IND}
    };

    int res = handle_st(&params);
    cr_assert_eq(res, EXIT_FAILURE);
}

Test(corewar, invalid_params_type, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0x12345678;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = ST_ID,
        .nb_params = 2,
        .values = {1, 50},
        .types = {T_REG, T_DIR}
    };

    int res = handle_st(&params);
    cr_assert_eq(res, EXIT_FAILURE);
}

Test(corewar, invalid_register_second_parameter, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0x12345678;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = ST_ID,
        .nb_params = 2,
        .values = {1, 50},
        .types = {T_REG, T_REG}
    };

    int res = handle_st(&params);
    cr_assert_eq(res, EXIT_FAILURE);
}
