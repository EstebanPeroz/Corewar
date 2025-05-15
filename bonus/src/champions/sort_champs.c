/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** sort_champs
*/

#include "corewar.h"

static void swap_basic_info(champions_t *a, champions_t *b)
{
    int temp_id = a->prog_id;
    int temp_adress = a->address;
    int temp_prog_counter = a->prog_counter;
    int temp_cylces_to_wait = a->cylces_to_wait;
    int temp_last_live = a->last_live;
    bool temp_is_placed = a->is_placed;

    a->prog_id = b->prog_id;
    a->address = b->address;
    a->prog_counter = b->prog_counter;
    a->cylces_to_wait = b->cylces_to_wait;
    a->last_live = b->last_live;
    a->is_placed = b->is_placed;
    b->prog_id = temp_id;
    b->address = temp_adress;
    b->prog_counter = temp_prog_counter;
    b->cylces_to_wait = temp_cylces_to_wait;
    b->last_live = temp_last_live;
    b->is_placed = temp_is_placed;
}

static void *my_memcpy(void *src, void *dest, size_t size, size_t initialsize)
{
    char *src_str = (char *)src;
    char *dest_str = (char *)dest;
    size_t i = 0;

    while (initialsize && i < size) {
        dest_str[i] = src_str[i];
        i++;
        initialsize--;
    }
    return (void *)dest_str;
}

static void swap_code_and_registers(champions_t *a, champions_t *b)
{
    unsigned char *temp_code = a->code;
    int temp_registers[REG_NUMBER];

    my_memcpy(a->registers, temp_registers, sizeof(temp_registers),
        sizeof(temp_registers));
    a->code = b->code;
    b->code = temp_code;
    my_memcpy(b->registers, a->registers, sizeof(a->registers),
        sizeof(a->registers));
    my_memcpy(temp_registers, b->registers, sizeof(temp_registers),
        sizeof(temp_registers));
}

static void swap_header_and_name(champions_t *a, champions_t *b)
{
    header_t temp_header = a->header;
    char *temp_name = a->name;

    a->header = b->header;
    a->name = b->name;
    b->header = temp_header;
    b->name = temp_name;
}

static void swipe_champs(champions_t *current, bool *swapped)
{
    if (current->prog_id > current->next->prog_id) {
        swap_basic_info(current, current->next);
        swap_code_and_registers(current, current->next);
        swap_header_and_name(current, current->next);
        *swapped = true;
    }
}

void sort_champs(champions_t **champ)
{
    bool swapped;
    champions_t *current;
    champions_t *last = NULL;

    do {
        swapped = false;
        current = *champ;
        while (current->next != last) {
            swipe_champs(current, &swapped);
            current = current->next;
        }
        last = current;
    } while (swapped);
}
