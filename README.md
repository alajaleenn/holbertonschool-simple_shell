
# Simple Shell

A lightweight UNIX command interpreter written in C that mimics the essential behavior of the `/bin/sh` shell.

---

## Overview

This project is a basic implementation of a UNIX command-line shell.  
It can run commands both **interactively** (prompt mode) and **non-interactively** (script or pipe mode).  
The shell handles command parsing, execution, built-in functions, and exit codes — all without using forbidden functions such as `getenv`.

---

## Features

- Displays a custom shell prompt (`$`) and waits for user commands  
- Executes commands using **absolute paths** (`/bin/ls`) or **PATH** (`ls`)  
- Handles arguments and multiple words (`ls -l /tmp`)  
- Searches the PATH manually (no use of `getenv`)  
- Supports built-in commands: `exit` and `env`  
- Handles End-Of-File (Ctrl+D) correctly  
- Returns proper **exit status codes** (0, 1, 2, 127)  
- Clean memory management (no leaks under Valgrind)  
- Follows Holberton School C style (Betty compliant)  

---

## Compilation

To compile all source files and create the executable `hsh`:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


⸻

Usage

Interactive Mode

$ ./hsh
$ ls
main.c  shell.c  builtin.c  hsh
$ /bin/pwd
/home/user/simple_shell
$ exit
$

Non-Interactive Mode

$ echo "ls -l" | ./hsh
-rw-r--r-- 1 user user 1024 Nov 10 10:00 main.c
$ cat commands.txt | ./hsh


⸻

Project Structure

File	Description	Key Functions
main.h	Header file with includes and prototypes	—
main.c	Entry point, runs the main shell loop	main()
shell.c	Core shell logic: prompt, read, parse, free	display_prompt(), read_line(), parse_line()
find_path.c	PATH search without getenv	get_path_env(), find_path()
run_command.c	Executes commands via execve	fork_and_execute(), execute_command()
builtin.c	Built-in command handlers	handle_exit(), handle_env(), is_builtin()
AUTHORS	Contributor names	—
README.md	Project documentation	—


⸻

Main Functions

main.c
	•	main() – Initializes and controls the shell loop, manages exit codes.

shell.c
	•	display_prompt() – Prints the shell prompt ($).
	•	read_line() – Reads user input using getline().
	•	parse_line() – Tokenizes input into an argument array.
	•	free_array() – Frees dynamically allocated argument arrays.

find_path.c
	•	get_path_env() – Retrieves the PATH manually from environ.
	•	find_path() – Searches for the command within PATH directories.

run_command.c
	•	fork_and_execute() – Creates child processes and runs commands.
	•	execute_command() – Handles execution logic and error handling.

builtin.c
	•	handle_exit() – Exits the shell properly, freeing all resources.
	•	handle_env() – Prints all environment variables.
	•	is_builtin() – Checks for built-in commands.

⸻
 Built-in Commands

Command	Description	Example
exit	Exits the shell	exit
env	Prints environment variables	env


⸻

 Exit Status Codes

Code	Meaning	Example
0	Success	Valid command executed
1	General error	Fork failure
2	Misuse of command	ls /nonexistent
127	Command not found	invalidcmd


⸻

Examples

Example 1 — Basic Commands

$ ./hsh
$ ls
main.c  shell.c  builtin.c  hsh
$ exit
$

Example 2 — Command Not Found

$ ./hsh
$ notfound
./hsh: 1: notfound: not found
$ exit
$ echo $?
127

Example 3 — Non-Interactive Mode

$ echo "ls -l" | ./hsh
total 8
-rw-r--r-- 1 user user 2048 Nov 10 09:30 main.c


⸻

Memory & Process Management
	•	Dynamic memory is freed before each iteration.
	•	No leaks (valgrind clean).
	•	Uses:
	•	fork() to create processes
	•	execve() to run commands
	•	waitpid() to capture exit status
	•	Macros WIFEXITED and WEXITSTATUS used for process control.

⸻

PATH Handling
	•	Does not use getenv().
	•	Custom implementation uses the global environ variable directly.
	•	Properly handles empty or missing PATH values.

⸻

Allowed Functions

access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free,
getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror,
read, readdir, signal, stat, lstat, fstat, strtok, wait, waitpid,
wait3, wait4, write, strdup, strlen, strcmp, strncmp, sprintf


⸻

Testing

Manual Testing

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh
echo "ls" | ./hsh

Memory Leak Test

valgrind --leak-check=full ./hsh

Expected result:

All heap blocks were freed -- no leaks are possible

Style Check

betty *.c *.h


⸻

 Authors
	•	Noura Alqahtani — @bynoura
	•	Najla Alajaleen — @alajaleenn

⸻

Requirements
	•	OS: Ubuntu 20.04 LTS
	•	Compiler: gcc 9.4.0 or later
	•	Standard: -std=gnu89
	•	Style: Betty compliant

⸻

Project Information
	•	Project: 0x16. C - Simple Shell
	•	Language: C
	•	School: Holberton School
	•	Purpose: Educational project for learning system programming and process management.

⸻

License

This project is part of the Holberton School curriculum.
It was created for educational purposes and is not intended for production use.

