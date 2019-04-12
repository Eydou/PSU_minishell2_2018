/*
** EPITECH PROJECT, 2019
** my_shell2_h
** File description:
** my_shell2_h
*/

#ifndef my_shell2_h
#define my_shell2_h

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

typedef struct shell
{
    int j;
    int retrn;
    int check;
    char *buffer;
    int status;
    size_t chara;
    size_t bufsize;
    pid_t pid;
} shell_t;

    /* src */

int check_cd(shell_t *po, char *dir);
int is_binaries(shell_t *po, char **env);
void str_clean(shell_t *po);
char *rm_tab(char *str);
char *rm_up_space(char * str);
char *rm_low_space(char *str);
char *rm_space(char *src);
char *my_getenv_oldpwd(char *dir, char **env);
void check_exit(int index, char *value, shell_t *po);
void check_shell_sts(shell_t *po);
void check_error_cmd(shell_t *po);
void my_function(shell_t *po, char **env);
void my_prompt_basic(shell_t *po);
void my_prompt_error(shell_t *po) ;
char *my_calloc(int size);
char *get_args(char *str);
char *my_getenv_pwd(char *path, char **env);
char **my_str_to_wordarry(char *str, char **path);
shell_t *my_struct(shell_t *po);
char *my_strcut(char *buffer, char *binary);
int my_cd(shell_t *po, char **env);
int check_error(int ac, char **av);
char *my_getenv(char *dir, char **env);
char *my_getenv_cd(char *path, char **env);

    /* lib */

int my_atoi(char const *str);
int my_put_nbr(int nb);
char *my_strcat(char *str1, char *str2);
int my_strcmp(char *str, char *cmp);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);

#endif /*  my_shell2.h */
