/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Cat a strstr in an other strstr
*/
#include "stdlib.h"
#include "corewar.h"

char **my_strstrcat(char **strstr1, char **strstr2)
{
    int i = 0;
    int j = 0;

    if (!strstr1 || !strstr2)
        return NULL;
    for (; strstr1[i] != NULL; i++);
    for (; strstr2[j] != NULL; j++);
    strstr1 = realloc(strstr1, sizeof(char *) * (i + j + 1));
    if (!strstr1)
        return NULL;
    for (int k = 0; i + k <= j; k++) {
        strstr1[i + k] = my_strdup(strstr2[k]);
    }
    strstr1[i + j] = NULL;
    return strstr1;
}
