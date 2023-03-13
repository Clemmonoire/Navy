/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-malo.coet
** File description:
** get_nbr
*/

#include "stdlib.h"
#include "unistd.h"

int get_nbr(char const *str)
{
    int nbr = 0, i = 0;

    while (str[i] >= 48 && str[i] <= 57){
        nbr *= 10;
        nbr = nbr + str[i] - 48;
        i++;
    }
    return nbr;
}

int my_put_nbr(int nb)
{
    int l = 1, r = 1, i = 0;
    char *buffer;
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    while ((nb / r) >= 10) {
        r *= 10;
        l++;
    }
    buffer = malloc(sizeof(char) * (l + 1));
    while (r > 0) {
        buffer[i] = ((nb / r) % 10 + 48);
        r /= 10;
        i++;
    }
    write(1, buffer, i);
    return l;
}
