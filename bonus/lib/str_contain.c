/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Check if a str contain a specific char
*/

int str_contain(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return 1;
    }
    return 0;
}
