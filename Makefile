##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Build my_ls
##

NAME = project
NAME_TEST = unit_tests

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB_PATH := ./lib/my

SRC =
SRC_TEST =
MAIN_SRC = ./src/main.c

.PHONY: all tests_run coverage valgrind clean tests_clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(MAIN_SRC) $(SRC) $(CFLAGS) -o $(NAME)

tests_run:
	$(CC) $(SRC) $(SRC_TEST) $(CFLAGS) -o $(NAME_TEST) --coverage -lcriterion
	./$(NAME_TEST)

coverage: tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

valgrind: all
	valgrind -s --leak-check=full --error-exitcode=1 ./$(NAME)

clean:
	$(RM) $(NAME)

tests_clean:
	$(RM) $(NAME_TEST)
	$(RM) *.gcno
	$(RM) *.gcda

fclean: clean tests_clean

re: fclean all
