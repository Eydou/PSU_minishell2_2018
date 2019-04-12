/*
** EPITECH PROJECT, 2019
** my_getenv.c
** File description:
** my_getenv.
*/

#include "my_shell2.h"

char *my_getenv_cd(char *dir, char **env)
{
    for (int j = 0; env[j] != NULL; j++) {
        if (env[j][0] == 'H' && env[j][1] == 'O'
            && env[j][2] == 'M' && env[j][3] == 'E') {
            dir = my_calloc(sizeof(char) * 1000);
            for (int i = 0; i <= (my_strlen(env[j]) + 1); i++)
                dir[i] = env[j][i];
        }
    }
    return (dir);
}

char *my_getenv(char *path, char **env)
{
    for (int j = 0; env[j] != NULL; j++) {
        if (env[j][0] == 'P' && env[j][1] == 'A'
            && env[j][2] == 'T' && env[j][3] == 'H') {
            path = my_calloc(sizeof(char) * 1000);
            for (int i = 0; i <= my_strlen(env[j]); i++)
                path[i] = env[j][i];
        }
    }
    return (path);
}

char *my_getenv_oldpwd(char *dir, char **env)
{
    for (int j = 0; env[j] != NULL; j++) {
        if (env[j][0] == 'O' && env[j][1] == 'L'
            && env[j][2] == 'D' && env[j][3] == 'P') {
            dir = my_calloc(sizeof(char) * 1000);
            for (int i = 0; i <= (my_strlen(env[j]) + 1); i++)
                dir[i] = env[j][i];
        }
    }
    return (dir);
}

char *my_getenv_pwd(char *path, char **env)
{
    for (int j = 0; env[j] != NULL; j++) {
        if (env[j][0] == 'P' && env[j][1] == 'W'
            && env[j][2] == 'D') {
            path = my_calloc(sizeof(char) * 1000);
            for (int i = 0; i <= my_strlen(env[j]); i++)
                path[i] = env[j][i];
        }
    }
    return (path);
}
