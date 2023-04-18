all: main.c simple_shell.h
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c -o shell
