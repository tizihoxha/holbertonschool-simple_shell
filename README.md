# Simple shell in **C** 



![simple shell](https://user-images.githubusercontent.com/105599575/182689314-9e0f417d-d314-4005-9497-9eef7746bf0a.png)



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
$
```

Non-interactive Mode

```
$ echo "/bin/ls -l" | ./hsh
hsh main.c shell.c test_ls
$
$ cat test_ls
/bin/ls -l
/bin/ls -l
$
$ cat test_ls | ./hsh
hsh main.c shell.c test_ls
hsh main.c shell.c test_ls
$
```

#### Authors

:octocat: Tiziana Hoxha - https://github.com/tizihoxha

:octocat: FatjonMileti - https://github.com/FatjonMileti
