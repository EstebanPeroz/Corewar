/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Tests
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/redirect.h>

Test(corewar, test_reverse_byte)
{
    char bytes[4];
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    bytes[3] = 1;
    int result = bytes_to_int(bytes);

    cr_assert_eq(result, 1);
}


Test(corewar, test_reverse_byte2)
{
    char bytes[4];
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 1;
    bytes[3] = 2;
    int result = bytes_to_int(bytes);

    printf("\n\n%d\n\n", result);
    cr_assert_eq(result, 258);
}
