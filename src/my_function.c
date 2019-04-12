/*
** EPITECH PROJECT, 2019
** my_function.c
** File description:
** my_function.
*/

#include "my_shell2.h"

int is_binaries(shell_t *po, char **env)
{
    char *binary = my_calloc(sizeof(char) * 100);
    char **arr_flag = {NULL};
    binary = my_strcut(po->buffer, binary);
    arr_flag = my_str_to_wordarry(po->buffer, arr_flag);
    for (int i = 0; po->buffer[i] != '\0'; i++)
        if ((binary[0] = '.') && (binary[1] = '/')) {
            binary = my_strcut(po->buffer, binary);
            if (!access(binary, X_OK)) {
                if ((po->pid = fork()) == -1)
                    return (1);
                if (!(po->pid)) {
                    execve(binary, arr_flag, env);
                } else {
                    po->check = 3;
                    waitpid(po->pid, &(po->status), 0);
                    check_shell_sts(po);
                }
                return (1);
            }
        }
}

void is_exit(shell_t *po)
{
    char *value = NULL;
    int index = 0;
    char *binary = my_calloc(100);
    binary = my_strcut(po->buffer, binary);

    if (!my_strcmp("exit", binary)) {
        if (my_strlen(po->buffer) > 5) {
            value = get_args(po->buffer);
            check_exit(index, value, po);
        }
        if (po->check != 1)
        exit(po->retrn);
        my_putstr("exit: Expression Syntax.\n");
    }
}

void my_echo(shell_t *po, char **env)
{
    if (!my_strcmp("echo $?", po->buffer)) {
        my_put_nbr(po->retrn);
        my_putchar('\n');
        po->check = 1;
        po->retrn = 0;
    }
}

void my_function(shell_t *po, char **env)
{
    is_exit(po);
    my_echo(po, env);
    my_cd(po, env);
}
