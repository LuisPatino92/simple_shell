#  OUR OWN BASIC SHELL

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
  <td>README.md</td>
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

