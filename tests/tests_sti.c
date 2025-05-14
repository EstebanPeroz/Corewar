/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** test_sti
*/

#include "corewar.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(corewar, test_handle_sti_reg_reg_reg, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0xCAFEBABE;
    champ->registers[1] = 10;
    champ->registers[2] = 30;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = STI_ID,
        .nb_params = 3,
        .values = {1, 2, 3},
        .types = {T_REG, T_REG, T_REG}
    };

    handle_sti(&params);
    int offset = (10 + 30) % IDX_MOD;
    int addr = (100 + offset) % MEM_SIZE;
    int value = read_bytes(vm->arena, addr, T_IND);
    cr_assert_eq(value, 0xCAFEBABE);
}

Test(corewar, test_handle_sti_reg_ind_dir, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0xCAFEBABE;
    champ->registers[1] = 10;
    champ->registers[2] = 30;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = STI_ID,
        .nb_params = 3,
        .values = {1, 2, 3},
        .types = {T_REG, T_IND, T_DIR}
    };

    handle_sti(&params);
    int offset = (10 + 30) % IDX_MOD;
    int addr = (100 + offset) % MEM_SIZE;
    int value = read_bytes(vm->arena, addr, T_IND);
    cr_assert_eq(value, 0);
}

Test(corewar, invalid_register_second_or_third, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0xCAFEBABE;
    champ->registers[1] = 10;
    champ->registers[2] = 30;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = STI_ID,
        .nb_params = 3,
        .values = {1, 598, 3},
        .types = {T_REG, T_REG, T_REG}
    };

    handle_sti(&params);
    int offset = (10 + 30) % IDX_MOD;
    int addr = (100 + offset) % MEM_SIZE;
    int value = read_bytes(vm->arena, addr, T_IND);
    cr_assert_eq(value, 0);
}

Test(corewar, invalid_register_first, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0xCAFEBABE;
    champ->registers[1] = 10;
    champ->registers[2] = 30;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = STI_ID,
        .nb_params = 3,
        .values = {485, 2, 3},
        .types = {T_REG, T_REG, T_REG}
    };

    handle_sti(&params);
    int offset = (10 + 30) % IDX_MOD;
    int addr = (100 + offset) % MEM_SIZE;
    int value = read_bytes(vm->arena, addr, T_IND);
    cr_assert_eq(value, 0);
}

Test(corewar, sti_invalid_type, .init = redirect_all_std)
{
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    champions_t *champ = calloc(1, sizeof(champions_t));
    champ->prog_counter = 100;
    champ->registers[0] = 0xCAFEBABE;
    champ->registers[1] = 10;
    champ->registers[2] = 30;
    vm->champion = champ;
    instructions_params_t params = {
        .vm = vm,
        .champ = champ,
        .instruction = STI_ID,
        .nb_params = 3,
        .values = {1, 2, 3},
        .types = {T_REG, 5, T_REG}
    };

    handle_sti(&params);
    int offset = (10 + 30) % IDX_MOD;
    int addr = (100 + offset) % MEM_SIZE;
    int value = read_bytes(vm->arena, addr, T_IND);
    cr_assert_eq(value, 0);
}
