/*
** EPITECH PROJECT, 2019
** my_prompt.c
** File description:
** my_prompt.
*/

#include "my_shell2.h"

void my_prompt_basic(shell_t *po)
{
    char cwd[100];

    if (getcwd(cwd, sizeof(cwd)) != NULL && po->j != 1) {
        write(1, cwd + 6, my_strlen(cwd) - 6);
        my_putstr(" > ");
        po->j = 0;
    }
}

void my_prompt_error(shell_t *po)
{
    char cwd[100];

    if (getcwd(cwd, sizeof(cwd)) != NULL && po->j == 1) {
        write(1, cwd + 6, my_strlen(cwd) - 6);
        my_putstr(" > ");
        po->j = 0;
    }
}
