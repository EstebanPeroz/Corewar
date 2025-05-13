/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Struc define
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <stdio.h>
    #include <fcntl.h>
    #include <stdbool.h>

    #include "op.h"

typedef struct champions_s {
    char *name;
    FILE *fd;
    int carry;
    int address;
    int prog_id;
    int prog_counter;
    int cylces_to_wait;
    int last_live;
    bool is_placed;
    unsigned char *code;
    int registers[REG_NUMBER];
    header_t header;
    struct champions_s *next;
} champions_t;

typedef struct virtual_machine_s {
    int cycle;
    int nbr_processus;
    int nbr_processus_to_place;
    int cycle_to_dump;
    int cycle_to_die;
    int cycle_delta;
    int nbr_live;
    int alive_champions;
    unsigned char arena[MEM_SIZE];
    champions_t *champion;
} virtual_machine_t;

typedef struct free_space_tracker_s {
    int best_start;
    int best_size;
    int current_start;
    int current_size;
} free_space_tracker_t;

typedef struct free_space_s {
    int start;
    int size;
} free_space_t;

typedef struct instructions_params {
    virtual_machine_t *vm;
    int cycles;
    champions_t *champ;
    int instruction;
    int nb_params;
    int types[MAX_ARGS_NUMBER];
    int values[MAX_ARGS_NUMBER];
} instructions_params_t;


typedef struct options_s {
    int address;
    int id;
} options_t;

#endif // STRUCT_H
