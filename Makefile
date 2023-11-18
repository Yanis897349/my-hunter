##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Build my_ls
##

SRC = ./src/Core/options.c \
	./src/Core/files.c \
	./src/Core/directory.c \
	./src/Helpers/args.c \
	./src/Helpers/sort.c \
	./src/Helpers/path.c \
	./src/Helpers/memory.c \
	./src/Display/display.c \
	./src/Display/display_error.c \
	./src/Display/normal_listing.c \
	./src/Display/long_listing.c \
	./src/Display/symbolic.c
SRC_TEST = ./tests/test_my_ls.c \
	./tests/test_options.c \
	./tests/test_args.c \
	./tests/test_files.c \
	./tests/test_display.c \
	./tests/test_sort.c
MAIN_SRC = ./src/my_ls.c

VALGRINDFLAGS = -s --leak-check=full --error-exitcode=1
VALGRINDEXECFLAGS =

CFLAGS = -Wall -Wextra -Werror -I. -I./src/ -L . -lmy
LIB_PATH = ./lib/my

NAME_TEST = unit_tests
NAME := my_ls

CC = gcc
RM = rm -f

.PHONY: all build_lib clean_lib fclean_lib clean fclean re tests_run valgrind

all: $(NAME)

build_lib:
	make -C $(LIB_PATH)

clean_lib:
	make clean -C $(LIB_PATH)

fclean_lib:
	make fclean -C $(LIB_PATH)

$(NAME): build_lib
	$(CC) $(MAIN_SRC) $(SRC) $(CFLAGS) -o $(NAME)

clean: clean_lib
	$(RM) $(NAME)

fclean: clean fclean_lib tests_clean

re: fclean all

tests_run: build_lib
	$(CC) $(SRC) $(SRC_TEST) $(CFLAGS) -o $(NAME_TEST) --coverage -lcriterion
	./$(NAME_TEST)

valgrind: all
	valgrind $(VALGRINDFLAGS) ./$(NAME) $(VALGRINDEXECFLAGS)

tests_clean:
	$(RM) $(NAME_TEST)
	$(RM) *.gcno
	$(RM) *.gcda
