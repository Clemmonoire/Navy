/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-clement.monnoire
** File description:
** attack
*/

#include "../include/navy.h"

int send_coord(int pid, char *coord)
{
    int x = coord[0] -64, y = coord[1] - 48;
    game.sig1 = 0; game.sig2 = 0;
    for (int i = 0; i < x; i++) {
        kill(pid, SIGUSR1);
        usleep(5000); }
    kill(pid, SIGUSR2);
    usleep(5000);
    for (int i = 0; i < y; i++) {
        kill(pid, SIGUSR1);
        usleep(5000); }
    kill(pid, SIGUSR2);
    pause();
    if (game.sig1 == 1) {
        game.enemy_map[y + 1][x * 2] = 'x';
        return 1;
    }
    if (game.sig2 == 1) {
        game.enemy_map[y + 1][x * 2] = 'o';
        return 0;
    }
}

int send_attack(int pid)
{
    int j = 0, output;
    char *buffer = NULL;
    size_t line_buf_size = 0;
    my_putstr("attack: ");
    getline(&buffer, &line_buf_size, stdin);
    while (buffer[2] != '\n' || buffer[0] < 'A' || buffer[0] > 'H'
        || buffer[1] < '1' || buffer[1] > '8') {
        my_putstr("wrong position\nattack: ");
        getline(&buffer, &line_buf_size, stdin);
    }
    write(1, buffer, 2);
    output = send_coord(pid, buffer);
    free(buffer);
    return output;
}

int check_map(int x, int y, char **map)
{
    char coord[2] = {x + 64, y + 48};
    if (map[y + 1][x * 2] >= '2' && map[y + 1][x * 2] <= '8'
        || map[y + 1][x * 2] == 'x') {
        game.my_map[y + 1][x * 2] = 'x';
        write(1,coord, 2);
        my_putstr(": hit\n\n");
        return 1;
    }
    if (map[y + 1][x * 2] == '.' || map[y + 1][x * 2] == 'o') {
        game.my_map[y + 1][x * 2] = 'o';
        write(1,coord, 2);
        my_putstr(": missed\n\n");
    }else {
        return -1;
    }
}

int receve_attack(int pid)
{
    int x = 0, y = 0;
    game.sig1 = 0; game.sig2 = 0;
    while (game.sig2 == 0) {
        pause();
    }
    x = game.sig1;
    game.sig1 = 0; game.sig2 = 0;
    pause();
    while (game.sig2 == 0) {
        pause();
    }
    y = game.sig1;
    if (check_map(x, y, game.my_map) == 1) {
        kill(pid, SIGUSR1);
        return 1;
    } else {
        kill(pid, SIGUSR2);
        return 0;
    }
}
