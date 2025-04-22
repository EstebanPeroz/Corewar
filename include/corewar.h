/*
** EPITECH PROJECT, 2025
** include
** File description:
** include corewar
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

#ifndef COREWAR_H
    #define COREWAR_H

typedef struct parsed_args_s {
    int nb_cycles;
    int *prog_nbr;
    int *load_adress;
    char **core_files;
} parsed_args_t;

typedef struct champions_s {
    char *name;
    int id;
    bool is_alive;
    int cooldown;
    struct champions_s *next;
} champion_t;

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
long long inverse_byte_order(long long nb, size_t byte_nb);
int char_nb(char *str, char c);
int get_array_len(void **array);
void **add_array_new_val(void **array, void *val);
char *super_strcat(char *dest, char *src);
char *super_strncat(char *dest, char *src, int ldest, int lsrc);

    /*Main project functions*/
parsed_args_t parse_args(int ac, char **av);
int help(void);

#endif // !COREWAR_H
