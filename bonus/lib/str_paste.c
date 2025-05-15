/*
** EPITECH PROJECT, 2024
** a*az
** File description:
** azd
*/

#include "corewar.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *my_revstr(char *str)
{
    int i;
    int size = 0;
    char a;

    while (str[size] != '\0')
        size++;
    for (i = 0; i < size / 2; i++) {
        a = str[size - i - 1];
        str[size - i - 1] = str[i];
        str[i] = a;
    }
    return str;
}

char *my_strcat(char *dest, char *src)
{
    int ldest = my_strlen(dest);
    int lsrc = my_strlen(src);
    int i = 0;

    for (i = ldest; i <= ldest + lsrc; i++)
        dest[i] = src[i - ldest];
    dest[i] = '\0';
    return dest;
}

char *my_strncat(char *dest, char *src, int nb)
{
    int ldest = my_strlen(dest);
    int lsrc = my_strlen(src);
    int i = 0;

    for (i = ldest; i <= ldest + lsrc && i <= nb; i++)
        dest[i] = src[i - ldest];
    dest[i] = '\0';
    return dest;
}
