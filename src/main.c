/*
** EPITECH PROJECT, 2020
** need for stek
** File description:
** need4stek
*/

#include "../include/my.h"

char **my_str_to_wordarray(char *str)
{
    char **tab = malloc(sizeof(char *) * 1000);

    for (int i = 0, y = 0; str[i] != '\0'; i++, y++) {
        tab[y] = malloc(sizeof(char) * 1000);
        while (str[i] == ':' && str[i++] != '\0');
        for (int x = 0; str[i] != ':' && str[i] != '\0'; x++, i++)
            tab[y][x] = str[i];
    }
    return (tab);
}

char **my_command(char *str)
{
    char **tab = NULL;
    char *src = NULL;
    size_t size = 0;

    if (write(1, str, strlen(str)) == -1)
        return (NULL);
    if (getline(&src, &size, stdin) == -1)
        return (NULL);
    tab = my_str_to_wordarray(src);
    return (tab);
}

int check_direction(float i)
{
    if (i < 0.0)
        return (1);
    else
        return (2);
}

int check_angle(void)
{
    float i;
    float angle[35] = {0};
    char **tab = my_command("GET_INFO_LIDAR\n");

    for (int x = 0; x <= 35; x++)
        angle[x] = atof(tab[x]);
    i = angle[4] - angle[34];
    if (angle[15] >= 1500) {
        if (check_direction(i) == 1)
            my_command("WHEELS_DIR:-0.005\n");
        else
            my_command("WHEELS_DIR:0.005\n");
    } else if (angle[15] >= 1000) {
        if (check_direction(i) == 1)
            my_command("WHEELS_DIR:-0.05\n");
        else
            my_command("WHEELS_DIR:0.05\n");
    } else if (angle[15] >= 600) {
        if (check_direction(i) == 1)
            my_command("WHEELS_DIR:-0.1\n");
        else
            my_command("WHEELS_DIR:0.1\n");
    } else if (angle[15] >= 400) {
        if (check_direction(i) == 1)
            my_command("WHEELS_DIR:-0.2\n");
        else
            my_command("WHEELS_DIR:0.2\n");
    } else if (angle[15] >= 200) {
        if (check_direction(i) == 1)
            my_command("WHEELS_DIR:-0.3\n");
        else
            my_command("WHEELS_DIR:0.3\n");
    } else {
        if (check_direction(i) == 1)
            my_command("WHEELS_DIR:-0.5\n");
        else
            my_command("WHEELS_DIR:0.5\n");
    }
}

int main(void)
{
    char **tab = NULL;

    if (my_command("START_SIMULATION\n") == NULL)
        return (84);
    while (1) {
        tab = my_command("CAR_FORWARD:0.5\n");
        for (int x = 0; tab[x] != NULL; x++)
            dprintf(STDERR_FILENO, "%s", tab[x]);
        if (tab == NULL)
            return (84);
        if (check_angle() == 1)
            return (1);
    }
    return (0);
}
