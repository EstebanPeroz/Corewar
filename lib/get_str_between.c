/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** get_str_between
*/

#include "corewar.h"

int char_nb(char *str, char c)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
        counter += str[i] == c;
    return counter;
}

int get_strpos(char *str, char *to_find, int nb)
{
    int sample_pos = 0;
    int sample_counter = 0;

    if (to_find[0] == '\0')
        return nb;
    if (!str || !to_find)
        return -1;
    for (int i = 0; str[i] != '\0' && nb >= 0; i++) {
        if (str[i] == to_find[sample_counter]) {
            sample_pos = i + 1;
            sample_counter++;
        } else
            sample_counter = 0;
        if (sample_counter == my_strlen(to_find) && nb)
            return sample_pos +
                get_strpos(str + sample_pos, to_find, nb - 1);
        if (sample_counter == my_strlen(to_find) && !nb)
            return sample_pos - sample_counter;
    }
    return -1;
}

char *get_str_between(char *start, char *end, char *str, int nb)
{
    int start_pos = get_strpos(str, start, nb) + my_strlen(start);
    int end_pos = get_strpos(str + start_pos, end, 0) + start_pos;
    int size = end_pos - start_pos;
    char *buffer = malloc(sizeof(char) * (size + 1));
    int i = start_pos;

    if (!buffer || size <= 0 || !str)
        return NULL;
    for (; str[i] != '\0' && i < end_pos; i++) {
        buffer[i - start_pos] = str[i];
    }
    buffer[i - start_pos] = '\0';
    return buffer;
}
