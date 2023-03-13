/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-clement.monnoire
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_
    #define _XOPEN_SOURCE 700
    #include <unistd.h>
    #include <signal.h>
    #include "stdio.h"
    #include <signal.h>
    #include "stdlib.h"
    #include <unistd.h>
    struct game_t {
        char **my_map;
        char **enemy_map;
        int enemy_pid;
        int sig1;
        int sig2;
    };
    extern struct game_t game;

    void get_enemy_pid(int signum, siginfo_t *info, void *context);
    void signal_connection(int sig);
    void handle_signal(int sig);
    void print_map(char **map, int player);
    int player_two(int pid, char *file_path);
    int player_one(char *file_path);
    int send_attack(int pid);
    int receve_attack(int pid);
    int open_file(char const *file);
    void my_putstr(char *str);
    int my_put_nbr(int nb);
    int get_nbr(char const *str);
    void destroy_map(char **map);
    int check_boat(char *boat, int line);
#endif /* !NAVY_H_ */
