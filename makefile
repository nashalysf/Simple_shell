all: main.c simple_shell.h
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
	./hsh
