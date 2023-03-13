/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-clement.monnoire
** File description:
** signal
*/

#include "../include/navy.h"

void signal_connection(int sig)
{
    return;
}

void get_enemy_pid(int signum, siginfo_t *info, void *context)
{
    game.enemy_pid = info->si_pid;
}

void handle_signal(int sig)
{
    if (sig == SIGUSR1)
        game.sig1++;
    if (sig == SIGUSR2)
        game.sig2++;
}
