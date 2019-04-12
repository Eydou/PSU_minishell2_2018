/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error.c
*/

#include "my_shell2.h"

int check_cd(shell_t *po, char *dir)
{
    struct stat stat;
    int b = 0;

    for (int j = 0; dir[j] != '\0'; j++)
        dir[j] == ' ' ? b++ : 0;
    if (b > 0) {
        write(2, "cd: Too many arguments.\n", 24);
        return (84);
    }   
    if (access(dir, F_OK) < 0) {
        write(2, dir, my_strlen(dir));
        write(2, ": No such file or directory.\n", 29);
        return (84);
    }
    if (!S_ISDIR(lstat(dir, &stat))) {
        write(2, dir, my_strlen(dir));
        write(2, ": Not a directory.\n", 19);
        return (84);
    }
    return (0);
}

void check_shell_sts(shell_t *po)
{
    if (!WIFEXITED(po->status)) {
        po->retrn = WTERMSIG(po->status) + 128;
        if (WTERMSIG(po->status) != 8)
            my_putstr(strsignal(WTERMSIG(po->status)));
        if (WTERMSIG(po->status) == 8)
            my_putstr("Floating exception");
        if (WCOREDUMP(po->status) == 128)
            my_putstr(" (core dumped)");
        my_putchar('\n');
    } else
        po->retrn = WEXITSTATUS(po->status);
}

void check_exit(int index, char *value, shell_t *po)
{
    for (int i = 0; value[i] != '\0'; i++) {
        if ((value[i] < 48 || value[i] > 57) && (value[i] != '-')) {
            po->check = 1;
            po->retrn = 1;
        } else {
            index = my_atoi(value);
            po->retrn = index;
            po->retrn = (256 -((po->retrn * -1) - 256));
        }
    }
}

int check_error(int ac, char **av)
{
    if (ac != 1)
    return (84);
}

void check_error_cmd(shell_t *po)
{
    if (po->check != 2) {
        write(2, po->buffer, my_strlen(po->buffer));
        write(2, ": Command not found.\n", 21);
        po->retrn = 1;
        po->check = 0;
    }
}
