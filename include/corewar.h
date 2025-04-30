/*
** EPITECH PROJECT, 2025
** include
** File description:
** include corewar
*/

#ifndef COREWAR_H
    #define COREWAR_H

    #define READ_FILE_ARG "r"
    #define DEFAULT_ADRESS -1

    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdbool.h>

    #include "op.h"

typedef struct champions_s {
    char *name;
    FILE *fd;
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
    int carry;
    int nbr_processus;
    int nbr_processus_to_place;
    int cycle_to_dump;
    int cycle_to_die;
    int cycle_delta;
    int nbr_live;
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

typedef struct options_s {
    int address;
    int id;
} options_t;

    /*Lib functions*/
int my_strcmp(char *, char *);
int str_contain(char *str, char c);
int my_put_map(char **map);
int my_strlen(char *);
int my_puterr(char const *);
int my_putstr(char const *);
int my_getnbr(char *);
char *my_strdup(char const *src);
void my_putchar(char);
char **my_str_to_word_array(char *);
int get_strpos(char *str, char *to_find, int nb);
char *get_str_between(char *start, char *end, char *str, int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char *src, int nb);
int inverse_byte_order(int nb, size_t byte_nb);
int char_nb(char *str, char c);
int get_array_len(void **array);
void **add_array_new_val(void **array, void *val);
char *super_strcat(char *dest, char *src);
char *super_strncat(char *dest, char *src, int ldest, int lsrc);
int is_nbr(char *str);


// VM
int fill_vm(int ac, char **av, virtual_machine_t *vm);
virtual_machine_t *init_virtual_machine(int cycle_to_tump,
    int nb_processus);
void free_virtual_machine(virtual_machine_t *virtual_machine);
free_space_t find_largest_free_space(virtual_machine_t *vm);
void place_all_processus(virtual_machine_t *virtual_machine);
void place_champion(virtual_machine_t *virtual_machine,
    champions_t *champion);
bool is_cell_taken(champions_t *champ, int pos);
bool compare_champ_cell(virtual_machine_t *vm, int pos);
champions_t *get_champion_to_place(virtual_machine_t *vm);
int vm_loop(virtual_machine_t *vm);

// CHAMPIONS
champions_t *get_champs_with_options(char **list);
int print_champions(champions_t **head);
void free_champion(champions_t *champ);
int fill_struct_champions(char *file, champions_t **champ, int id,
    int address);
void sort_champs(champions_t **champ);
void manage_adress(champions_t *champ);
int get_total_champs(champions_t **head);

// PARSING
int is_valid_magic(FILE *fd);
int set_options(champions_t **tmp, int i, int *used_id);
int handle_options(champions_t **head, char **str, int *i, options_t *options);
void reverse_endian_header(header_t *header);
int get_cycles(char ***av, int ac);

// OTHERS
int help(void);

#endif // !COREWAR_H
