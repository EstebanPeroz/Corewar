/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Dump
*/
#include "corewar.h"
#include "op.h"
#include "structs.h"
#include <unistd.h>

void byte_to_hex(unsigned char byte, char *out)
{
    const char *hex = "0123456789ABCDEF";

    out[0] = hex[(byte >> 4) & 0x0F];
    out[1] = hex[byte & 0x0F];
}

static void print_dump(virtual_machine_t *vm)
{
    char line[LINE_LENGTH];

    for (int i = 0; i < MEM_SIZE; i += BYTES_PER_LINE) {
        for (int j = 0; j < BYTES_PER_LINE; j++) {
            byte_to_hex(vm->arena[i + j], &line[j * 2]);
        }
        line[BYTES_PER_LINE * 2] = '\n';
        write(1, line, LINE_LENGTH);
    }
}

int handle_dump(virtual_machine_t *vm, int *last_dump)
{
    if (vm->cycle_to_dump == *last_dump) {
        print_dump(vm);
        *last_dump = 1;
        return 1;
    }
    (*last_dump)++;
    return 0;
}
