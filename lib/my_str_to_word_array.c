/*
** EPITECH PROJECT, 2024
** str to word array
** File description:
** str to word array
*/
#include <stdio.h>
#include <stdlib.h>

int is_letter_nbr(char c, int *quotes)
{
    if (c == '\"')
        *quotes += 1;
    if (*quotes % 2 == 1)
        return 1;
    if (c != ' ' && c != '\t' && c != '\0') {
        return 0;
    }
    return 1;
}

int count_start(char const *str, int i)
{
    int quotes = 0;

    while (str[i] != '\0' && (is_letter_nbr(str[i], &quotes) == 1
    && str[i] != '\"')) {
        i++;
    }
    if (str[i] != '\0') {
        return (i);
    }
    return 0;
}

int count_length(char const *str, int start)
{
    int length = 0;
    int quotes = 0;

    while (is_letter_nbr(str[start], &quotes) == 0 || quotes == 1) {
        length++;
        start++;
    }
    return (length);
}

int count_total_words(char const *str)
{
    int total_words = 0;
    int quotes = 0;
    int quotes2 = 0;

    is_letter_nbr(str[0], &quotes2);
    for (int i = 0; str[i] != 0 && str[i + 1] != 0; i++) {
        if (is_letter_nbr(str[i], &quotes) == 1
        && is_letter_nbr(str[i + 1], &quotes2) == 0)
            total_words++;
    }
    return (total_words + 1);
}

char **my_str_to_word_array(char const *str)
{
    int start = count_start(str, 0);
    int i = 0;
    int length = count_length(str, start);
    int total_words = count_total_words(str);
    char **to_ret = malloc(sizeof(char *) * (total_words + 1));

    for (int count = 0; total_words > count; count++) {
        to_ret[count] = malloc((1 + length) * sizeof(char));
        for (; i < length; i++) {
            to_ret[count][i] = str[start];
            start++;
        }
        to_ret[count][i] = '\0';
        i = 0;
        start = count_start(str, start);
        length = count_length(str, start);
    }
    to_ret[total_words] = NULL;
    return to_ret;
}
