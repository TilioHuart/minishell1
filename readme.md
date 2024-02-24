# Minishell1

## Introduction
Minishell1 is a basic UNIX command interpreter project, a precursor to the 42sh project. It aims to implement a simplified shell that can execute basic command lines, manage the PATH and the environment, and handle errors appropriately.

## Features
- Displays a prompt and waits for the user to input a command line.
- Executes basic command lines without pipes, redirections, or advanced features.
- Handles commands found in the PATH or provided with direct paths.
- Implements builtins: `cd`, `setenv`, `unsetenv`, `env`, `exit`.
- Manages errors and returns appropriate exit statuses.

## Compilation
The project is compiled with a Makefile that includes `re`, `clean`, and `fclean` rules. Use the following command to compile:

make

## Usage
To start the shell, run the compiled binary:

./mysh

Then, input your command at the prompt (`$>`).
