/*
** EPITECH PROJECT, 2024
** DAY 8
** File description:
** strdup_function
*/

#include "corewar.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen((char *)src) + 1));
    int i = 0;

    for (; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}

char *super_strcat(char *dest, char *src)
{
    int ldest = my_strlen(dest);
    int lsrc = my_strlen(src);
    int i = 0;

    dest = realloc(dest, sizeof(char) * (ldest + lsrc + 2));
    if (!dest)
        return NULL;
    for (i = ldest; i <= ldest + lsrc; i++)
        dest[i] = src[i - ldest];
    return dest;
}

static char *my_char_realloc(char *buff, size_t i_size, size_t f_size)
{
    char *temp = malloc(f_size + 1);

    if (!temp)
        return NULL;
    for (int i = 0; i < (int)i_size; i++)
        temp[i] = buff[i];
    free(buff);
    return temp;
}

char *super_strncat(char *dest, char *src, int ldest, int lsrc)
{
    int i = 0;

    dest = my_char_realloc(dest, ldest, sizeof(char) * (ldest + lsrc + 1));
    if (!dest)
        return NULL;
    for (i = ldest; i < (lsrc + ldest); i++)
        dest[i] = src[i - ldest];
    return dest;
}
