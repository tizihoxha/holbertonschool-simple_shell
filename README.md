# Simple shell in **C** 



![simple shell](https://user-images.githubusercontent.com/105599575/182689314-9e0f417d-d314-4005-9497-9eef7746bf0a.png)

##### Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

###### General

- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

### Description :bookmark:

This **Simple Shell** is a recreation of **Shell** that takes user input (commands with arguments) and outputs accordingly.

##### Basic loop of a shell: :bookmark:

- Read command from standard input.
- Inspects commandline string into an executable program and its arguments.
- Runs examined commands.

##### Features :bookmark:

- displays a prompt and waits for user to type a command
- can handle commands with options and arguments
- prompt displays again each time command is executed
- uses PATH variable to find executable command
- if executable is not found, prints an error message and displays prompt again
- includes an exit function that exits the shell
- includes an env built-in that prints the current environment

#### File Contents
This repository contains the following files:

   **File**   |   **Description**   
-------------- | --------------------- 
[shell.h](https://github.com/tizihoxha/holbertonschool-simple_shell/blob/main/shell.h) | File that contains all function prototypes
[shell.c](https://github.com/tizihoxha/holbertonschool-simple_shell/blob/main/shell.c) | Contains functions for the implementation of Simple Shell, entry point, function that reads the command & functon that executes the commands
[command_path.c](https://github.com/tizihoxha/holbertonschool-simple_shell/blob/main/command_path.c) | Functions that find the full PATH of the commands
[env_utils.c](https://github.com/tizihoxha/holbertonschool-simple_shell/blob/main/env_utils.c) | Contains functions _printenv & _getenv, functions that find and print the environment
[string_functions.c](https://github.com/tizihoxha/holbertonschool-simple_shell/blob/main/string_functions.c) | Contains created string functions like _strdup, _strlen, _strcat, _strcmp, _strcpy

#### Usage

- Enter custom shell by typing "./hsh". after compilation it will be prompted with a ($).
- Type a command of your liking ex. ls or env and press "Enter".
- Appropriate output will appear.
- Prompt reappears and awaits your next command.
- Exit shell by typing "exit"


## Compilation
Enter the following command to compile:

```
` $ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh `
```

## Example

Interactive Mode

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit

```

Non-interactive Mode

```
$ echo "/bin/ls -l" | ./hsh
hsh main.c shell.c test_ls
$
$ cat test_ls
/bin/ls -l
/bin/ls -l

$ cat test_ls | ./hsh
hsh main.c shell.c test_ls
hsh main.c shell.c test_ls
$
```

#### Authors

:octocat: Tiziana Hoxha - https://github.com/tizihoxha

:octocat: FatjonMileti - https://github.com/FatjonMileti
