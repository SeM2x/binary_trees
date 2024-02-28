.PHONY = all clean fclean

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
RM = del

SRC := $(wildcard [0-9]*-*.c)

all: 
	@echo building...
	@$(CC) $(CFLAGS) $(SRC) main.c binary_tree_print.c -o exe
	@echo done.
clean:
	$(RM) *.exe

fclean: clean
	$(RM) *main.c
