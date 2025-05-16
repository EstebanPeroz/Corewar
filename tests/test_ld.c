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

void put_short_in_arena(unsigned char *arena, int adrs, short value)
{
    int offset = 0;

    for (int i = 0; i < 2; i++) {
        offset = (adrs + i) % MEM_SIZE;
        if (offset < 0)
            offset += MEM_SIZE;
        arena[offset] = (value >> (8 * (1 - i))) & 0xFF;
    }
}

Test(corewar, test_handle_ld_reset_carry)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(5, av, vm);
    champions_t *champ = vm->champion;

    champ->prog_counter = 100;
    vm->arena[champ->prog_counter] = LD_ID + 1;
    int ind_offset = 76 % IDX_MOD;
    int addr = (champ->prog_counter + ind_offset) % MEM_SIZE;
    int test_value = 0x42;
    put_short_in_arena(vm->arena, addr, test_value);
    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = LD_ID + 1,
        .nb_params = 2,
        .types = {T_IND, T_REG},
        .values = {76, 1}
    };

    cr_assert_eq(vm->arena[champ->prog_counter], LD_ID + 1);
    handle_ld(&params);
    cr_assert_eq(champ->registers[0], test_value);
    cr_assert_eq(champ->carry, 0);
}

Test(corewar, test_handle_lld_reset_carry) {
    char *av[] = {"./corewar", "tests/pdd.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(5, av, vm);
    champions_t *champ = vm->champion;

    champ->prog_counter = 100;
    vm->arena[champ->prog_counter] = LD_ID + 1;
    int ind_offset = 76;
    int addr = (champ->prog_counter + ind_offset) % MEM_SIZE;
    int test_value = 0x42;
    put_short_in_arena(vm->arena, addr, test_value);
    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = LD_ID + 1,
        .nb_params = 2,
        .types = {T_IND, T_REG},
        .values = {76, 1}
    };

    cr_assert_eq(vm->arena[champ->prog_counter], LD_ID + 1);
    handle_lld(&params);
    cr_assert_eq(champ->registers[0], test_value);
    cr_assert_eq(champ->carry, 0);
}

Test(corewar, test_handle_ld_set_carry_to_1) {
    char *av[] = {"./corewar", "tests/ld_carry.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(5, av, vm);
    champions_t *champ = vm->champion;

    champ->prog_counter = 100;
    vm->arena[champ->prog_counter] = LD_ID + 1;
    int ind_offset = 76 % IDX_MOD;
    int addr = (champ->prog_counter + ind_offset) % MEM_SIZE;
    int test_value = 0;
    put_short_in_arena(vm->arena, addr, test_value);
    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = LD_ID + 1,
        .nb_params = 2,
        .types = {T_IND, T_REG},
        .values = {76, 1}
    };

    cr_assert_eq(vm->arena[champ->prog_counter], LD_ID + 1);
    handle_ld(&params);
    cr_assert_eq(champ->registers[0], test_value);
    cr_assert_eq(champ->carry, 1);
}

Test(corewar, test_handle_lld_set_carry_to_1) {
    char *av[] = {"./corewar", "tests/ld_carry.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(5, av, vm);
    champions_t *champ = vm->champion;

    champ->prog_counter = 100;
    vm->arena[champ->prog_counter] = LD_ID + 1;
    int ind_offset = 76;
    int addr = (champ->prog_counter + ind_offset) % MEM_SIZE;
    int test_value = 0;
    put_short_in_arena(vm->arena, addr, test_value);
    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = LD_ID + 1,
        .nb_params = 2,
        .types = {T_IND, T_REG},
        .values = {76, 1}
    };

    cr_assert_eq(vm->arena[champ->prog_counter], LD_ID + 1);
    handle_lld(&params);
    cr_assert_eq(champ->registers[0], test_value);
    cr_assert_eq(champ->carry, 1);
}

Test(corewar, test_handle_ldi_set_carry_to_1) {
    char *av[] = {"./corewar", "tests/pdd.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(5, av, vm);
    champions_t *champ = vm->champion;

    champ->prog_counter = 100;
    int ind_offset = (76) % IDX_MOD;
    int addr = (champ->prog_counter + ind_offset) % MEM_SIZE;
    int test_value = 4;
    put_short_in_arena(vm->arena, addr, test_value);
    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = LD_ID + 1,
        .nb_params = 3,
        .types = {T_IND, T_DIR, T_REG},
        .values = {76, 50, 2}
    };

    handle_ldi(&params);
    cr_assert_eq(champ->registers[1], test_value + 50);
    cr_assert_eq(champ->carry, 0);
}

Test(corewar, test_handle_ldi) {
    char *av[] = {"./corewar", "tests/ld_carry.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(5, av, vm);
    champions_t *champ = vm->champion;

    champ->prog_counter = 100;
    vm->arena[champ->prog_counter] = LD_ID + 1;
    int ind_offset = (-5 + -5) % IDX_MOD;
    int addr = (champ->prog_counter + ind_offset) % MEM_SIZE;
    int test_value = -10;
    put_short_in_arena(vm->arena, addr, test_value);
    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = LD_ID + 1,
        .nb_params = 3,
        .types = {T_DIR, T_DIR, T_REG},
        .values = {-5, -5, 1}
    };

    cr_assert_eq(vm->arena[champ->prog_counter], LD_ID + 1);
    handle_ldi(&params);
    cr_assert_eq(champ->registers[0], test_value);
    cr_assert_eq(champ->carry, 0);
}

Test(corewar, test_handle_lldi) {
    char *av[] = {"./corewar", "tests/ld_carry.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(5, av, vm);
    champions_t *champ = vm->champion;

    champ->prog_counter = 100;
    vm->arena[champ->prog_counter] = LD_ID + 1;
    int ind_offset = (-5 + -5);
    int addr = (champ->prog_counter + ind_offset) % MEM_SIZE;
    int test_value = -10;
    put_short_in_arena(vm->arena, addr, test_value);
    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = LD_ID + 1,
        .nb_params = 3,
        .types = {T_DIR, T_DIR, T_REG},
        .values = {-5, -5, 1}
    };

    cr_assert_eq(vm->arena[champ->prog_counter], LD_ID + 1);
    handle_lldi(&params);
    cr_assert_eq(champ->registers[0], test_value);
    cr_assert_eq(champ->carry, 0);
}

Test(corewar, test_handle_lldi_set_carry_to_1) {
    char *av[] = {"./corewar", "tests/pdd.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    fill_vm(5, av, vm);
    champions_t *champ = vm->champion;

    champ->prog_counter = 100;
    vm->arena[champ->prog_counter] = LD_ID + 1;
    int ind_offset = (76 + 0);
    int addr = (champ->prog_counter + ind_offset) % MEM_SIZE;
    int test_value = 0;
    put_short_in_arena(vm->arena, addr, test_value);
    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = LD_ID + 1,
        .nb_params = 3,
        .types = {T_IND, T_REG, T_REG},
        .values = {76, 1, 1}
    };

    cr_assert_eq(vm->arena[champ->prog_counter], LD_ID + 1);
    handle_lldi(&params);
    cr_assert_eq(champ->registers[0], test_value + 1);
    cr_assert_eq(champ->carry, 0);
}
