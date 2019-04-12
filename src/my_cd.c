/*
** EPITECH PROJECT, 2019
** my_cd.
** File description:
** my_cd.
*/

#include "my_shell2.h"

char *my_calloc(int size)
{
    char *res = malloc(size);

    if (res == NULL)
        return (NULL);
    for (int i = 0; i != size; i++)
        res[i] = '\0';
    return (res);
}

char *get_home(char *str)
{
    char *res = my_calloc(sizeof(char) * 100);
    int count = 0;

    for (; str[count] != '='; count++);
    count++;
    for (int i = 0; str[count] != '\0'; i++, count++)
        res[i] = str[count];
    return (res);
}

char *get_args(char *str)
{
    char *res = my_calloc(sizeof(char) * 100);
    int count = 0;

    for (; str[count] != ' '; count++);
    count++;
    for (int i = 0; str[count] != '\0'; i++, count++)
        res[i] = str[count];
    return res;
}

int my_cd(shell_t *po, char **env)
{
    char *dir = NULL;
    char *binary = my_calloc(100);

    binary = my_strcut(po->buffer, binary);
    if (!my_strcmp("cd", binary)) {
        if (my_strlen(po->buffer) == 2 || !my_strcmp("cd ~", po->buffer)) {
            chdir(get_home(my_getenv_cd(dir, env)));
        } else {
            dir = get_args(po->buffer);
            if (chdir(dir) == -1 && check_cd(po, dir) == 84) {
                po->retrn = 1;
                po->j = 1;
            }
        }
        po->check = 1;
    }
}
