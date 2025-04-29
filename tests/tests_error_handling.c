/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Tests
*/
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>
#include "corewar.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(corewar, basic_parsing, .init = redirect_all_std)
{
    char *av[] = { "./corewar", "tests/pdd.cor", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(3, av, vm);
    cr_assert_not_null(vm->champion);
}

Test(corewar, parsing_unvalid_file, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "Non file", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(3, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_unvalid_file2, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/pdd.s", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(3, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_directory, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(3, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_options_n, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "4", "tests/pdd.cor", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    cr_assert_not_null(vm->champion);
}

Test(corewar, parsing_options_a, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "4", "tests/pdd.cor", "-a", "200", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(7, av, vm);
    cr_assert_not_null(vm->champion);
}

Test(corewar, parsing_invalid_option, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-a", "200", "-n", "-2", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(7, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_invalid_option2, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-a", "-200", "-n", "2", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(7, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_option_missing_datas, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", "-a", "200", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_option_missing_datas2, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", "-a", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(4, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_option_missing_datas3, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", "-a", "tests/pdd.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(5, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_options_an, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-n", "4", "-a", "400", "tests/pdd.cor", "-a", "200", "-n", "0", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(11, av, vm);
    cr_assert_not_null(vm->champion);
}


Test(corewar, parsing_basic_dump, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-dump", "500", "-n", "4", "-a", "400", "tests/pdd.cor", "-a", "200", "-n", "0", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(13, av, vm);
    cr_assert_not_null(vm->champion);
}

Test(corewar, parsing_dump_missing_data, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-dump", "-n", "4", "-a", "400", "tests/pdd.cor", "-a", "200", "-n", "0", "tests/abel.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(12, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_dump_missing_champ, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-dump", "200", "-n", "4", "-a", "400", "tests/pdd.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(8, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_too_many_champs, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", "-n", "4", "tests/tyron.cor", "tests/pdd.cor", "tests/pdd.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(8, av, vm);
    cr_assert_null(vm->champion);
}

Test(corewar, parsing_enought_champs, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", "-n", "4", "tests/tyron.cor", "tests/pdd.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    
    fill_vm(7, av, vm);
    cr_assert_not_null(vm->champion);
}


Test(corewar, help, .init = redirect_all_std)
{
    int ret = help();

    cr_assert_eq(ret, 0);
}
