/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-clement.monnoire
** File description:
** my_putstr
*/

#include "unistd.h"

void my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') i++;
    write(1, str, i);
}
