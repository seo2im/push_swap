NAME = TEST
SRC = ./main.c \
		./srcs/push_swap/push_swap_main.c \
		./srcs/push_swap/simple.c \
		./srcs/checker/checker_main.c \
		./srcs/checker/checker.c \
		./srcs/checker/get_exec.c \
		./srcs/checker/argv_check.c \
		./srcs/checker/run.c \
		./srcs/public/stack_main.c \
		./srcs/public/stack/stack.c \
		./srcs/public/exec/exec.c \
		./lib/*.c
HEADER = -I ./includes/
CC = gcc

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $(NAME) $(SRC) $(HEADER)


fclean : 
	rm -rf $(NAME)