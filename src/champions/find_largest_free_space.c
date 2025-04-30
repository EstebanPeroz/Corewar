/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** find_largest_free_space
*/

#include "corewar.h"

bool is_cell_taken(champions_t *champ, int pos)
{
    int champ_start = champ->address;
    int champ_end = (champ_start + champ->header.prog_size) % MEM_SIZE;

    if (champ_start <= champ_end) {
        if (pos >= champ_start && pos < champ_end)
            return true;
    } else {
        if (pos >= champ_start || pos < champ_end)
            return true;
    }
    return false;
}

bool compare_champ_cell(virtual_machine_t *vm, int pos)
{
    champions_t *champ = vm->champion;

    while (champ != NULL) {
        if (is_cell_taken(champ, pos) == true)
            return true;
        champ = champ->next;
    }
    return false;
}

static void initialize_tracker(free_space_tracker_t *tracker)
{
    tracker->best_start = -1;
    tracker->best_size = 0;
    tracker->current_start = -1;
    tracker->current_size = 0;
}

static void update_best_space(free_space_tracker_t *tracker)
{
    if (tracker->current_size > tracker->best_size) {
        tracker->best_start = tracker->current_start;
        tracker->best_size = tracker->current_size;
    }
}

static void handle_end_of_free_space(free_space_tracker_t *tracker)
{
    if (tracker->current_start == -1) {
        return;
    }
    update_best_space(tracker);
    tracker->current_start = -1;
    tracker->current_size = 0;
}

static void process_free_cell(free_space_tracker_t *tracker, int index)
{
    if (tracker->current_start == -1) {
        tracker->current_start = index;
    }
    tracker->current_size++;
}

static void process_occupied_cell(free_space_tracker_t *tracker)
{
    handle_end_of_free_space(tracker);
}

static bool is_cell_free(virtual_machine_t *vm, int pos)
{
    return !compare_champ_cell(vm, pos);
}

free_space_t find_largest_free_space(virtual_machine_t *vm)
{
    free_space_tracker_t tracker;
    free_space_t result = {0, 0};

    initialize_tracker(&tracker);
    for (int i = 0; i < MEM_SIZE; i++) {
        if (is_cell_free(vm, i)) {
            process_free_cell(&tracker, i);
        } else {
            process_occupied_cell(&tracker);
        }
    }
    handle_end_of_free_space(&tracker);
    result.size = tracker.best_size;
    result.start = tracker.best_start;
    return result;
}
