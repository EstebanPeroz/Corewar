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

Test(corewar, basic_parsing)
{
    char *av[] = { "./corewar", "tests/pdd.cor", "tests/abel.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(3, av);
    cr_assert_not_null(args.champs);
}

Test(amazed, parsing_unvalid_file)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "Non file", NULL};
    parsed_args_t args;
    
    args = parse_args(3, av);
    cr_assert_null(args.champs);
}

Test(amazed, parsing_unvalid_file2)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/pdd.s", NULL};
    parsed_args_t args;
    
    args = parse_args(3, av);
    cr_assert_null(args.champs);
}

Test(amazed, parsing_directory)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests", NULL};
    parsed_args_t args;
    
    args = parse_args(3, av);
    cr_assert_null(args.champs);
}

Test(amazed, parsing_options_n)
{
    char *av[] = {"./corewar", "-n", "4", "tests/pdd.cor", "tests/abel.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(5, av);
    cr_assert_not_null(args.champs);
}

Test(amazed, parsing_options_a)
{
    char *av[] = {"./corewar", "-n", "4", "tests/pdd.cor", "-a", "200", "tests/abel.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(7, av);
    cr_assert_not_null(args.champs);
}

Test(amazed, parsing_invalid_option)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-a", "200", "-n", "-2", "tests/abel.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(7, av);
    cr_assert_null(args.champs);
}


Test(amazed, parsing_invalid_option2)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "-a", "-200", "-n", "2", "tests/abel.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(7, av);
    cr_assert_null(args.champs);
}

Test(amazed, parsing_option_missing_datas)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", "-a", "200", NULL};
    parsed_args_t args;
    
    args = parse_args(5, av);
    cr_assert_null(args.champs);
}

Test(amazed, parsing_option_missing_datas2)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", "-a", NULL};
    parsed_args_t args;
    
    args = parse_args(4, av);
    cr_assert_null(args.champs);
}

Test(amazed, parsing_option_missing_datas3)
{
    char *av[] = {"./corewar", "tests/pdd.cor", "tests/abel.cor", "-a", "tests/pdd.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(5, av);
    cr_assert_null(args.champs);
}

Test(amazed, parsing_options_an)
{
    char *av[] = {"./corewar", "-n", "4", "-a", "400", "tests/pdd.cor", "-a", "200", "-n", "0", "tests/abel.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(11, av);
    cr_assert_not_null(args.champs);
}


Test(amazed, parsing_basic_dump)
{
    char *av[] = {"./corewar", "-dump", "500", "-n", "4", "-a", "400", "tests/pdd.cor", "-a", "200", "-n", "0", "tests/abel.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(13, av);
    cr_assert_not_null(args.champs);
}

Test(amazed, parsing_dump_missing_data)
{
    char *av[] = {"./corewar", "-dump", "-n", "4", "-a", "400", "tests/pdd.cor", "-a", "200", "-n", "0", "tests/abel.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(12, av);
    cr_assert_null(args.champs);
}

Test(amazed, parsing_dumpd_missing_champ)
{
    char *av[] = {"./corewar", "-dump", "200", "-n", "4", "-a", "400", "tests/pdd.cor", NULL};
    parsed_args_t args;
    
    args = parse_args(8, av);
    cr_assert_null(args.champs);
}

Test(amazed, help)
{
    int ret = help();

    cr_assert_eq(ret, 0);
}
