/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Test the loop
*/
#include "corewar.h"
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
