/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-clement.monnoire
** File description:
** error
*/

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int check_boat(char *boat, int line)
{
    if (line != boat[0] - 48) return 84;
    if (my_strlen(boat) > 9) return 84;
    if (boat[0] < '2' || boat[0] > '5') return 84;
    if (boat[2] != boat[5] && boat[3] != boat[6]) return 84;
    if (boat[2] < 'A' || boat[2] > 'H') return 84;
    if (boat[5] < 'A' || boat[5] > 'H') return 84;
    if (boat[3] < '1' || boat[3] > '8') return 84;
    if (boat[6] < '1' || boat[6] > '8') return 84;
    if ((boat[5] - boat[2] + boat[6] - boat[3]) != (boat[0] - 49)) return 84;
    return 0;
}
