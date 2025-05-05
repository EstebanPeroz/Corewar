/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Test the loop
*/
#include "corewar.h"
#include "structs.h"
#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <criterion/redirect.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/redirect.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(corewar, test_dump, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "-dump", "500", "-n", "1", "tests/mine.cor", "-n", "2", "tests/mine2.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);
    int ret;
    int last = 0;
    
    fill_vm(9, av, vm);
    ret = handle_dump(vm, &last);
    cr_assert_eq(ret, 0);
    last = 500;
    ret = handle_dump(vm, &last);
    cr_assert_eq(ret, 1);
    cr_assert_stdout_neq_str("");
}

Test(corewar, test_byte_to_hex)
{
    unsigned char byte = 18;
    char result[3];

    byte_to_hex(byte, result);
    result[2] = '\0';
    cr_assert_str_eq(result, "12");
}

Test(corewar, test_byte_to_hex2)
{
    unsigned char byte = 210;
    char result[3];

    byte_to_hex(byte, result);
    result[2] = '\0';
    cr_assert_str_eq(result, "D2");
}
