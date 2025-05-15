/*
** EPITECH PROJECT, 2024
** my putnbr
** File description:
** je sais plus
*/
int count_nbr_pos_neg(char const *str, int beg)
{
    int positivity = 0;

    if (beg > 0)
        beg--;
    while (str[beg] == '-' || str[beg] == '+') {
        if (str[beg] == '-') {
            positivity++;
        }
        beg--;
    }
    return (positivity);
}

int count_total_nbrs_in_str(char const *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nbr++;
    }
    return nbr;
}

int nbr_returner(int length, char const *str, int beg)
{
    long long nbr_to_ret = 0;
    int i = 0;
    int copy_beg = beg;
    int positivity = 0;

    for (i = 0; i < length; i++) {
        nbr_to_ret = nbr_to_ret * 10 + (str[beg] - 48);
        beg++;
    }
    positivity = count_nbr_pos_neg(str, copy_beg);
    if (positivity % 2 == 1) {
        nbr_to_ret = nbr_to_ret * -1;
    }
    if (nbr_to_ret > 2147483647 || nbr_to_ret < -2147483648 || length > 11) {
        nbr_to_ret = 0;
    }
    return (nbr_to_ret);
}

int my_getnbr(char *str)
{
    int beg = 0;
    int end = 0;
    int length;
    int nbr = 0;

    if (count_total_nbrs_in_str(str) == 0)
        return 0;
    while (str[beg] < '0' || str[beg] > '9')
        beg++;
    end = beg + 1;
    while (str[end] >= '0' && str[end] <= '9') {
        end++;
    }
    length = end - beg;
    nbr = nbr_returner(length, str, beg);
    return (nbr);
}
