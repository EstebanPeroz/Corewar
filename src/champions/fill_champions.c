/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** fill_champions
*/

#include "corewar.h"

static void push_to_end(champions_t **champ, champions_t *new_champ)
{
    champions_t *current = *champ;

    if (current == NULL) {
        *champ = new_champ;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_champ;
    }
}

static int fill_basic_info(champions_t *champ, int id, int address, char *file)
{
    champ->prog_id = id;
    champ->prog_counter = address;
    champ->cylces_to_wait = 0;
    champ->last_live = -1;
    champ->address = address;
    champ->next = NULL;
    champ->is_placed = false;
    champ->name = my_strdup(file);
    if (champ->name == NULL) {
        return EXIT_FAILURE;
    }
    return 0;
}

static void fill_registers(champions_t *champ)
{
    for (int i = 0; i < REG_NUMBER; i++) {
        champ->registers[i] = 0;
    }
}

static int fill_header_and_code(champions_t *champ, char *file)
{
    FILE *fd = fopen(file, READ_FILE_ARG);

    if (fread(&champ->header, sizeof(header_t), 1, fd) != 1) {
        fclose(fd);
        return EXIT_FAILURE;
    }
    reverse_endian_header(&champ->header);
    champ->code = malloc(champ->header.prog_size);
    if (champ->code == NULL) {
        fclose(fd);
        return EXIT_FAILURE;
    }
    if (fread(champ->code, 1, champ->header.prog_size, fd)
        != (size_t)champ->header.prog_size) {
        free(champ->code);
        fclose(fd);
        return EXIT_FAILURE;
    }
    fclose(fd);
    return 0;
}

int fill_struct_champions(char *file, champions_t **champ, int id, int address)
{
    champions_t *new_champ = malloc(sizeof(champions_t));

    if (new_champ == NULL)
        return EXIT_FAILURE;
    if (fill_basic_info(new_champ, id, address, file) == EXIT_FAILURE) {
        free(new_champ);
        return EXIT_FAILURE;
    }
    if (fill_header_and_code(new_champ, file) == EXIT_FAILURE) {
        free(new_champ->name);
        free(new_champ);
        return EXIT_FAILURE;
    }
    new_champ->fd = fopen(file, READ_FILE_ARG);
    fill_registers(new_champ);
    push_to_end(champ, new_champ);
    return 0;
}
