/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-clement.monnoire
** File description:
** players
*/

#include "../include/navy.h"

void end(int i)
{
    print_map(game.my_map, 1);
    print_map(game.enemy_map, 2);
    if (i == -1) my_putstr("Enemy won\n");
    if (i == 1) my_putstr("I won\n");
}

void game_loop_two(void)
{
    int win = 0, my_boat = 14, en_boat = 14;
    struct sigaction action;
    action.sa_handler = handle_signal;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (win == 0) {
        print_map(game.my_map, 1);
        print_map(game.enemy_map, 2);
        my_putstr("waiting for enemy's attack...\n");
        my_boat -= receve_attack(game.enemy_pid);
        usleep(5000);
        if (send_attack(game.enemy_pid) == 1) {
        my_putstr(": hit\n\n");
        en_boat--;
        }else
            my_putstr(": miss\n\n");
        if (my_boat == 0) win = -1;
        if (en_boat == 0) win = 1;
    }
    end(win);
}

void game_loop_one(void)
{
    int win = 0, my_boat = 14, en_boat = 14;
    struct sigaction action;
    action.sa_handler = handle_signal;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (win == 0) {
        print_map(game.my_map, 1);
        print_map(game.enemy_map, 2);
        if (send_attack(game.enemy_pid) == 1) {
        my_putstr(": hit\n\n");
        en_boat--;
        }else
            my_putstr(": miss\n\n");
        my_putstr("waiting for enemy's attack...\n");
        usleep(5000);
        my_boat -= receve_attack(game.enemy_pid);
        if (my_boat == 0) win = -1;
        if (en_boat == 0) win = 1;
    }
    end(win);
}

int player_one(char *file_path)
{
    struct sigaction action;
    action.sa_sigaction = get_enemy_pid;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    my_putstr("waiting for enemy connection...\n\n");
    pause();
    my_putstr("enemy connected\n\n");
    if (kill(game.enemy_pid, SIGUSR1) < 0) return 84;
    game_loop_one();
    return 0;
}

int player_two(int pid, char *file_path)
{
    struct sigaction action;
    action.sa_handler = signal_connection;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    game.enemy_pid = pid;
    usleep(5000);
    if (kill(game.enemy_pid, SIGUSR1) < 0) return 84;
    pause();
    my_putstr("successfully connected\n\n");
    game_loop_two();
    return 0;
}
