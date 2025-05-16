/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Test the loop
*/
#include "corewar.h"
#include "structs.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/redirect.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(corewar, test_reset_cycles)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    int cycle;
    
    fill_vm(3, av, vm);
    vm->champion->last_live = 2;
    cycle = vm->cycle_to_die - 1;
    cr_assert_eq(vm->champion->last_live, 2);
    reset_cycles(vm, &cycle);
    cr_assert_eq(vm->champion->last_live, -1);
    cr_assert_eq(cycle, 1);
}

Test(corewar, test_find_winner, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(3, av, vm);
    vm->champion->last_live = 2;
    get_winner(vm);
    cr_assert_stdout_eq_str("The player 1(pdd)has won.\n");
}

Test(corewar, test_find_winner2, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(3, av, vm);
    vm->champion->next->last_live = 4;
    get_winner(vm);
    cr_assert_stdout_eq_str("The player 2(Abel)has won.\n");
}

Test(corewar, test_find_winner_no_live_calls, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "56", "tests/pdd.cor", "-n", "299", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(7, av, vm);
    get_winner(vm);
    cr_assert_stdout_eq_str("The player 56(pdd)has won.\n");
}

Test(corewar, test_get_alive_champs, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "1", "tests/mine.cor", "-n", "2", "tests/mine2.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(7, av, vm);
    vm->champion->last_live = 1;
    vm->champion->next->last_live = 24;
    get_alive_champions(vm, vm->cycle_to_die);
    cr_assert_eq(vm->alive_champions, 2);
}

Test(corewar, test_find_living_champs, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "1", "tests/mine.cor", "-n", "2", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    int cycles = 1;
    
    fill_vm(7, av, vm);
    handle_instructions(vm, cycles);
    cr_assert_eq(vm->nbr_live, 39);
    cr_assert_stdout_eq_str("The player 1(Mine)is alive.\n");
}

Test(corewar, test_find_living_champs2, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "1", "tests/mine.cor", "-n", "2", "tests/mine2.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    int cycles = 1;
    
    fill_vm(7, av, vm);
    handle_instructions(vm, cycles);
    cr_assert_stdout_eq_str("The player 1(Mine)is alive.\nThe player 2(Mine2)is alive.\n");
}

Test(corewar, test_handle_live, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "1", "tests/mine.cor", "-n", "2", "tests/mine2.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(7, av, vm);
    instructions_params_t params = { vm, 1, vm->champion , 0x01, 1 , {0}, {0} };
    handle_live(&params);
    params.champ = vm->champion->next;
    handle_live(&params);
    cr_assert_stdout_eq_str("The player 1(Mine)is alive.\nThe player 2(Mine2)is alive.\n");
}

Test(corewar, test_find_living_champs3, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "1", "tests/mine.cor", "-n", "2", "tests/mine2.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    int cycles = 1;
    
    fill_vm(7, av, vm);
    vm->champion->prog_counter += 1;
    vm->champion->next->prog_counter += 1;
    handle_instructions(vm, cycles);
    cr_assert_stdout_eq_str("");
}

Test(corewar, test_cooldown_verif_no_cooldown, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "1", "tests/mine.cor", "-n", "2", "tests/mine2.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    int verif = 1;
    
    fill_vm(7, av, vm);
    verif = is_cooldown(&vm->champion);
    cr_assert_eq(verif, 0);
}

Test(corewar, test_cooldown_verif_with_cooldown, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "1", "tests/mine.cor", "-n", "2", "tests/mine2.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    int verif = 1;
    champions_t *champ;
    
    fill_vm(7, av, vm);
    champ = vm->champion;
    champ->cylces_to_wait = 10;
    verif = is_cooldown(&champ);
    cr_assert_str_eq(champ->header.prog_name, "Mine2");
    cr_assert_eq(verif, 1);
}
