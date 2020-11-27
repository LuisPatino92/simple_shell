#  OUR OWN BASIC SHELL
This project is about how build our own simple shell program

## Steps if you want try this program

1. git clone https://github.com/LuisPatino92/simple_shell.git
2. cd simple_shell
3. For compile the shell 
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
4. Execute
 ./hsh


## **FILES**
<table>
<thead>
<tr>
  <th>#</th>
  <th>Directory</th>
  <th>Description</th>
</tr>
</thead>
<tbody>
<tr>
  <td>1</td>
  <td> README.md</td>
  <td>...<td>
</tr>
<tr>
  <td>2</td>
  <td>entry_point.c</td>
  <td>Begining entry point to simple shell (main)</td>	
</tr>
<tr>
  <td>3</td>
  <td>interactive.c</td>
  <td>Functions that interpret the interactive mode and display the new prompt  </td>
</tr>
<tr>
  <td>4</td>
  <td>non_interactive_mode</td>
  <td>Functions that interpret the non interactive mode and display the new prompt</td>
</tr>
<tr>
  <td>5</td>
  <td>leak_control.c</td>
  <td>Special functions for not having many memory leaks</td>
</tr>
<tr>
  <td>6</td>
  <td>interpreter.c</td>
  <td>contain funtions to help iterpreter the input command in a simple shell</td>
</tr>
<tr>
  <td>7</td>
  <td>_getline.c</td>
  <td>Reads the command from STDIN and tokenizes it</td>
</tr>
<tr>
  <td>8</td>
  <td>execute.c</td>
  <td>executes a process</td>
</tr>
<tr>
  <td>9</td>
  <td>aux_strings.c</td>
  <td>auxiliar functions for simple_shell</td>
</tr>
<tr>
  <td>10</td>
  <td>aux_strings1.c</td>
  <td>auxiliar functions for simple_shell</td>
</tr>
<tr>
  <td>11</td>
  <td>shell.h</td>
  <td>Header file with prototypes of the functions</td>
</tr>
<tr>
  <td>12</td>
  <td>man_1_simple_shell</td>
  <td>Manual of simple shell</td>
</tr>
<tr>
  <td>13</td>
  <td>AUTHORS</td>
  <td>File that lis</td>
</tr>
t all individuals having contributef content to the repository
</tbody>
</table>

## Description of the programm

The program simple_shell that takes command from the input

> The prompt looks like this:
>>`[#FAKE SHELL] /.../simple_shell $`

This simple shell can works in:

  - Display a prompt and wait for the user to type a command. A command line always ends with a new line.
  - Handle command lines with arguments
  - Handle the PATH
  - The prompt is displayed again each time a command has been executed.
  -  The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
  - The command lines are made only of one word. - If an executable cannot be found, print an error message and display the prompt again.
  - Handle errors.
  - have to handle the “end of file” condition (Ctrl+D)
  - Implement the exit built-in, that exits the shell
  - Implement the env built-in, that prints the current environment
  - Have own function _getline
  - Handle Ctrl+C
  - Not have memory leaks


## FUNCTIONS IN SIMPLE SHELL 

<table>
<thead>
<tr>
  <th>| Prototype |</th>
  <th>| Description   |</th>
</tr>
</thead>
<tbody>
<tr>
  <td>int main(void) </td>
  <td> Entry point to simple command line interpeter</td>
</tr>
<tr>
  <td>char **_getline(void) </td>
  <td>_getline - Reads the command from STDIN and tokenizes it</td>
</tr>
<tr>
  <td>void interactive_mode(void) </td>
  <td>Interactive commandline interpeter</td>
</tr>
<tr>
  <td>void show_prompt(void) </td>
  <td>Shows a prompt on the stdout</td>
</tr>
<tr>
  <td>void non_interactive_mode(void) </td>
  <td>executes one comman passed as pipeline to STDIN</td>
</tr>
<tr>
  <td>void execute(char *command, char **args) </td>
  <td>executes a process</td>
</tr>
<tr>
  <td>void interpeter(char **command, int loop) </td>
  <td>Interprets a command</td>
</tr>
<tr>
  <td>char *get_valid_exe(char *command) </td>
  <td> finds for a valid command to execute</td>
