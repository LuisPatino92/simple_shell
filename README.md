#  OUR OWN BASIC SHELL

This project is about how build our own simple shell program

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
>>[#FAKE SHELL] /.../simple_shell $

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


FUNCTIONS IN A SIMPLE SHELL 
<table>
<thead>
<tr>
  <th>| prototype |</th>
  <th>| Description   |</th>
</tr>
</thead>
<tbody>
<tr>
  <td>  |</td>
  <td>Content Cell</td>
</tr>
<tr>
  <td>int main(void) |</td>
  <td> Entry point to simple command line interpeter</td>
</tr>
<tr>
  <td>char **_getline(void) |</td>
  <td>_getline - Reads the command from STDIN and tokenizes it</td>
</tr>
<tr>
  <td>void interactive_mode(void) |</td>
  <td>Interactive commandline interpeter</td>
</tr>
<tr>
  <td>void show_prompt(void) |</td>
  <td>Shows a prompt on the stdout</td>
</tr>
<tr>
  <td>void non_interactive_mode(void) |</td>
  <td>executes one comman passed as pipeline to STDIN</td>
</tr>
<tr>
  <td>void execute(char *command, char **args) |</td>
  <td>executes a process</td>
</tr>
<tr>
  <td>void interpeter(char **command, int loop) |</td>
  <td>Interprets a command</td>
</tr>
<tr>
  <td>char *get_valid_exe(char *command) |</td>
  <td> finds for a valid command to execute</td>
</tr>
<tr>
  <td>int include_path(char *command) |</td>
  <td>Checks if command is a path</td>
</tr>
<tr>
  <td>char **path_tokenizer(void) | </td>
  <td> Tokenizes the path</td>
</tr>
<tr>
  <td>char *connect(char *msj1, char *msj2) |</td>
  <td>Conect two strings</td>
</tr>
<tr>
  <td>int _strlen(char *str) |</td>
  <td>Measure the length of a strings</td>
</tr>
<tr>
  <td>int _strncmp(const char *s1, const char *s2, int n) |</td>
  <td>Compare n bytes of  two strings</td>
</tr>
<tr>
  <td>char **_strtok(char *str, char delimiter) |</td>
  <td> Splits a string in separated words</td>
</tr>
<tr>
  <td>char *write_word(char *str, char delimiter) |</td>
  <td>Write a word in the desired direction</td>
</tr>
<tr>
  <td>
int length_d(char *str, char delimiter) |</td>
  <td>Computes the length of a string until a delimiter</td>
</tr>

</tbody>
</table>



## Examples

