#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

/*interactive.c*/
void interactive_mode(void);
void show_prompt(void);

/*_getline.c*/
char **_getline(void);
char **_getline_NIM(void);

/*non_interactive.c*/
void non_interactive_mode(void);

/*interpeter.c*/
void interpeter(char **command, int loop);
char *get_valid_exe(char *command);
int include_path(char *command);
char **path_tokenizer(void);
char *connect(char *msj1, char *msj2);

/*execute.c*/
void execute(char *command, char **args);

/*aux_strings.c*/
int _strlen(char *str);
int _strncmp(const char *s1, const char *s2, int n);
char **_strtok(char *str, char delimiter);
char *write_word(char *str, char delimiter);
int length_d(char *str, char delimiter);

/*aux_strings1.c*/
char *int_to_string(int number);
long absolute(long n);
int pot(int x, int y);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/*leak_control.c*/
void free_dp(char **to_free);
void signal_handler(int signal);
void show_error(char **command, int loop);
void error_msg(char **command, int loop);
char *get_exe_name(void);

/*built_ins.c*/
int built_ins(char **command, int loop);

#endif /*SHELL_H*/
