/*
** EPITECH PROJECT, 2025
** include
** File description:
** include corewar
*/

#ifndef COREWAR_H
    #define COREWAR_H

// Instructions ids
    #define LIVE_ID 0
    #define LD_ID 1
    #define ST_ID 2
    #define ADD_ID 3
    #define SUB_ID 4
    #define AND_ID 5
    #define OR_ID 6
    #define XOR_ID 7
    #define ZJMP_ID 8
    #define LDI_ID 9
    #define STI_ID 10
    #define FORK_ID 11
    #define LLD_ID 12
    #define LLDI_ID 13
    #define LFORK_ID 14
    #define AFF_ID 15

    #define READ_FILE_ARG "r"
    #define DEFAULT_ADRESS -1
    #define INSTRUCTIONS_NB 2
// The printed line length is equal to 65
// 32 bytes = 64 (2 chars for hexadecimal) + 1 for \n
    #define LINE_LENGTH     65
    #define BYTES_PER_LINE     32

    #define NB_INSTRUCTIONS 16

    #define MAX_BIN_BYTES 0b11
    #define MAX_HEXA_BYTES 0xFF

    #define SUBSTRACTION_MARK -
    #define ADDITION_MARK +

    #include <stdlib.h>

    #include "structs.h"

// Instructions

int handle_live(instructions_params_t *params);
int handle_ld(instructions_params_t *params);
int handle_zjmp(instructions_params_t *params);
int handle_lld(instructions_params_t *params);
int handle_ldi(instructions_params_t *params);
int handle_lldi(instructions_params_t *params);
int handle_fork(instructions_params_t *params);
int handle_lfork(instructions_params_t *params);
int handle_add(instructions_params_t *params);
int handle_st(instructions_params_t *params);
int handle_sti(instructions_params_t *params);
int handle_and(instructions_params_t *params);
int handle_aff(instructions_params_t *params);
int handle_sub(instructions_params_t *params);

// VM

int get_alive_champions(virtual_machine_t *vm, int cycles);
int decrease_cycle_to_die(virtual_machine_t *vm);
int reset_carry(champions_t *champ);
void byte_to_hex(unsigned char byte, char *out);
int is_cooldown(champions_t **current);
void print_live_and_win_message(champions_t *champ);
int handle_dump(virtual_machine_t *vm, int *last);
int check_cooldown(champions_t **champ);
int handle_instructions(virtual_machine_t *vm, int cycles);
int get_winner(virtual_machine_t *vm);
int reset_cycles(virtual_machine_t *vm, int *cycles);
int fill_vm(int ac, char **av, virtual_machine_t *vm);
int read_bytes(unsigned char *arena, int start, int size);
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
const op_t *get_instruction(int opcode);
instructions_params_t *init_instruction_params(
    virtual_machine_t *vm, int cycles, champions_t *champ, int opcode);
void free_instruction_params(instructions_params_t *params);
int update_prog_counter(virtual_machine_t *vm,
    champions_t *champ, const op_t *op);
unsigned char get_coding_byte(virtual_machine_t *vm, int pc);
int get_params_size(int params, const op_t *op);
bool is_valid_register(int reg);
void put_int_in_arena(unsigned char *arena, int adrs, int value);
int read_bytes(unsigned char *arena, int start, int size);

// CHAMPIONS
champions_t *get_champs_with_options(char **list);
int print_champions(champions_t **head);
void free_champion(champions_t *champ);
int fill_struct_champions(char *file, champions_t **champ, int id,
    int address);
void sort_champs(champions_t **champ);
void manage_adress(champions_t *champ);
int get_total_champs(champions_t **head);
void update_champs_cycle_to_wait(virtual_machine_t *vm);

// PARSING
int is_valid_magic(FILE *fd);
int set_options(champions_t **tmp, int i, int *used_id);
int handle_options(champions_t **head, char **str, int *i, options_t *options);
void reverse_endian_header(header_t *header);
int get_cycles(char ***av, int ac);

    /*Lib functions*/
int my_getnbr(char *);
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
int bytes_to_int(unsigned char *arena, int pc);
short bytes_to_short(unsigned char *arena, int pc);
int my_put_nbr(int);

// OTHERS
int start_corewar(int ac, char **av);
int help(void);

#endif // !COREWAR_H
