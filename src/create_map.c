/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-clement.monnoire
** File description:
** create_map
*/

#include "../include/navy.h"

void destroy_map(char **map)
{
    for (int i = 0; i < 10; i++) {
        free(map[i]);
    }
    free(map);
}

void my_str_cpy(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
}

int create_map(void)
{
    int j = 0;
    char *buffer = NULL;
    size_t line_buf_size = 0;
    FILE *fp = fopen("include/map", "r");
    game.my_map = malloc(sizeof(char *) * 10);
    game.enemy_map = malloc(sizeof(char *) * 10);
    for (int i = 0; i < 10; i++) {
        game.my_map[i] = malloc(sizeof(char) * 20);
        game.enemy_map[i] = malloc(sizeof(char) * 20);
    }
    if (!fp) return 0;
    while (getline(&buffer, &line_buf_size, fp) != -1) {
        my_str_cpy(game.my_map[j], buffer);
        my_str_cpy(game.enemy_map[j], buffer);
        j++;
    }
    fclose(fp);
    free(buffer);
}

void put_boat(char **map, char *boat)
{
    char sign = boat[0];
    for (int i = (boat[3] - 47); i <= (boat[6] - 47); i++) {
        for (int j = 2 * (boat[2] - 64); j <= 2 * (boat[5] - 64); j += 2) {
            map[i][j] = sign;
        }
    }
}

int open_file(char const *file)
{
    char *buffer = NULL;
    size_t line_buf_size = 0;
    int line = 1, output;
    FILE *fp = fopen(file, "r");
    create_map();
    if (game.my_map == NULL || game.enemy_map == NULL) return 84;
    if (!fp) return 84;
    while (getline(&buffer, &line_buf_size, fp) != -1) {
        line++;
        if (check_boat(buffer, line) == 84) {
            output = 84;
            break;
        }
        put_boat(game.my_map, buffer);
    }
    fclose(fp);
    free(buffer);
    if (line != 5) return 84;
    return output;
}
