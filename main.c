/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_shell2.h"

int my_setup_function(shell_t *po, char *binary, char **env, char *path)
{
    char **arr_flag = {NULL};
    char **path_arry = {NULL};

    arr_flag = my_str_to_wordarry(po->buffer, arr_flag);
    path_arry = my_str_to_wordarry(path, path_arry);
    for (int v = 0; path_arry[v] != NULL; v++) {
        if (!access(my_strcat(path_arry[v], binary), X_OK)) {
            po->check = 3;
            if ((po->pid = fork()) == -1)
                return (1);
            if (!(po->pid)) {
                execve(my_strcat(path_arry[v], binary),
                arr_flag, env);
            } else {
                waitpid(po->pid, &(po->status), 0);
                check_shell_sts(po);
            }
            return (1);
        }
    }
}

int my_call_function(shell_t *po, char *binary, char **env, char *path)
{
    if (my_strlen(po->buffer) == 0)
        return (1);
    my_setup_function(po, binary, env, path);
    is_binaries(po, env);
    if (po->check != 3)
        check_error_cmd(po);
    po->check = 0;
}

int start(char *binary, char *path, shell_t *po, char **env)
{
    while (1) {
        binary = my_calloc(100);
        if (po->j != 1)
            my_prompt_basic(po);
        else
        my_prompt_error(po);
        if (po->chara = getline(&(po->buffer), &(po->bufsize), stdin) == -1) {
            my_putchar('\n');
            exit(po->retrn % 256);
        }
        po->buffer[my_strlen(po->buffer) - 1] = '\0';
        str_clean(po);
        binary = my_strcut(po->buffer, binary);
        my_function(po, env);
        if (po->check == 0)
            my_call_function(po, binary, env, path);
        else
            po->check = 0;
    }
}

int main(int ac, char **av, char **env)
{
    char *binary = my_calloc(sizeof(char) * 500);
    char *path = my_getenv(path, env);
    shell_t *po = NULL;

    if (check_error(ac, av) == 84)
        return (84);
    po = my_struct(po);
    start(binary, path, po, env);
    return (0);
}
