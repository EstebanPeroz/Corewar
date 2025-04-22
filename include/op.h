/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Structs and Macros for corewar
*/

#ifndef _OP_H_
    #define _OP_H_

    #define MEM_SIZE (6 * 1024)
    /* modulo of the index < */
    #define IDX_MOD 512
    /* this may not be changed 2^*IND_SIZE */
    #define MAX_ARGS_NUMBER 4

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define REGISTER_CHAR 'r'
    #define INDIRECT_CHAR '\0'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789\0"
    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

/*
** regs
*/
    /* r1 <--> rx */
    #define REG_NUMBER 16

    /* register */
    #define T_REG 1
    /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_DIR 2
    /* indirect always relative (ld 1,r1 put what's in the address
     * (1+pc) into r1 (4 bytes )) */
    #define T_IND 4
    /* Label */
    #define T_LAB 8

/*
** size (in bytes)
*/
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE 1
    #define HEADER_SIZE 2

/*
** header
*/
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3
    /* number of cycle before beig declared dead */
    #define CYCLE_TO_DIE 1536
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40
/*
** arg_type
*/
    #define TYPE_REG 0b01
    #define TYPE_DIR 0b10
    #define TYPE_IND 0b11
    #define TYPE_OTHER 0b00

typedef char args_type_t;
typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    int force_indexes;
    char code;
    int nbr_cycles;
    char *comment;
} op_t;
extern const op_t op_tab[];
#endif
