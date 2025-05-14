/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** sub_tests
*/

#include "corewar.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(corewar, test_handle_sub_basic)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->registers[0] = 32;
    champ->registers[1] = 10;
    champ->registers[2] = 0;
    champ->carry = 0;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = ADD_ID,
        .nb_params = 3,
        .types = {T_REG, T_REG, T_REG},
        .values = {1, 2, 3} 
    };

    handle_sub(&params);
    cr_assert_eq(champ->registers[2], 22, "add: expected r3 == 42 but got %d", champ->registers[2]);
    cr_assert_eq(champ->carry, 0, "add: expected carry == 0 but got %d", champ->carry);
}

Test(corewar, invalid_type_sub, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->registers[0] = 10;
    champ->registers[1] = 32;
    champ->registers[2] = 0;
    champ->carry = 0;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = ADD_ID,
        .nb_params = 3,
        .types = {T_REG, T_IND, T_DIR},
        .values = {1, 2, 3} 
    };

    int res = handle_sub(&params);
    cr_assert_eq(res, EXIT_FAILURE);
    cr_assert_eq(champ->carry, 0);
}

Test(corewar, not_valid_register_sub, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->registers[0] = 10;
    champ->registers[1] = 32;
    champ->registers[2] = 0;
    champ->carry = 0;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = ADD_ID,
        .nb_params = 3,
        .types = {T_REG, T_REG, T_REG},
        .values = {44, 296, 3} 
    };

    int res = handle_sub(&params);
    cr_assert_eq(res, EXIT_FAILURE);
    cr_assert_eq(champ->carry, 0);
}
