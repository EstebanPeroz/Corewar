/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Tests
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>
#include "corewar.h"

Test(amazed, bugged_test)
{
    int ret = help();

    cr_assert_eq(ret, 0);
}
