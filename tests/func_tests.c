/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Tests functionnels
*/
#include "corewar.h"
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

Test(corewar, all_basic, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/mine.cor", "tests/mine2.cor", NULL};

    start_corewar(3, av);
    cr_assert_stdout_eq_str("The player 1(Mine)is alive.\nThe player 2(Mine2)is alive.\nThe player 1(Mine)has won.\n");
}
