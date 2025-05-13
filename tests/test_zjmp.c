#include "corewar.h"
#include "op.h"
#include "structs.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/redirect.h>
#include <stdio.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(corewar, test_handle_zjmp_no_carry, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/mine.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);

    fill_vm(5, av, vm);
    champions_t *champ = vm->champion->next;

    champ->carry = 0;

    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = ZJMP_ID,
        .nb_params = 1
    };
    params.types[0] = T_DIR;
    params.values[0] = 5;
    handle_zjmp(&params);
    cr_assert_eq(champ->carry, 0);
}

Test(corewar, test_handle_zjmp, .init = redirect_all_std)
{
    char *av[] = {"./corewar", "tests/mine.cor", "-n", "3", "tests/zjmper.cor", NULL};
    virtual_machine_t *vm = init_virtual_machine(0, 0);

    fill_vm(5, av, vm);
    champions_t *champ = vm->champion->next;
    champ->prog_counter += DIR_SIZE + 1;

    if (vm->arena[champ->prog_counter] != 0x09) {
        printf("Current instruction: %i\n"
            "Expected: %i\n", vm->arena[champ->prog_counter], ZJMP_ID);
        fflush(NULL);
        cr_assert_fail("Wrong instruction\n");
    }
    champ->carry = 1;
    int offset = -5;
    int new_PC = (champ->prog_counter + (offset % IDX_MOD) + MEM_SIZE) % MEM_SIZE;
    instructions_params_t params = {
        .vm = vm,
        .cycles = 1,
        .champ = champ,
        .instruction = ZJMP_ID,
        .nb_params = 1
    };
    params.types[0] = T_DIR;
    params.values[0] = offset;
    handle_zjmp(&params);
    cr_assert_eq(champ->carry, 1);
    cr_assert_eq(champ->prog_counter, new_PC);
}