</tr>
<tr>
  <td>int include_path(char *command) </td>
  <td>Checks if command is a path</td>
</tr>
<tr>
  <td>char **path_tokenizer(void)</td>
  <td> Tokenizes the path</td>
</tr>
<tr>
  <td>char *connect(char *msj1, char *msj2)</td>
  <td>Conect two strings</td>
</tr>
<tr>
  <td>int _strlen(char *str)</td>
  <td>Measure the length of a strings</td>
</tr>
<tr>
  <td>int _strncmp(const char *s1, const char *s2, int n) </td>
  <td>Compare n bytes of  two strings</td>
</tr>
<tr>
  <td>char **_strtok(char *str, char delimiter) </td>
  <td>Is a double pointer that  Splits a string in separated words</td>
</tr>
<tr>
  <td>char *write_word(char *str, char delimiter) </td>
  <td>Write a word on the desired direction</td>
</tr>
<tr>
  <td>
int length_d(char *str, char delimiter) </td>
  <td>Computes the length of a strings until a delimiter</td>
</tr>
</tbody>
</table>

## List of system calls
* execve (man 2 execve)
* exit (man 3 exit)
* fork (man 2 fork)
* free (man 3 free)
* isatty (man 3 isatty)
* malloc (man 3 malloc)
* read (man 2 read)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* wait (man 2 wait)
* write (man 2 write)


## FLOWCHAR

![Alt](https://i.imgur.com/MDG6aqr.jpg "Flowchar")


## Examples
 -->
 	

`$ ls`

```
AUTHORS     aux_strings.c   execute.c      leak_control.c      testing
README.md   aux_strings1.c  hsh            man_1_simple_shell
_getline.c  built_ins.c     interactive.c  non_interactive.c
a.out       entry_point.c   interpeter.c   shell.h
```

`$ ls -l`

```
total 84
-rw-r--r-- 1 luna luna   190 Nov 25 18:55 AUTHORS -rw-r--r-- 1 luna luna  4468 Nov 25 23:20 README.md
-rw-r--r-- 1 luna luna   890 Nov 25 23:23 _getline.c
-rwxr-xr-x 1 luna luna 18496 Nov 25 17:58 a.out
-rw-r--r-- 1 luna luna  2583 Nov 25 19:09 aux_strings.c
-rw-r--r-- 1 luna luna  1839 Nov 25 19:36 aux_strings1.c
-rw-r--r-- 1 luna luna   564 Nov 26 11:27 built_ins.c
-rw-r--r-- 1 luna luna   230 Nov 25 15:12 entry_point.c
-rw-r--r-- 1 luna luna   339 Nov 25 19:42 execute.c
-rwxr-xr-x 1 luna luna 18496 Nov 25 19:10 hsh
-rw-r--r-- 1 luna luna  1406 Nov 25 16:56 interactive.c
-rw-r--r-- 1 luna luna  2674 Nov 25 10:55 interpeter.c
-rw-r--r-- 1 luna luna  1910 Nov 25 19:46 leak_control.c
-rw-r--r-- 1 luna luna   582 Nov 25 16:57 man_1_simple_shell
-rw-r--r-- 1 luna luna   382 Nov 26 11:27 non_interactive.c
-rw-r--r-- 1 luna luna  1327 Nov 25 19:09 shell.h
drwxr-xr-x 1 luna luna  4096 Nov 25 10:55 testing
```

`$ /bin/ls `
```
AUTHORS    _getline.c  aux_strings.c   built_ins.c    execute.c  interactive.c  leak_control.c      non_interactive.c  testing
README.md  a.out       aux_strings1.c  entry_point.c  hsh        interpeter.c   man_1_simple_shell  shell.h
```

`$ /bin/ls /bin/ls /bin/ls`
```
/bin/ls /bin/ls
```

`$ echo simple example`
```
simple example
```
`$ inexistent_command`
```
./hsh: 1:  inexistent_command: not found
```

## _**MADE BY**_
  * _LUIS ALEJANDRO PATIÑO ARBOLEDA_
  * _GIRALUNA GOMEZ LONDOÑO_



