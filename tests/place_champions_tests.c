/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** place_champions_tests
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

Test(place_champion, basic_placement, .init = redirect_all_std)
{
    virtual_machine_t vm = {0};
    champions_t champ = {0};

    champ.address = 10;
    champ.header.prog_size = 3;
    champ.code = (unsigned char[]){0x01, 0x02, 0x03};
    place_champion(&vm, &champ);
    cr_assert_eq(vm.arena[10], 0x01);
    cr_assert_eq(vm.arena[11], 0x02);
    cr_assert_eq(vm.arena[12], 0x03);
    cr_assert_eq(champ.is_placed, true);
}

Test(is_cell_taken, normal_range, .init = redirect_all_std)
{
    champions_t champ = {0};

    champ.address = 5;
    champ.header.prog_size = 3;
    cr_assert_eq(is_cell_taken(&champ, 5), true);
    cr_assert_eq(is_cell_taken(&champ, 6), true);
    cr_assert_eq(is_cell_taken(&champ, 7), true);
    cr_assert_eq(is_cell_taken(&champ, 8), false);
}

Test(is_cell_taken, wrap_around, .init = redirect_all_std)
{
    champions_t champ = {0};

    champ.address = MEM_SIZE - 2;
    champ.header.prog_size = 4;
    cr_assert_eq(is_cell_taken(&champ, MEM_SIZE - 2), true);
    cr_assert_eq(is_cell_taken(&champ, MEM_SIZE - 1), true);
    cr_assert_eq(is_cell_taken(&champ, 0), true);
    cr_assert_eq(is_cell_taken(&champ, 1), true);
    cr_assert_eq(is_cell_taken(&champ, 2), false);
}

Test(compare_champ_cell, check_conflict, .init = redirect_all_std)
{
    virtual_machine_t vm = {0};
    champions_t champ1 = {0};

    champ1.address = 0;
    champ1.header.prog_size = 2;
    champ1.next = NULL;
    vm.champion = &champ1;
    cr_assert_eq(compare_champ_cell(&vm, 0), true);
    cr_assert_eq(compare_champ_cell(&vm, 1), true);
    cr_assert_eq(compare_champ_cell(&vm, 2), false);
}

Test(find_largest_free_space, simple_space, .init = redirect_all_std)
{
    virtual_machine_t vm = {0};
    memset(vm.arena, 0, MEM_SIZE);
    for (int i = 10; i < 20; i++)
        vm.arena[i] = 0xFF;
    champions_t champ = {0};
    champ.address = 10;
    champ.header.prog_size = 10;
    champ.next = NULL;
    vm.champion = &champ;

    free_space_t space = find_largest_free_space(&vm);

    cr_assert(space.size > 900);
    cr_assert(space.start == 20);
}

Test(place_all_processus, auto_distribution, .init = redirect_all_std)
{
    virtual_machine_t vm = {0};
    champions_t champ1 = {0};
    champions_t champ2 = {0};
    
    vm.nbr_processus = 2;
    vm.nbr_processus_to_place = 2;
    champ1.header.prog_size = 4;
    champ2.header.prog_size = 4;
    champ1.code = (unsigned char[]){0x01, 0x02, 0x03, 0x04};
    champ2.code = (unsigned char[]){0x05, 0x06, 0x07, 0x08};
    champ1.address = -1;
    champ2.address = -1;
    champ1.next = &champ2;
    champ2.next = NULL;
    vm.champion = &champ1;
    place_all_processus(&vm);
    cr_assert_eq(champ1.is_placed, true);
    cr_assert_eq(champ2.is_placed, true);
    cr_assert(vm.arena[0] == 0x01 || vm.arena[MEM_SIZE / 2] == 0x01);
    cr_assert(vm.arena[MEM_SIZE / 2] == 0x05 || vm.arena[0] == 0x05);
}

Test(get_champion_to_place, no_champion, .init = redirect_all_std)
{
    virtual_machine_t vm = {0};

    cr_assert_null(get_champion_to_place(&vm));
}

Test(get_champion_to_place, all_placed, .init = redirect_all_std)
{
    virtual_machine_t vm = {0};
    champions_t champ1 = { .is_placed = true };
    champions_t champ2 = { .is_placed = true };

    champ1.next = &champ2;
    champ2.next = NULL;
    vm.champion = &champ1;
    cr_assert_null(get_champion_to_place(&vm));
}

Test(get_champion_to_place, first_unplaced, .init = redirect_all_std)
{
    virtual_machine_t vm = {0};

    champions_t champ1 = { .is_placed = false };
    champions_t champ2 = { .is_placed = true };

    champ1.next = &champ2;
    champ2.next = NULL;
    vm.champion = &champ1;
    cr_assert_eq(get_champion_to_place(&vm), &champ1);
}