/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-clement.monnoire
** File description:
** my_navy
*/
#include "../include/navy.h"

struct game_t game;

void print_map(char **map, int player)
{
    if (player == 1) {
        my_putstr("my positions:\n");
    }else {
        my_putstr("enemy's positions:\n");
    }
    for (int i = 0; map[i] != NULL; i++)
        my_putstr(map[i]);
    write(1, "\n", 1);
}

void print_pid(void)
{
    write(1, "my_pid: ", 9);
    my_put_nbr(getpid());
    write(1, "\n", 1);
}

int my_navy(int argc, char **argv)
{
    switch (argc) {
    case 2 : if (open_file(argv[1]) == 84) return 84;
        print_pid();
        return player_one(argv[1]);
    case 3 : if (open_file(argv[2]) == 84) return 84;
    print_pid();
        return player_two(get_nbr(argv[1]) , argv[2]);
    default: return 84;
    }
}

int main(int argc, char **argv)
{
    int output;
    output = my_navy(argc, argv);
    destroy_map(game.enemy_map);
    destroy_map(game.my_map);
    return output;
}
